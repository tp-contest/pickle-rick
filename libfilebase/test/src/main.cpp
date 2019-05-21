#include <iostream>
#include <gtest/gtest.h>
#include "Folder.h"
#include "MemoryFile.h"
#include "FileSystem.h"
#include "Downloader.h"
#include "ContestStorage.h"

TEST (DummyFile, Setting) {
    MemoryFile file1("bass");
    file1.setContent("Hello world!");
    ASSERT_EQ("Hello world!", file1.getContent());
}


TEST (Folder, AddingObjects) {
    Folder folder1("folder1");
    for (auto const& name: {"hello.txt", "text.txt", "main.cpp", "what.h"}) {
        folder1.addFileObject(new MemoryFile(name));
    }

    dynamic_cast<MemoryFile*>(folder1.getFileObject("text.txt"))->setContent("Hello world!");
    ASSERT_EQ(
        "Hello world!",
        dynamic_cast<MemoryFile*>(folder1.getFileObject("text.txt"))->getContent()
    );
}

TEST (ContestStorage, FindingFiles) {
    auto *fs = new FileSystem();
    ContestStorage a1(fs, new Downloader(*fs));

    ContestFileInfo file1;
    file1.fileName = "test.cpp";
    file1.contestID = 1;
    file1.contestantID = 12;

    ContestFileInfo file2;
    file2.fileName = "hello.exe";
    file2.contestID = 1;
    file1.contestantID = 12;

    a1.saveFile(file1, "Hello world!");
    a1.saveFile(file2, "dadadadawdada");
    ASSERT_EQ(a1.findFile(file1)->getContent(), "Hello world!");
    ASSERT_EQ(a1.findFile(file2)->getContent(), "dadadadawdada");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}