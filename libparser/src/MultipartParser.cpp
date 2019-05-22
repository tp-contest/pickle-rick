#include "MultipartParser.h"

using std::stringstream;
using std::vector;
using std::string;
using std::getline;
using std::istream_iterator;
using std::copy;
using std::runtime_error;
using std::find;

inline void
swap(MultipartParser& lhs, MultipartParser& rhs)
{
    using std::swap;

    swap(lhs.boundary, rhs.boundary);
    swap(lhs.content, rhs.content);
}

MultipartParser::MultipartParser(MultipartParser&& other):
    boundary(std::move(other.boundary)),
    content(std::move(other.content))
{ }

MultipartParser&
MultipartParser::operator=(MultipartParser &&other)
{
    swap(*this, other);

    return *this;
}


void
MultipartParser::parse(string input)
{
    stringstream request(input);

    findBoundary(request);

    auto parts = divideIntoParts(std::move(request));

    extractContent(std::move(parts));
}

std::string
MultipartParser::findBoundary(std::stringstream& request)
{
    const string boundaryStr = "boundary=";
    string buffer;
    //ищем наш boundary
    size_t boundaryPos;
    while (getline(request, buffer) &&
            (boundaryPos = buffer.find(boundaryStr)) == string::npos);
    //если цикл закончился НЕ по причине того, что мы дошли до конца потока...
    if (request) {
        boundary = buffer.substr(
            boundaryPos + boundaryStr.size(),
            buffer.size() - (boundaryPos + boundaryStr.size() + 1)
            // +1 потому что в буфере в конце будет лежать \r
        );
    }

    // отматываем поток до тех пор, пока не найдём первый разделитель
    const string divider = "--" + boundary + '\r';
    while (getline(request, buffer) && buffer != divider);

    return boundary;
}

vector<MultipartParser::part>
MultipartParser::divideIntoParts(stringstream &&str)
{
    vector<part> parts;

    auto stream = std::move(str);
    const string divider = "--" + boundary + '\r';
    const string request_end = "--" + boundary + "--\r";

    string buffer;


    parts.push_back(part());

    while (getline(stream, buffer) && buffer != request_end) {
        //нашли следующую часть
        if (buffer == divider) {
            parts.push_back(part());
            continue;
        }

        parts.back().push_back("");
        //убираем \r из конца строки
        copy(begin(buffer), --end(buffer), back_inserter(parts.back().back()));
    }

    return parts;
}

void
MultipartParser::extractContent(vector<part>&& _parts)
{
    string name_keyword = "name=";
    auto parts = _parts;

    for (auto const &p: parts) {
        string part_name = "";
        auto part_iter = begin(p), part_end = end(p);
        //пока мы не нашли название части, итерируем по строкам части
        for (; part_name == "" && part_iter != part_end; part_iter++) {
            stringstream this_line(*part_iter);
            string buffer;
            while (this_line >> buffer) {
                //если токен начинается с name_keyword...
                if (buffer.find(name_keyword) == 0) {
                    size_t first_quote_pos = buffer.find('\"') + 1;
                    size_t second_quote_pos = buffer.find_last_of('\"');
                    part_name = buffer.substr(
                        first_quote_pos, second_quote_pos - first_quote_pos
                    );
                    break;
                }
            }
        }

        if (part_name == "")
            throw runtime_error("Couldn't find part's name");

        auto empty_line_pos = find(part_iter, part_end, "");

        string temp_str;
        for_each (
            empty_line_pos, part_end,
            [&](const string& arg) {temp_str += arg;}
        );
        content[part_name] = temp_str;
    }
}

bool
MultipartParser::doneParsing()
{
    return (content.size() != 0);
}

string
MultipartParser::getBoundary() const
{
    return boundary;
}

const std::string
MultipartParser::operator[](const string &key) noexcept
{
    auto res = content.find(key);
    return (res == end(content) ? "" : res->second);
}