#include <iostream>
#include <vector>
using namespace std;

int find_value(vector<int> data, int start, int end, int type) {
  int _value = data[start];
  int _index = start;
  if(type == 0) {
    for(int i=start+1; i<=end; i++) {
      if(data[i] > _value) {
        _value = data[i];
        _index = i;
      }
    }
  }
  else if(type == 1) {
    for(int i=start+1; i<=end; i++) {
      if(data[i] < _value) {
        _value = data[i];
        _index = i;
      }
    }
  }
  return _index;
}

int sum_all(vector<int> data, int start, int end) {
  int _sum=0;
  for(int i=start; i<=end; i++) {
    _sum = data[i] * 2;
  }
  return _sum;
}

int combine(vector<int> data, int start, int end) {
  printf("");
  int _sum = 0;
  if(start == end) return data[start];
  vector<int> temp_data(data);
  vector<int> temp_sum;
  int leng = end-start+1;
  int mid = find_value(temp_data, start, end, 0);

  if(leng > 4) {
    int mid = find_value(data, start, end, 0);
    printf("max : %d\n",mid);
    int left = combine(data, start, mid-1);
    int right = combine(data, mid+1, end);
    _sum = (data[mid] + left + right) * 2;
    _sum += max(left, right);
  }
  else if (leng == 2) {
    _sum = data[start] + data[end];
  }
  else if (leng == 3) {
    _sum += sum_all(data, start, end);
    _sum -= (data[start] > data[end]) ? data[start] : data[end];
  }
  return _sum;
}

int main() {
  int total, temp, sum=0;
  cin >> total;
  vector<int> data;
  for(int i=0; i<total; i++) {
    cin >> temp;
    data.push_back(temp);
  }
  vector<int> _data(data);
  sum = combine(_data, 0, total-1);
  cout << sum << endl;
}
