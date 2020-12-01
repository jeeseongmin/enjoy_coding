#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string a, b;
  int _a, _b, _sum;
  int ax, bx;
  cin >> a >> b;
  int max = (a.size() > b.size()) ? a.size() : b.size();
  vector<int> result(max+1, 0);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for(int i=0; i<max; i++) {
    _a = a[i];
    _b = b[i];
    _sum = result[i];
    ax = (48<=_a && _a <=57) ? a[i] : '0';
    bx = (48<=_b && _b <=57) ? b[i] : '0';
    int _result = (ax+bx)-96 + _sum;
    if(_result >= 10) {
      result[i+1]=1;
      result[i] = _result-10;
    }
    else {
      result[i] = _result;
    }
  }
  for(int i=result.size()-1; i>=0; i--) {
    if(i==result.size()-1 && result[i] == 0) continue;
    cout<< result[i];
  }
}
