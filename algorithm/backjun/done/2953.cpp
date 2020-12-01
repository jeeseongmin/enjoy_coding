#include <iostream>
#include <vector>
using namespace std;

int main() {
  int winner=0, max=0, tmp=0;
  vector<int> person(5, 0);

  for(int i=0; i<5; i++) {
    for(int j=0; j<4; j++) {
      cin >> tmp;
      person[i]+=tmp;
    }
    if(person[i] > max) {
      max = person[i];
      winner = i;
    }
  }
  cout << winner+1 << " " << max;
}
