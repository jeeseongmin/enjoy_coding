#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;
vector<int> v1;
stack<int> copy_st;

int count(int index, int limit, stack<int> s) {
  int temp_value = 0;
  // 현재 항목을 포함하겠다.
  if(v1[index] < limit) {
    // 정상 (내림차순)
    if(v1[index] > s.top()) {
      s.push(v1[index]);
      temp_value = count(index+1, limit, s);
    }
    // 비정상 (역순)
    // 포함하지 않
    else if(v1[index] <= s.top()) {
      temp_value = count(index+1, limit, s);
    }
  }





}

int main() {
  int total, temp, max=0, tmax, avg, top, bottom, first, limit;
  multimap<int, int, greater<int>> origin;
  stack<int> store;
  cin >> total;
  vector<int> check;
  check.assign(total,0);

  cout << total<< endl;
  multimap<int, int, greater<int>> ::iterator iter;
  for(int i=0; i<total; i++) {
    cin >> temp;
    v1.push_back(temp);
    // cout << temp << endl;
    origin.insert(pair<int, int>(temp, i));
  }

  cout << endl;
  iter = origin.find(100);
  cout<< endl;
  cout << "value, " << "index" << endl;
  for(iter = origin.begin(); iter != origin.end(); iter++) {
    cout << iter->first << ", " << iter->second << endl;
  }
  cout<<endl;

  for(int start = 0; max <= total-start; start++) {
    cout << "v1[start] : " << v1[start] << endl;
    store.push(v1[start]);
    // 다음 구문은, 현재 index의 value를 start로 시작했으며, 다음 항목을 넣을지말지 결정하겠다는 의미.
    tmax = count(start+1, limit, store);
    if(max < tmax) max = tmax;
    // start가 다음 차례로 넘어갔다는 의미가 해당 요소를 포함하지 않았다는 의미.
  }
  cout << endl;
  cout << max << endl;
}
