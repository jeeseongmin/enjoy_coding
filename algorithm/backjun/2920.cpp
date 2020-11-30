#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> sound(8,0);
  int check;
  // 1이면 descending, 2이면 ascending
  for(int i=0; i<8; i++) {
    cin >> sound[i];
  }
  if(sound[0] == 1){
    check = 1;
    for(int i=0; i<8; i++) {
      if(check != sound[i]) {
        printf("ascending");
        exit(0);
      }
      check++;
    }
  }
  else if(sound[0] == 8) {
    check = 8;
    for(int i=0; i<8; i++) {
      if(check != sound[i]) {
        printf("ascending");
        exit(0);
      }
      check--;
    }
  }
  printf("mixed");
  return 0;
}
