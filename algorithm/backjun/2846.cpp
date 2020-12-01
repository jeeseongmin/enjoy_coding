#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, current=0, before=0, asc=0, desc=0, flag=0, max=0;
  cin >> N;
  vector<int> num(N, 0);
  for(int i=0; i<N; i++) {
    cin >> num[i];
  }
  before = num[0];
  for(int i=1; i<N; i++) {
    current = num[i];
    if(before >= current)
  }

}
