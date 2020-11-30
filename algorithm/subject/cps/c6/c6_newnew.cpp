#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;
vector<int> v1;

int main() {
  int total, temp, max=0, tmax=0;

  cin >> total;

  vector<int> data;
  stack<int> st_data;
  vector<int> rev_data(data);
  vector<int> asc;
  vector<int> desc;

  // asc.assign(total, 0);
  // desc.assign(total, 0);
  // cout << total<< endl;
  vector<int> asc_arr;
  vector<int> desc_arr;
  for(int i=0; i<total; i++) {
    cin >> temp;
    data.push_back(temp);
    st_data.push(temp);
  }
  while(!st_data.empty()) {
    rev_data.push_back(st_data.top());
    st_data.pop();
  }

  vector<int> v;
  vector<int> copy(data);
  asc_arr.push_back(1);
  for(int i =1; i<total; i++) {
    int ans = 0;
    copy.clear();
    copy.assign(data.begin(), data.end());
    v.clear();
    v.push_back(-100);
    for(int j =0; j<=i; j++) {
      int here = copy[j];
      // printf("copy[%d] : %d, v.back() : %d\n",i,copy[i], v.back());
      if(v.back() < here) {
        v.push_back(here);
        ans++;
      }
      else {
        auto pos = lower_bound(copy.begin(), copy.end(), here);
        *pos = here;
      }
    }
    // printf("i : %d, copy[%d] : %d, answer : %d\n",i, i, copy[i], ans);
    asc_arr.push_back(ans);
  }

  // cout<< "---------------------------------------"<< total << endl;
  vector<int> v2;
  vector<int> copy2(data);
  desc_arr.push_back(1);
  // cout << desc_arr.size() << endl;
  for(int i=total-2; i>=0; i--) {
    int ans = 0;
    copy2.clear();
    copy2.assign(data.begin(), data.end());
    v2.clear();
    v2.push_back(-100);
    for(int j=total-1; j>=i; j--) {
      // printf("check!\n");
      int here = copy2[j];
      // printf("copy[%d] : %d, v.back() : %d\n",i,copy2[i], v2.back());
      if(v2.back() < here) {
        v2.push_back(here);
        ans++;
      }
      else {
        auto pos = lower_bound(copy2.rbegin(), copy2.rend(), here);
        *pos = here;
      }
    }
    // printf("i : %d, copy[%d] : %d, answer : %d\n",i, i, copy[i], ans);
    desc_arr.push_back(ans);
    // cout << "ans : " << ans << endl;
  }
  reverse(desc_arr.begin(), desc_arr.end());

  // cout << endl;
  // for(int i =0; i<total; i++) {
  //   printf("result[%d] :%d, data[%d], %d\n",i, asc_arr[i], i, data[i]);
  // }
  // cout << endl;
  // for(int i =0; i<total; i++) {
  //   printf("result[%d] :%d, data[%d], %d\n",i, desc_arr[i], i, data[i]);
  // }

  // ascending order의 가장 우측 요소가 최소한의 최대값이다.
  max = asc_arr[total-1];
  for(int i=total-1; i>=0; i--) {
    // ascending의 값+ descending의 최대값이 여기서 나올 수 있는 최대값이다. 그렇기 떄문에 max보다 작다면 볼 필요도 없다.
    if(max < (asc_arr[i] + desc_arr[0])) {
      for(int j=total-1; j>=i; j--) {
        tmax = 0;
        if(i < j && data[i] > data[j]) {
          tmax = asc_arr[i] + desc_arr[j];
          if(max < tmax) max = tmax;
        }
      }
    }
  }
  cout << max;



  // for(iter = origin.begin(); iter != origin.end(); iter++) {
  //   cout << iter->first << ", " << iter->second << endl;
  // }


}
