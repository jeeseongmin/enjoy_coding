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
  // vector<int> check;
  // check.assign(total,0);

  vector<int> data;
  vector<int> data_sort;
  vector<int> asc;
  vector<int> desc;

  priority_queue<pair<int, int>> pq;
  multimap<int, int, greater<int>> ::iterator asc_iter;
  multimap<int, int, greater<int>> ::iterator desc_iter;
  asc.assign(total, 0);
  desc.assign(total, 0);
  // cout << total<< endl;
  int check = 0;
  for(int i=0; i<total; i++) {
    cin >> temp;
    data.push_back(temp);
  }
  // cout << "value, index" << endl;
  // for(int i=0; i<total; i++) {
  //   printf("%d : %d\n",i, data[i]);
  // }



  // 데이터 넣은 대로 정렬한
  for(int i=0; i<total; i++) {
    check = 0;
    // 비어있다면 정상
    if(!asc_map.empty()) {
      // 제일 큰 value
      for(asc_iter = asc_map.begin(); asc_iter != asc_map.end(); asc_iter++) {
        if(data[asc_iter->second] < data[i]) {
          // printf("data[%d] : %d, data[%d] : %d\n",asc_iter->second, data[asc_iter->second], i, data[i]);
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
    // 비어있다면
    else {
      asc_map.insert(pair<int, int>(1, i));
      data_sort.push_back(data[i]);
    }
    sort(data_sort.begin(), data_sort.end());
  }

  // cout << "---------------data_sort-----------------" << endl;
  // for(int i =0; i<total; i++) {
  //   cout << data_sort[i] << endl;
  // }
  // cout << "-------------------------------------" << endl;
  // cout << "test" << endl;
  // cout << lower_bound(data_sort.begin(), data_sort.end(), 4) - data_sort.begin() << endl;
  // cout << lower_bound(data_sort.begin(), data_sort.end(), 5) - data_sort.begin() << endl;
  // cout << lower_bound(data_sort.begin(), data_sort.end(), 2) - data_sort.begin() << endl;
  // cout << "test" << endl;
  // 만약 자기보다 작은

  // printf("value, index\n");
  // printf("size:  %d\n",asc_map.size());
  // for(desc_iter = asc_map.begin(); asc_iter != asc_map.end(); asc_iter++) {
  //   cout << asc_iter ->first << ", " << asc_iter->second << endl;
  // }
  for(int i=total-1; i>=0; i--) {
    check = 0;
    // 비어있다면 정상
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
    // 비어있다면
    else {
      desc_map.insert(pair<int, int>(1, i));
    }
  }

  // 오름차순 중에 제일 큰 값.
  max = asc_map.begin()->first;
  // 여기부터 검사.
  for(asc_iter = asc_map.begin(); asc_iter != asc_map.end(); asc_iter++) {
    // 먼저 max가 여기서 가질 수 있는 최대 값보다 큰지 비교한다. 크다면 검사할 필요가 없기때문에.
    if(max < (asc_iter->first + desc_map.begin()->first)) {
      for(desc_iter = desc_map.begin(); desc_iter != desc_map.end(); desc_iter++) {
        tmax = 0;
        // index는 오른쪽이 커야 하고, value는 왼쪽이 커야함.
        if(asc_iter->second < desc_iter->second && data[asc_iter->second] > data[desc_iter->second]) {
          tmax = asc_iter->first + desc_iter->first;
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
