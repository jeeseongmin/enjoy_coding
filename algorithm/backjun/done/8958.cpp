#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int N, max=0, answer=0, cnt=1;
  cin >> N;
  string temp, str[N];
  getline(cin, temp);
  for(int i=0; i<N; i++) {
    getline(cin, str[i]);
  }
  for(int i=0; i<N; i++) {
    cnt = 0;
    for(int j=0; j<str[i].size(); j++) {
      if(str[i][j] == 'O') {
        answer += ++cnt;
        max = (answer > max) ? answer : max;
      }
      else cnt = 0;
    }
    cout << max << endl;
    max=0;
    answer=0;
  }
}
