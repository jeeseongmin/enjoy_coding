#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> check(42,0);
  int temp, answer=0;
  for(int i=0; i<10; i++) {
    cin >> temp;
    check[temp%42] = 1;
  }
  for(int i=0; i<42; i++) {
    if(check[i] == 1) answer++;
  }
  cout << answer;
}
