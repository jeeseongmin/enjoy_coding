#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int col, row;
  string tmp;
  cin >> col >> row;
  vector<int> answer(5,0), v(row,0);
  getline(cin, tmp);
  getline(cin, tmp);
  for(int i=1; i<=col*5; i++) {
    getline(cin, tmp);
    if(i%5 != 0) {
      for(int j=1; j<=row*5;) {
        if(tmp[j] == '*') {
          v[j/5]++;
        }
        j+=5;
      }
    }
    if(i%5 == 0) {
      for(int x=0; x<row; x++) {
        answer[v[x]]++;
      }
      v.assign(row,0);
    }
  }
  for(int i=0; i<5; i++) {
    cout<< answer[i] << " ";
  }
}
