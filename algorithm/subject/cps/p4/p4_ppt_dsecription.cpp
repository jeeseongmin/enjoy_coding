#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int count = 0;
int disks = 0;
int destination = 0;

// stack
stack<int> rod[4];

// 현재 노드와 목표 노드 이외의 빈 노드를 찾는 함수.
// 만약 현재 노드와 목표 노드가 같다면 0을 반환합니다.
int empty_rod(int from, int to) {
  int total = 6;
  if(from != to) {
    return total-from-to;
  }
  else return 0;
}

// disk를 현재 노드에서 목표 노드로 하나 옮기는 함수입니다.
void Hanoi_moveOne(int index, int *loc, int from, int to) {
  rod[to].push(rod[from].top());
  rod[from].pop();
  loc[index] = to;
}

// 이 함수는 모든 n개의 disk들을 목표 노드로 옮기라고 명령하는 함수입니다.
void Hanoi(int index, int *loc, int from, int to) {
  // 맨처음에는 목표 노드와 현재 노드가 같은지 검사를 합니다.
  // 만약 같다면, 옮길 필요가 없기 때문에,
  /*
  세 가지 경우로 생각할 수 있습니다.
  현재 노드와 목표 노드가 같을 때, 이제 같을 때는 disk n이 원하는 위치에 있다는 것이기 때문에, disk n-1부터 검사를 시작하게 됩니다.
  그래서 1 ~ n-1의 노드들을 다시 recursion 하게 됩니다.

  그리고 현재 노드와 목표 노드가 다를 때는 두 가지 경우로 나눠볼 수 있습니다.
  1인 경우, 즉 마지막인 경우에는 1 하나만 옮기고 제거하면 되고,
  1이 아닌 경우, 즉 중간의 경우에는
  자신보다 아래의 모든 노드들을 빈노드로 옮기고,
  자신이 이동하고,
  아래의 모든 노드들을 다시 자신의 위로 옮기면 차례가 끝나게 됩니다.
  */
  if(from == to) {
    if(index != 1) {
      Hanoi(index-1, loc, loc[index-1], to);
    }
    else return ;
  }
  else if(from != to) {
    if(index != 1) {
      Hanoi(index-1, loc, loc[index-1], empty_rod(from, to));
      Hanoi_moveOne(index, loc, loc[index], to);
      count++;
      Hanoi(index-1, loc, loc[index-1], to);
      return ;
    }
    else {
      Hanoi_moveOne(index, loc, loc[index], to);
      count++;
      return ;
    }
  }
}

int main() {
  scanf("%d %d",&disks, &destination);
  // 여기서 loc는 location의 줄임말인데, 총 디스크의 개수+1을 통해서, index를 직관적으로 볼 수 있도록 했습니다.
  // 그리고 모든 disk들의 location을 저장해놓은 배열을 의미합니다.
  int loc[disks+1];
  loc[0] = 0;
  for(int i=1; i<=3; i++) {
    int cnt=0;
    scanf("%d ", &cnt);
    for(int j=0; j<cnt; j++) {
      int temp = 0;
      scanf("%d ", &temp);
      // 이 과정에서 진짜 stack에 집어넣은 뒤에, 현재 어떤 disk가 위치에 있는지 저장해놓습니다.
      rod[i].push(temp);
      loc[rod[i].top()] = i;
    }
  }
  // 모든 disk들을 목표 노드로 옮기라고 명령하는 함수입니다.
  Hanoi(disks, loc, loc[disks], destination);
  printf("%d\n",count);
}
