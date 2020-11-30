#include <iostream>
#include <vector>

using namespace std;
int N, B, x, y, max_val=0, sum;
vector<int> tumor;
vector<vector<int>> con_matrix;
vector<vector<int>> check;
vector<int> mark;

// 현재 요소들중에 관계를 파악하고 더하는 함수.
int func(vector<int> temp) {
  cout<< "temp : ";
  for(int i=0; i<temp.size(); i++) {
    printf("%d ",temp[i]);
  }
  cout << endl;
  int _max_val=0;
  int _sum;
  int temp_sum;
  // 해당 요소를 포함한 그룹의 최대값을 구하기.
  if(temp.size() == 0) return 0;
  else if(temp.size() == 1) return tumor[temp[0]];
  vector<int> temp2;
  for(int x=0; x<temp.size()-1; x++) {
    // 처음값 + 해당 요소
    _sum = tumor[temp[x]];
    temp_sum = _sum;
    for(int y=1; y<temp.size(); y++) {
      // 만약 요소 간의 관계가 없다면 후자를 목록에서 제거.
      if(check[temp[x]][temp[y]] != 0) {
        temp2.push_back(temp[y]);
      }
    }
    cout<< "temp2 : ";
    for(int i=0; i<temp2.size(); i++) {
      printf("%d ",temp2[i]);
    }
    cout << endl;
    _sum += func(temp2);
    _max_val = (_max_val < _sum) ? _sum : _max_val;
  }
  // temp_sum+=tumor[temp.back()];
  // // 혹시 마지막 요소와의 합이
  // _max_val = (_max_val < temp_sum) ? temp_sum : _max_val;

  return _max_val;
}

int main() {
  cin >> N >> B;
  tumor.assign(N+1, 0);

  printf("N: %d, B: %d\n",N, B);
  for(int i=1; i<=N; i++) {
    cin >> tumor[i];
    printf("tumor[%d] : %d\n",i, tumor[i]);
  }
  vector<int> con_list[N+1];
  con_matrix.assign(N+1, vector<int>(N+1,0));
  check.assign(N+1, vector<int>(N+1, 0));
  vector<pair<int,int>> rel(N+1, {0,0});
  vector<int> temp;

  // vector<int> q(N+1, 0);
  mark.assign(N+1, 0);

  for(int i=1; i<=B; i++) {
    cin >> x >> y;
    printf("x : %d, y : %d\n",x, y);
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
    printf("con_list[%d] : ",i);
    for(int j=0; j<con_list[i].size(); j++) {
      printf("%d ",con_list[i][j]);
    }
    cout << endl;
  }

  for(int i=1; i<=N; i++) {
    sum=tumor[i];
    printf("i : %d, sum : %d\n",i, sum);
    // 사이즈가 하나이면 그 하나값만 더해서 max_val와 비교.
    if(con_list[i].size() == 0) continue;
    else if(con_list[i].size() == 1) {
      sum += con_list[i][0];
      max_val = (max_val < sum) ? sum : max_val;
      continue;
    }
    // 2개 이상이면 서로의 관계를 확인.
    else {
      // 먼저 해당 요소들을 모두 표시한다.
      printf("size : %d\n",con_list[i].size());
      for(int j=0; j<con_list[i].size(); j++) {
        if(check[i][con_list[i][j]] != 0) {
          temp.push_back(con_list[i][j]);
        }
      }
      sum+=func(temp);
      printf("sum : %d\n",sum);
    }
    max_val = (max_val < sum) ? sum : max_val;
    mark[i] = 1;
    temp.clear();
  }
  cout << max_val;
  return 0;
}
