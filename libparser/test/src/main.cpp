#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include "MultipartParser.h"

const std::string input = (
        "POST http://www.site.ru/postnews.html HTTP/1.0\r\n"
        "Host: www.site.ru\r\n"
        "Referer: http://www.site.ru/news.html\r\n"
        "Cookie: income=1\r\n"
        "Content-Type: multipart/form-data; boundary=1BEF0A57BE110FD467A\r\n"
        "Content-Length: 491\r\n"
        "\r\n"
        "--1BEF0A57BE110FD467A\r\n"
        "Content-Disposition: form-data; name=\"news_header\"\r\n"
        "\r\n"
        "Пример новости\r\n"
        "--1BEF0A57BE110FD467A\r\n"
        "Content-Disposition: form-data; name=\"news_file\"; filename=\"news.txt\"\r\n"
        "Content-Type: application/octet-stream\r\n"
        "Content-Transfer-Encoding: binary\r\n"
        "\r\n"
        "А вот такая новость, которая лежит в файле news.txt\r\n"
        "--1BEF0A57BE110FD467A--\r\n"
);

TEST (MultipartParser, FindingABoundary) {
    using std::string;

    MultipartParser parser;

    parser.parse(input);

    ASSERT_EQ(parser.getBoundary(), "1BEF0A57BE110FD467A");
}

TEST (MultipartParser, Parsing) {
    using std::string;

    MultipartParser parser;

    parser.parse(input);

    ASSERT_EQ(parser["news_header"], "Пример новости");   
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}