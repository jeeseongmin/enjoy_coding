#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
  int N, move=0, back=0;
  cin >> N;
  string str;
  getline(cin, str);
  stack cur_str;
  for(int i=0; i<N; i++) {
    getline(cin, str);
    for(int j=0; j<str.size(); j++) {
      printf("check!\n");
    }
  }
}
