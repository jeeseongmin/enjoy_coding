#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int max_weight, temp, start, end, carrier=0;
  vector<int> weight;

  scanf("%d",&max_weight);
  while(cin>>temp){
    weight.push_back(temp);
  }
  sort(weight.begin(),weight.end());
  start = 0;
  end = weight.size()-1;
  while(start <= end) {
    if(start == end) {
      carrier++;
      break;
    }
    if(weight[start] + weight[end] > max_weight) {
      end--;
      carrier++;
    } else {
      carrier++;
      start++;
      end--;
    }
  }
  cout << carrier;
  return 0;
}
