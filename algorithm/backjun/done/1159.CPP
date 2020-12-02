#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int N, cnt=0;
  cin >> N;
  string tmp;
  vector<int> name(27,0);

  getline(cin, tmp);
  for(int i=0; i<N; i++) {
    getline(cin, tmp);
    name[tmp[0]-96]++;
  }
  for(int i=0; i<27; i++) {
    if(name[i] >= 5) {
      printf("%c", i+96);
      cnt++;
    }
  }
  if(cnt == 0) cout << "PREDAJA";
  return 0;
}
