#pragma once
#include "IParser.h"
#include <sstream>

#include <string>
#include <vector>
#include <map>

#include <memory>
#include <algorithm>
#include <iterator>

class MultipartParser : public IParser {
public:
    using part = std::vector<std::string>;

    MultipartParser() = default;

    /* 
     * Парсер, скорее всего, будет содержать в себе огромное количество
     * информации, так что копировать его будет невыгодно;
     * поэтому разрешено только его перемещение
     */
    MultipartParser(const MultipartParser&) = delete;
    MultipartParser &operator=(const MultipartParser&) = delete;

    MultipartParser(MultipartParser&&);
    MultipartParser &operator=(MultipartParser&&);

    virtual void parse(std::string);
    bool doneParsing();

    std::string getBoundary() const;

    const std::string operator[](const std::string&) noexcept;

    inline friend void swap(MultipartParser&, MultipartParser&);
private:
    std::string boundary;
    std::map<std::string, std::string> content;

    std::string findBoundary(std::stringstream&);
    //divideIntoParts() полностью истощает строковой поток, поэтому &&
    std::vector<part> divideIntoParts(std::stringstream&&);
    void extractContent(std::vector<part>&&);
};