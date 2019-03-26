#pragma once
#include "File.h"
#include <string>

class TextFile : public IFile {
public:
    TextFile() {};
    TextFile(std::string text) {
        setText(text);
    }

    void setText(std::string content) {
        std::vector<byte> raw_content(content.size());
        for (auto &i : content) {
            raw_content.push_back(i);
        }

        setContent(raw_content);
    }

    std::string getText() {
        std::string text_content;
        for (auto &i : raw_content) {
            text_content.push_back(i);
        }
        return text_content;
    }

private:
    void setContent(std::vector<byte> content) {
        raw_content = content;
    }

    std::vector<char> getContent() {
        return raw_content;
    }

    std::vector<byte> raw_content;
};