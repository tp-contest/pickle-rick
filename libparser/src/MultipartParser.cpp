#include "MultipartParser.h"

using std::stringstream;
using std::vector;
using std::string;
using std::getline;
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

inline std::string
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

inline vector<MultipartParser::part>
MultipartParser::divideIntoParts(stringstream &&str)
{
    vector<part> parts;

    auto stream = std::move(str);
    const string divider = "--" + boundary + '\r';
    const string requestEnd = "--" + boundary + "--\r";

    string buffer;


    parts.push_back(part());

    while (getline(stream, buffer) && buffer != requestEnd) {
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

inline void
MultipartParser::extractContent(vector<part>&& _parts)
{
    string nameKeyword = "name=";
    auto parts = _parts;

    for (auto const &p: parts) {
        string partName = "";
        auto partIter = begin(p), partEnd = end(p);
        //пока мы не нашли название части, итерируем по строкам части
        for (; partName == "" && partIter != partEnd; partIter++) {
            stringstream thisLine(*partIter);
            string buffer;
            while (thisLine >> buffer) {
                //если токен начинается с nameKeyword...
                if (buffer.find(nameKeyword) == 0) {
                    size_t firstQuotePos = buffer.find('\"') + 1;
                    size_t secondQuotePos = buffer.find_last_of('\"');
                    partName = buffer.substr(
                        firstQuotePos, secondQuotePos - firstQuotePos
                    );
                    break;
                }
            }
        }

        if (partName == "")
            throw runtime_error("Couldn't find part's name");

        auto emptyLinePos = find(partIter, partEnd, "");

        string tempStr;
        for_each (
            emptyLinePos, partEnd,
            [&](const string& arg) {tempStr += arg;}
        );
        content[partName] = tempStr;
    }
}

inline bool
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
