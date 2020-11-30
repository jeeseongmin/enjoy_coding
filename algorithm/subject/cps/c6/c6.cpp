#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
vector<int> v1;
stack<int> copy_st;

int main() {
  int total, temp, max=0, tmax=0;
  multimap<int, int, greater<int>> asc_map;
  multimap<int, int, greater<int>> desc_map;
  stack<int> store;
  cin >> total;
  vector<int> data;
  vector<int> data_sort;
  vector<int> asc;
  vector<int> desc;

  priority_queue<pair<int, int>> pq;
  multimap<int, int, greater<int>> ::iterator asc_iter;
  multimap<int, int, greater<int>> ::iterator desc_iter;
  asc.assign(total, 0);
  desc.assign(total, 0);
  int check = 0;
  for(int i=0; i<total; i++) {
    cin >> temp;
    data.push_back(temp);
  }
  for(int i=0; i<total; i++) {
    check = 0;
    if(!asc_map.empty()) {
      for(asc_iter = asc_map.begin(); asc_iter != asc_map.end(); asc_iter++) {
        if(data[asc_iter->second] < data[i]) {
          asc_map.insert(pair<int, int>((asc_iter->first)+1, i));
          data_sort.push_back(data[i]);
          check = 1;
          break;
        }
      }
      if(check == 0) {
        asc_map.insert(pair<int, int>(1, i));
        data_sort.push_back(data[i]);
      }
    }
    else {
      asc_map.insert(pair<int, int>(1, i));
      data_sort.push_back(data[i]);
    }
    sort(data_sort.begin(), data_sort.end());
  }
  for(int i=total-1; i>=0; i--) {
    check = 0;
    if(!desc_map.empty()) {
      for(desc_iter = desc_map.begin(); desc_iter != desc_map.end(); desc_iter++) {
        if(data[desc_iter->second] < data[i]) {
          desc_map.insert(pair<int, int>((desc_iter->first)+1, i));
          check = 1;
          break;
        }
      }
      if(check == 0) {
        desc_map.insert(pair<int, int>(1, i));
      }
    }
    else {
      desc_map.insert(pair<int, int>(1, i));
    }
  }

  max = asc_map.begin()->first;
  for(asc_iter = asc_map.begin(); asc_iter != asc_map.end(); asc_iter++) {
    if(max < (asc_iter->first + desc_map.begin()->first)) {
      for(desc_iter = desc_map.begin(); desc_iter != desc_map.end(); desc_iter++) {
        tmax = 0;
        if(asc_iter->second < desc_iter->second && data[asc_iter->second] > data[desc_iter->second]) {
          tmax = asc_iter->first + desc_iter->first;
          if(max < tmax) max = tmax;
        }
      }
    }
  }
  cout << max;
}
