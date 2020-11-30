#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int count = 0;
int disks = 0;
int destination = 0;

stack<int> rod[4];

int empty_rod(int from, int to) {
  int total = 6;
  if(from != to) {
    return total-from-to;
  }
  else return 0;
}

void Hanoi_moveOne(int index, int *loc, int from, int to) {
  rod[to].push(rod[from].top());
  rod[from].pop();
  loc[index] = to;
}

void Hanoi(int index, int *loc, int from, int to) {
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
  int loc[disks+1];
  loc[0] = 0;
  for(int i=1; i<=3; i++) {
    int cnt=0;
    scanf("%d ", &cnt);
    for(int j=0; j<cnt; j++) {
      int temp = 0;
      scanf("%d ", &temp);
      rod[i].push(temp);
      loc[rod[i].top()] = i;
    }
  }
  Hanoi(disks, loc, loc[disks], destination);
  printf("%d\n",count);
}
