#include<iostream>

using namespace std;

int main() {
  int N, x, y, answer;
  cin >> N;
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for(int i=0; i<N; i++) {
    cin >> x >> y;
    cout << x+y << "\n";
  }
}
