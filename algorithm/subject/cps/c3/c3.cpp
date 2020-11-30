#include <iostream>
#include <vector>
using namespace std;

#define MAX_VALUE 1000000000

int afuel;
int bfuel;
int ufuel;
int city=0; // 정점
int rel; // 간선

typedef struct Min {
  int alpha=0;
  int beta=0;
  int united=0;
  int isalpha=0;
  int isbeta=0;
  // int isunited=0;
} Min;

void _init_mark(int *mark, int marking) {
  for(int i=0; i<=city; i++) {
    if(mark[i] != marking)
    mark[i] = 0;
  }
  mark[city] = 1;
}

int _comp_min(int X, int Y) {
  if(X == 0 && Y!=0) return Y;
  else if(X != 0 && Y ==0) return X;
  else if(X != 0 && Y !=0) return X<Y ? X : Y;
  else return 0;
}

struct Min _search(vector <int> w[], int *mark, int index, int marking) {
  struct Min _result;
  mark[index] = marking;
  int temp_alpha;
  int temp_beta;
  int temp_united;
  int temp_isalpha;
  int temp_isbeta;
  int cnt = 0;

  for(int v : w[index]) {
    if(mark[v] == 0) {
      cnt++;
    }
  }
  if(cnt > 1) marking+=1;
  struct Min arr[cnt];
  int x = 0;

  for(int v : w[index]) {
    if(mark[v] == 0) {
      arr[x] = _search(w,mark,v,marking);
      if(x==0) {
        temp_alpha = arr[x].alpha;
        temp_beta = arr[x].beta;
        temp_united = arr[x].united;
        temp_isalpha = arr[x].isalpha;
        temp_isbeta = arr[x].isbeta;
      }
      else {
        if(index == 1) {
          arr[x].isalpha = 1;
        }
        else if(index == 2) {
          arr[x].isbeta = 1;
        }
        temp_alpha = _comp_min(arr[x].alpha, temp_alpha);
        temp_beta = _comp_min(arr[x].beta, temp_beta);
        temp_united = _comp_min(arr[x].united, temp_united);
        temp_isalpha |= arr[x].isalpha;
        temp_isbeta |= arr[x].isbeta;
      }

      if(cnt > 1) {
        _init_mark(mark, marking-1);
      }
      x++;
    }
  }

  if(cnt == 0) {
    if(index == 1) {
      _result.isalpha = 1;
      _result.isbeta = 0;
      _result.alpha = 0;
      _result.beta = 0;
      _result.united =0;
    }
    else if(index == 2) {
      _result.isalpha = 0;
      _result.isbeta = 1;
      _result.alpha = 0;
      _result.beta = 0;
      _result.united =0;
    }
    else {
      _result.isalpha = 0;
      _result.isbeta = 0;
      _result.alpha = 0;
      _result.beta = 0;
      _result.united = 0;
    }
    return _result;
  }
  else {
    _result.isalpha = temp_isalpha;
    _result.isbeta = temp_isbeta;
    _result.alpha = temp_alpha;
    _result.beta = temp_beta;
    _result.united = temp_united;
    if(_result.isalpha == 1 && index != 1) _result.alpha += afuel;
    if(_result.isbeta == 1 && index != 2) _result.beta += bfuel;

    if(index == 1) _result.isalpha = 1;
    if(index == 2) _result.isbeta = 1;

    if(_result.isalpha == 1 && _result.isbeta ==1) {
      if(_result.united != 0) {
        _result.united += ufuel;
      }
      else {
        _result.united = _result.alpha + _result.beta;
      }
    }
  }
  return _result;
}

int main() {
  scanf("%d %d %d %d %d",&afuel, &bfuel, &ufuel, &city, &rel);
  vector<int> w[city+1];

  int mark[city+1];
  Min m1 = {0,0,0,0,0};
  Min *m2 = &m1;
  Min result = {0,0,0,0,0};
  for(int i=0; i<rel; i++) {
    int left;
    int right;
    scanf("%d %d",&left, &right);
    w[left].push_back(right);
    w[right].push_back(left);
  }
  _init_mark(mark, 0);

  int alpha_min=MAX_VALUE;
  int beta_min=MAX_VALUE;
  int united_min=MAX_VALUE;
  int result_min;
  int cnt_city = 0;
  cnt_city = w[city].size();
  struct Min temp[cnt_city];
  int y = 0;
  for(int v : w[city]) {
    temp[y] = _search(w, mark, v, 1);
    if(temp[y].isalpha == 1) temp[y].alpha+=afuel;
    if(temp[y].isbeta == 1) temp[y].beta+=bfuel;
    if(temp[y].isalpha == 1 && temp[y].isbeta == 1) {
      if(temp[y].united != 0) {
        temp[y].united+=ufuel;
      }
    }
    if(alpha_min > temp[y].alpha) alpha_min = temp[y].alpha;
    if(beta_min > temp[y].beta) beta_min = temp[y].beta;
    if(united_min > temp[y].united) united_min = temp[y].united;
    y++;
    _init_mark(mark, 0);
  }

  if(alpha_min+beta_min < united_min) {
    result_min = alpha_min+beta_min;
  }
  else {
    result_min = united_min;
  }

  printf("%d\n",result_min);
  return 0;
}
