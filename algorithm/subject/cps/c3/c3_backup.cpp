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
  int alpha;
  int beta;
  int united;
  int isalpha;
  int isbeta;
  int isunited;
  int temp_alpha;
  int temp_beta;
}Min;

void _init(struct Min *m2, int *mark, int type) {
  if(type==0) {
    for(int i=0; i<=city; i++) {
      mark[i] = 0;
    }
  }
  m2->alpha = 0;
  m2->beta = 0;
  m2->united = 0;
  m2->isalpha = 0;
  m2->isbeta = 0;
}

void _compare(struct Min *m2) {
  if(m2->alpha < alpha_min && m2->alpha != 0) alpha_min = m2->alpha;
  if(m2->beta < beta_min && m2->beta != 0) beta_min = m2->beta;
  if(m2->united < united_min && m2->united !=0) united_min = m2->united;
}

void _update(struct Min *m2) {
  if(m2->isalpha == 1) m2->alpha += afuel;
  if(m2->isbeta == 1) m2->beta += bfuel;
  if(m2->isunited == 1) m2->united += ufuel;
}

void _print(struct Min *m2, int index) {
  cout << "index : " << index << endl;
  cout << "m2->alpha : "<< m2->alpha <<endl;
  cout << "m2->beta : "<< m2->beta <<endl;
  cout << "m2->united : "<< m2->united <<endl;
  cout << endl;
}

void _calculate() {
  if(united_min != 0) result_min = united_min;
  if(alpha_min+beta_min < result_min && alpha_min * beta_min !=0) {
    result_min = alpha_min+beta_min;
  }
}
// vector는 인접 리스트
// struct는 연료 저장값 3개
// mark는 경로 체크
// index는 현재 인덱스
void _search(vector <int> w[], struct Min *m2, int *mark, int index) {
  cout << "search(index) : "  << index << endl;
  // mark[index] = 1;
  if(index == 8) {
    mark[index] = 1;
    for(int v : w[index]) {
      mark[index] = 1;
      if(mark[v] == 0) {
        _search(w, m2, mark, v);
        _update(m2);
        _print(m2, index);
        _compare(m2);
        _init(m2, mark,0);
        // break;
      }
    }

    return ;
  }
  // alpha에 도착했다면, flag만 1 바꿔주고 return
  else if(index == 1) {
    m2->isalpha = 1;
    return ;
  }
  // beta에 도착했다면, flag만 1 바꿔주고 return
  else if(index == 2) {
    m2->isbeta = 1;
    return ;
  }
  // index 8이 아닌 중간일 때.
  else {
    mark[index] = 1;
    int temp_alpha=0;
    int temp_beta=0;
    int temp_united=0;
    int temp_isalpha = 0;
    int temp_isbeta = 0;

    // cout << "isalpha : " << m2->isalpha << endl;
    // cout << "temp_alpha : " << m2->temp_alpha << endl;
    // cout << "isbeta : " << m2->isbeta << endl;
    // cout << "temp_alpha : " << m2->temp_alpha << endl;

    for(int v : w[index]) {
      if(mark[v] == 0) {
        _search(w,m2,mark,v);
        // _print(m2, index);
        _update(m2);
        temp_alpha += m2->alpha;
        temp_beta += m2->beta;
        temp_united += m2->united;
        temp_isalpha |= m2->isalpha;
        temp_isbeta |= m2->isbeta;
        _init(m2, mark, 1);
        _print(m2, index);
      }
    }
    m2->alpha = temp_alpha;
    m2->beta = temp_beta;
    m2->united = temp_united;
    m2->isalpha = temp_isalpha;
    m2->isbeta = temp_isbeta;
    if(m2->isalpha == 1 && m2->isbeta == 1) {
      if(m2->isunited == 0) {
        m2->isunited = 1;
        m2->united = m2->alpha + m2->beta;
      }
    }
    _print(m2, index);

    return ;
  }
}

int main() {
  scanf("%d %d %d %d %d",&afuel, &bfuel, &ufuel, &city, &rel);
  // printf("afuel : %d, bfuel:%d, ufuel:%d, city:%d, rel:%d\n",afuel,bfuel,ufuel,city,rel);

  vector<int> w[city+1];

  int mark[city+1];
  Min m1 = {0,0,0,0,0};
  Min *m2 = &m1;

  for(int i=0; i<rel; i++) {
    int left;
    int right;
    scanf("%d %d",&left, &right);
    printf("%d %d\n", left, right);
    w[left].push_back(right);
    w[right].push_back(left);
    // getchar();
  }
  _init(m2, mark,0);
  // for(int i=1; i<=city; i++) {
  //   for(int v : w[i]) {
  //     cout<< "w[" << i<< "] :" << v <<endl;
  //   }
  // }

  _search(w, m2, mark, 8);
  _calculate();


  printf("%d\n",result_min);
  return 0;
}
