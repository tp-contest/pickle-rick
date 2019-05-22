#pragma once

#include <vector>
#include <string>

class IParser {
    virtual void parse(std::string) = 0;
};