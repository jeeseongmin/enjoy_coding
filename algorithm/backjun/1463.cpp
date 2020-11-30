#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
  return a > b ? b : a;
}

int main() {
  int N, answer=0, tmp;
  cin >> N;
  vector<int> dp(N+1, 0);
  for(int i=2; i<N+1; i++) {
    dp[i] = dp[i-1] + 1;
    if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
    if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
  }
  cout << dp[N];
}
