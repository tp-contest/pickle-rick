class IAdmins {
public:
    string virtual getAdminsForContest(un int contestID);
    string virtual getAdmin(un int adminID);
    string virtual getPermissions(un int adminD);
    bool virtual setPermissions(un int adminID);
    bool virtual addAdmin(un int userID);
};