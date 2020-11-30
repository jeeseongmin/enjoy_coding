#include <iostream>
#include <set>
using namespace std;

int main() {
  int poles = 0;
  int amp = 0;
  set<int> index;
  // int trash;
  scanf("%d %d",&poles, &amp);
  // printf("poles : %d, amp : %d\n",poles, amp);
  for(int i=0; i<poles; i++) {
    int temp = 0;
    scanf("%d",&temp);
    index.insert(temp);
  }
  set<int>::iterator iter;
  int arr[poles]={0,};
  int cnt = 0;
  for(iter = index.begin(); iter != index.end(); iter++) {
    arr[cnt] = *iter;
    cnt++;
  }
  // for(int i=0; i<poles; i++) {
  //   printf("%d\n",arr[i]);
  // }
  int left = 1;
  int right= arr[poles-1]-arr[0];
  // printf("%d %d\n",left,right);
  // printf("%d %d\n",left, right);
  int min = 0;
  int mid=0;
  // amp와 일치가 되면 그때 dist 끝.
  // 근데 이제 최소값을 생각해야 하기 때문에.
  // 만약 temp_amp가 amp보다 크거나 같다면, 최소 거리의 범위를 늘려야 함.
  // 만약 temp_amp가 amp보다 작다면, 최소 거리의 범위를 줄여야 함.
  while(left<=right) {
    mid = (left+right) / 2;
    int temp_amp = 0;
    int _current = arr[0];
    int _next;
    temp_amp++;
    for(int i=0; i<poles; i++) {
      _next = arr[i];
      if(_next - _current >= mid) {
        temp_amp++;
        _current = _next;
      }
    }
    // 설치한 증폭기 수가 목표 중폭기 수보다 크거나 같을 때.
    if(temp_amp >= amp) {
      left = mid+1;
      min = mid;
    }
    // 설치한 증폭기 수가 목표 중폭기 수보다 작을 때.
    else {
      right = mid-1;
    }
  }
  printf("%d",min);
  return 0;
}
