#pragma once

struct ContestantInfo {
    int ContestID;
    int ContestantID; 
    ContestantInfo(int _ContestID = 0, int _ContestantID = 0) : ContestID(_ContestID), ContestantID(_ContestantID) {};
};