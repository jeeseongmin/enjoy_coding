#include <iostream>
#include <vector>
using namespace std;

#define MAX_VALUE 1000000000

int afuel;
int bfuel;
int ufuel;
int city=0; // 정점
int rel; // 간선

int alpha_min=MAX_VALUE;
int beta_min=MAX_VALUE;
int united_min=MAX_VALUE;
int result_min;

typedef struct Min {
  int alpha=0;
  int beta=0;
  int united=0;
  int isalpha=0;
  int isbeta=0;
  // int isunited=0;
}Min;

void _init_mark(int *mark, int marking) {
  for(int i=0; i<=city; i++) {
    if(mark[i] != marking)
    mark[i] = 0;
  }
  mark[city] = 1;
}

// void _init_struct(struct Min *m2, int index) {
//   m2->alpha = 0;
//   m2->beta = 0;
//   m2->united = 0;
//   if(index == city) {
//     m2->isalpha = 0;
//     m2->isbeta = 0;
//     m2->isunited = 0;
//   }
// }
//
// void _update(struct Min *m2) {
//   if(m2->alpha < alpha_min && m2->alpha != 0) alpha_min = m2->alpha;
//   if(m2->beta < beta_min && m2->beta != 0) beta_min = m2->beta;
//   if(m2->united < united_min && m2->united !=0) united_min = m2->united;
// }
//
// void _sum(struct Min *m2) {
//   if(m2->isalpha == 1) m2->alpha += afuel;
//   if(m2->isbeta == 1) m2->beta += bfuel;
//   if(m2->isunited == 1) m2->united += ufuel;
// }
int _comp_min(int X, int Y) {
  if(X == 0 && Y!=0) return Y;
  else if(X != 0 && Y ==0) return X;
  else if(X != 0 && Y !=0) return X<Y ? X : Y;
  else return 0;
}
// void _print(struct Min *m2, int index) {
//   cout << "index : " << index << endl;
//   cout << "m2->alpha : "<< m2->alpha <<endl;
//   cout << "m2->beta : "<< m2->beta <<endl;
//   cout << "m2->united : "<< m2->united <<endl;
//   cout << "m2->isalpha : "<< m2->isalpha <<endl;
//   cout << "m2->isbeta : "<< m2->isbeta <<endl;
//   cout << endl;
// }
//
// void _calculate() {
//   if(united_min != 0) result_min = united_min;
//   if(alpha_min+beta_min < result_min && alpha_min * beta_min !=0) {
//     result_min = alpha_min+beta_min;
//   }
// }
// vector는 인접 리스트
// struct는 연료 저장값 3개
// mark는 경로 체크
// index는 현재 인덱스
struct Min _search(vector <int> w[], int *mark, int index, int marking) {
  printf("search(%d)\n",index);

  struct Min _result;
  if(index == city) {
    mark[index] = 1;
    int temp_alpha;
    int temp_beta;
    int temp_united;
    int temp_isalpha;
    int temp_isbeta;
    int cnt = 0;
    for(int i =0; i<=city; i++) {
      printf("mark[%d] : %d\n",i, mark[i]);
    }
    for(int v : w[index]) {
      if(mark[v] == 0) {
        cnt++;
      }
    }
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
          temp_alpha = _comp_min(arr[x].alpha, temp_alpha);
          temp_beta = _comp_min(arr[x].beta, temp_beta);
          temp_united = _comp_min(arr[x].united, temp_united);
        }
        // temp_isalpha = arr[x].isalpha;
        // temp_isbeta = arr[x].isbeta;
        // temp_isunited = arr[x].isunited;
        // printf("alpha : %d, beta : %d, united : %d, isalpha : %d, isbeta : %d, isunited : %d\n",temp_alpha, temp_beta, temp_united, temp_isalpha, temp_isbeta, temp_isunited);
        // printf("alpha_min : %d, beta_min : %d, united_min : %d\n",alpha_min, beta_min, united_min);
        _init_mark(mark, 0);
        // break;
        x++;
      }
      printf("------------------------------------\n");
    }

    // 가장 작은 값들만 모아둠.
    _result.alpha = temp_alpha;
    _result.beta = temp_beta;
    _result.united = temp_united;
    return _result;
  }
  else {
    mark[index] = marking;
    int temp_alpha;
    int temp_beta;
    int temp_united;
    int temp_isalpha;
    int temp_isbeta;
    // int temp_isunited = 0;
    int cnt = 0;
    for(int i =0; i<=city; i++) {
      printf("mark[%d] : %d\n",i, mark[i]);
    }
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
        // printf("submit - index : %d, alpha : %d, beta : %d, united : %d\n", index, arr[x].alpha, arr[x].beta, arr[x].united);
        // _print(m2, index);
        if(x==0) {
          if(arr[x].isalpha == 1) arr[x].alpha += afuel;
          if(arr[x].isbeta == 1) arr[x].beta += bfuel;
          if(arr[x].isalpha == 1 && arr[x].isbeta == 1) {
            if(arr[x].united != 0) {
              arr[x].united += ufuel;
            }
            else {
              arr[x].united = arr[x].alpha + arr[x].beta;
            }
          }
          printf("united : %d\n",arr[x].united);
          temp_alpha = arr[x].alpha;
          temp_beta = arr[x].beta;
          temp_united = arr[x].united;
          temp_isalpha = arr[x].isalpha;
          temp_isbeta = arr[x].isbeta;
        }
        else {
          if(arr[x].isalpha == 1) arr[x].alpha += afuel;
          if(arr[x].isbeta == 1) arr[x].beta += bfuel;
          if(arr[x].isalpha == 1 && arr[x].isbeta == 1) {
            if(arr[x].united != 0) {
              arr[x].united += ufuel;
            }
            else {
              arr[x].united = arr[x].alpha + arr[x].beta;
            }
          }
          printf("united : %d\n",arr[x].united);
          temp_alpha = _comp_min(arr[x].alpha, temp_alpha);
          temp_beta = _comp_min(arr[x].beta, temp_beta);
          temp_united = _comp_min(arr[x].united, temp_united);
          temp_isalpha |= arr[x].isalpha;
          temp_isbeta |= arr[x].isbeta;
        }

        // temp_isunited |= arr[x].isunited;
        if(cnt > 1) {
          _init_mark(mark, marking-1);
        }
        // _print(m2, index);
        x++;
        printf("index : %d, alpha : %d, beta : %d, united : %d, isalpha : %d, isbeta : %d\n",index, temp_alpha, temp_beta, temp_united, temp_isalpha, temp_isbeta);
      }
    }
    // 마지막 노드일 때.
    if(cnt == 0) {
      if(index == 1) {
        _result.isalpha = 1;
        _result.isbeta = 0;
        _result.alpha += afuel;
        _result.beta = 0;
        _result.united =0;
      }
      else if(index == 2) {
        _result.isalpha = 0;
        _result.isbeta = 1;
        _result.alpha =0;
        _result.beta += bfuel;
        _result.united =0;
      }
      return _result;
    }
    _result.isalpha = temp_isalpha;
    _result.isbeta = temp_isbeta;

    if((_result.isalpha==1 && index == 2) || (_result.isbeta==1 && index == 1)) {
      if(_result.isalpha == 1 && _result.isbeta ==1)    _result.united+=ufuel;
      else {
        // _result.isunited = 1;
        _result.united = _result.alpha + _result.beta;
      }
    }
    if(_result.isalpha == 1 && _result.isbeta ==1)    _result.united+=ufuel;

    if(_result.isalpha == 1) _result.alpha+=afuel;
    if(_result.isbeta == 1) _result.beta +=bfuel;
    // if(index == 1) {
    //   _result.isalpha = 1;
    // }
    // else if(index == 2) {
    //   _result.isbeta = 1;
    // }

    if(index == 1) {
      _result.isalpha = 1;
    }
    else if(index == 2) {
      _result.isbeta = 1;
    }
    // printf("index : %d, alpha : %d, beta : %d, united : %d, isalpha : %d, isbeta : %d\n",index, _result.alpha, _result.beta, _result.united, _result.isalpha, _result.isbeta);
    return _result;
  }
}

int main() {
  scanf("%d %d %d %d %d",&afuel, &bfuel, &ufuel, &city, &rel);
  // printf("afuel : %d, bfuel:%d, ufuel:%d, city:%d, rel:%d\n",afuel,bfuel,ufuel,city,rel);

  vector<int> w[city+1];

  int mark[city+1];
  Min m1 = {0,0,0,0,0};
  Min *m2 = &m1;
  Min result = {0,0,0,0,0};
  for(int i=0; i<rel; i++) {
    int left;
    int right;
    scanf("%d %d",&left, &right);
    printf("%d %d\n", left, right);
    w[left].push_back(right);
    w[right].push_back(left);
    // getchar();
  }
  _init_mark(mark, 0);

  result = _search(w, mark, 8, 1);
  cout << "result.alpha : " << result.alpha << endl;
  cout << "result.beta : " << result.beta << endl;
  cout << "result.united : " << result.united << endl;
  cout << "result.isalpha : " << result.isalpha << endl;
  cout << "result.isbeta : " << result.isbeta << endl;
  // cout << "result.isunited : " << result.isunited << endl;
  // _calculate();
  // _print(m2,8);
  // printf("alpha_min : %d, beta_min : %d, united_min : %d\n",alpha_min, beta_min, united_min);

  printf("%d\n",result.united);
  return 0;
}
