#include <iostream>
#include <vector>

using namespace std;
int N, B, x, y, max_val=0, sum, _max;
vector<int> tumor;
vector<vector<int>> con_matrix;
vector<vector<int>> check;
vector<int> mark;

int func(vector<int> temp, int _max) {
  int _max_val=0;
  int _sum;
  int temp_sum;
  if(temp.size() == 0) return 0;
  else if(temp.size() == 1) return tumor[temp[0]];
  vector<int> temp2;
  for(int x=0; x<temp.size()-1; x++) {
    // 처음값 + 해당 요소
    _sum = tumor[temp[x]];
    temp_sum = _sum;
    for(int y=1; y<temp.size(); y++) {
      if(check[temp[x]][temp[y]] != 0) {
        temp2.push_back(temp[y]);
      }
    }
    _sum += func(temp2, _max);
    if(_sum <= _max) {
      _max_val = (_max_val < _sum) ? _sum : _max_val;
    }
  }
  return _max_val;
}

int main() {
  cin >> N >> B;
  tumor.assign(N+1, 0);
  for(int i=1; i<=N; i++) {
    cin >> tumor[i];
  }
  vector<int> con_list[N+1];
  con_matrix.assign(N+1, vector<int>(N+1,0));
  check.assign(N+1, vector<int>(N+1, 0));
  vector<pair<int,int>> rel(N+1, {0,0});
  vector<int> temp;
  mark.assign(N+1, 0);

  for(int i=1; i<=B; i++) {
    cin >> x >> y;
    rel[i].first=x;
    rel[i].second=y;
    if(check[x][y] == 0) {
      con_list[x].push_back(y);
      con_matrix[x][y]=1;
      check[x][y]=1;
    }
    if(check[y][x] == 0) {
      con_list[y].push_back(x);
      con_matrix[x][y]=1;
      check[y][x]=1;
    }
  }

  for(int i=1; i<=N; i++) {
    sum=tumor[i];
    if(con_list[i].size() == 0) continue;
    else if(con_list[i].size() == 1) {
      sum += con_list[i][0];
      max_val = (max_val < sum) ? sum : max_val;
      continue;
    }
    else {
      for(int j=0; j<con_list[i].size(); j++) {
        if(check[i][con_list[i][j]] != 0) {
          temp.push_back(con_list[i][j]);
        }
      }
      sum+=func(temp,_max);
    }
    max_val = (max_val < sum) ? sum : max_val;
    mark[i] = 1;
    temp.clear();
  }
  cout << max_val;
  return 0;
}
