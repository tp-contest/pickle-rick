#pragma once
#include "IParser.h"
#include <sstream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>

class MultipartParser : public IParser {
public:
    using part = std::vector<std::string>;

    MultipartParser(std::string = "name=", std::string = "boundary=");
    ~MultipartParser() = default;

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
    const std::string partNameToken;
    const std::string boundaryToken;

    std::string boundary;
    std::map<std::string, std::string> content;

    std::string findBoundary(std::stringstream&);
    //divideIntoParts() полностью истощает строковой поток, поэтому &&
    std::vector<part> divideIntoParts(std::stringstream&&);
    void extractContent(std::vector<part>&&);
};
