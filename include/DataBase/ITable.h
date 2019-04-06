class ITable {
public:
    string virtual getTable();
    string virtual getRow(un int ID);
    string virtual getColumn(un int ID, string columnName);
    bool virtual addRow(string row);
    bool virtual setRow(un int ID, string row);
    bool virtual deleteRow(un int ID);
};