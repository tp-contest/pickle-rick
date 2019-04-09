#include <iostream>
#include <gtest/gtest.h>
#include "libFileStorage/File.h"
#include "libFileStorage/Folder.h"
#include "libFileStorage/ContestFileManagerInMemory.h"


TEST (DummyFile, Setting) {
    File file1("bass");
    std::vector<char> tempContent = {'a', 'b', 'c'};

    file1.SetContent(tempContent);
    ASSERT_EQ(file1.GetContent(), tempContent);
}


TEST (Folder, AddingObjects) {
    Folder folder1("folder1");    
    File file1("file1");
    File file2("file2");

    folder1.AddFileObject(&file1);
    folder1.AddFileObject(&file2);
    File* bufferFile;

    folder1.GetFileObject(bufferFile, "file1");
    ASSERT_EQ(file1.GetName(), bufferFile->GetName());

    folder1.GetFileObject(bufferFile, "file2");
    ASSERT_EQ(file2.GetName(), bufferFile->GetName());
}

TEST (Folder, DeletingObjects) {
    Folder folder1("folder1");    
    File file1("file1");

    folder1.AddFileObject(&file1);
    File* bufferFile;

    folder1.RemoveFileObject("file1");
    folder1.GetFileObject(bufferFile, "file1");
    ASSERT_EQ(bufferFile, nullptr);
}

TEST (Folder, UnsuccesfulFind) {
    Folder folder1("folder1");    
    File file1("foo");
    File* bufferFile = &file1;

    folder1.GetFileObject(bufferFile, "goo");
    ASSERT_EQ(bufferFile, nullptr);
}

TEST (ContestStorageManager, SavingFiles) {
    auto contestFileManager = ContestFileManagerInMemory();
    ContestantInfo contestant1{1, 12};
    File file1("file1");

    contestFileManager.SaveFile(contestant1, &file1);
    File* bufferFile = nullptr;
    contestFileManager.FindFile(contestant1, bufferFile, "file1");
    ASSERT_EQ(bufferFile->GetName(), "file1");
}

TEST (ContestStorageManager, FindingFiles) {
    auto contestFileManager = ContestFileManagerInMemory();
    ContestantInfo contestant1{1, 12};
    ContestantInfo contestant2{1, 25};
    File file1("file1");
    File file2("file2");

    contestFileManager.SaveFile(contestant1, &file1);
    contestFileManager.SaveFile(contestant2, &file2);

    File* bufferFile = nullptr;
    contestFileManager.FindFile(contestant1, bufferFile, "file1");
    ASSERT_EQ(bufferFile->GetName(), "file1");

    bufferFile = nullptr;
    contestFileManager.FindFile(contestant2, bufferFile, "file2");
    ASSERT_EQ(bufferFile->GetName(), "file2");
}

TEST (ContestStorageManager, DeletingFiles) {

    auto contestFileManager = ContestFileManagerInMemory();
    ContestantInfo contestant1{1, 12};
    ContestantInfo contestant2{1, 25};
    File file1("file1");

    contestFileManager.SaveFile(contestant1, &file1);
    contestFileManager.DeleteFile(contestant1, "file1");
    File* bufferFile = &file1;
    contestFileManager.FindFile(contestant1, bufferFile, "file1");
    ASSERT_EQ(bufferFile, nullptr);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}