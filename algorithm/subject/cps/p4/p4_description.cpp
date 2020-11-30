#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

// 총 count
int count = 0;
int disks = 0;
int des_rod = 0;

// 1,2,3 rod를 쓰기 위함.
stack<int> rod[4];
// 전달 과정에서 임시 stack
// stack<int> temp;

int empty_rod(int from, int to) {
  int total = 6;
  if(from != to) {
    return total-from-to;
  }
  else return 0;
}
// n-1부터 1까지 정렬되어있는 모든 원판을 옮긴다. count에 2^(n-1) - 1 을 더해준다.
// 이때, stack을 이용하면 될것 같은 느낌.
void Hanoi_moveAll(int index, int *pos, int from, int to) {
  stack<int> temp;
  for(int i=0; i<index; i++) {
    temp.push(rod[from].top());
    rod[from].pop();
  }
  for(int j=0; j<index; j++) {
    rod[to].push(temp.top());
    temp.pop();
    pos[rod[to].top()] = to;
  }
  count += pow(2,index)-1;
}

void Hanoi_moveMe(int me, int *pos, int from, int to) {
  rod[to].push(rod[from].top());
  rod[from].pop();
  pos[me] = to;
}

void Hanoi(int cur, int *pos, int from, int to) {
  // printf("Hanoi(%d) - from : %d, to : %d\n",cur, from, to);
  if(from == to) {
    if(cur != 1) {
      Hanoi(cur-1, pos, pos[cur-1], to);
    }
    else return ;
  }
  else if(from != to) {
    if(cur != 1) {
      Hanoi(cur-1, pos, pos[cur-1], empty_rod(from, to));
      Hanoi_moveMe(cur, pos, pos[cur], to);
      // printf("cur : %d -> rod[%d]\n",cur,pos[cur]);
      count++;
      Hanoi_moveAll(cur-1, pos, pos[cur-1], to);
      return ;
    }
    else {
      Hanoi_moveMe(cur, pos, pos[cur], to);
      // printf("cur : %d -> rod[%d]\n",cur,pos[cur]);
      count++;
      return ;
    }
  }
}

int main() {
  scanf("%d %d",&disks, &des_rod);
  int pos[disks+1];
  pos[0] = 0;
  // printf("before : \n");
  for(int i=1; i<=3; i++) {
    int cnt=0;
    scanf("%d ", &cnt);
    // cout << "r[" << i << "] : ";
    for(int j=0; j<cnt; j++) {
      int temp = 0;
      scanf("%d ", &temp);
      rod[i].push(temp);
      // cout << rod[i].top()<< " ";
      pos[rod[i].top()] = i;
    }
    // cout << "\nstack size : "<< rod[i].size() << endl;
    // cout << endl;
  }
  Hanoi(disks, pos, pos[disks], des_rod);
  // printf("\nafter : \n");
  // for(int i =1; i<=3; i++) {
  //   for(int j =0; j<cnt; j++) {
  //     cout<< rod[i].top()<< " ";
  //   }
  //   cout << "\nstack size : "<< rod[i].size() << endl;
  // }
  printf("%d\n",count);
}
