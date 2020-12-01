#include <iostream>
#include <vector>
using namespace std;
inline void end_game() {cout<<"mixed"; exit(0);}
int main() {
  vector<int> sound(8,0);
  int check;
  // 1이면 descending, 2이면 ascending
  for(int i=0; i<8; i++) {
    cin >> sound[i];
  }
  if(sound[0] > sound[7]) {
    check = sound[0];
    for(int i=0; i<8; i++) {
      if(check != sound[i]) end_game();
      check--;
    }
    cout << "descending";
  }
  else {
    check = sound[0];
    for(int i=0; i<8; i++) {
      if(check != sound[i]) end_game();
      check++;
    }
    cout << "ascending";
  }

  return 0;
}
