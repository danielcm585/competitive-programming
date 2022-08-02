#include <iostream>
using namespace std;

void destroyRow(int r) {
  // hancurkan row r
}

bool isFullRow(int r) {
  // cek row r apakah full
}

int getLastRow() {
  // hancurkan semua full row
  // return last row OR -1
}

int fallFromRow(int r) {
  // jatuhkan semua yang di atas row r
}

int main() {
  // input
  while (true) {
    int x = getLastRow();
    if (x == -1) break;
    fallFromRow(x);
  }
}
