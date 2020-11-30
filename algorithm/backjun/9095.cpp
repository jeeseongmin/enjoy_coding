#include <iostream>
#include <vector>

using namespace std;
int main() {
  int N, max=0;
  cin >> N;

  vector<int> num(N+1, 0);
  for(int i=1; i<=N; i++) {
    cin >> num[i];
    cout << num[i] << endl;
    max = (max < num[i]) ? num[i] : max;
  }
  vector<int> dp(max+1, 0);
  dp[1]=0;
  dp[2]=1;
  for(int i=3; i<=max; i++) {
    dp[i] = dp[i-1]*2 + 1;
  }
  cout<< "result : " << endl;
  for(int i=1; i<=N; i++) {
    cout << dp[num[i]] << endl;
  }
}
// d(2) = 1
// d(3) = 3
// d(4) = 7
// d(5) = 15
