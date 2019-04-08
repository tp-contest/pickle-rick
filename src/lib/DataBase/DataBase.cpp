#include <iostream>
#include "stdlib.h"

#include "DataBaseMySQL.h"

using namespace std;

int main() {
  cout << "Hello" << endl;
  DataBaseMySQL *base = new DataBaseMySQL;
  string adminName = base->admins->getAdmin(1);
  cout << adminName;
  int a = 0;
  cin >> a;
  return 0;
}