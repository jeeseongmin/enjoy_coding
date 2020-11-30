#include <iostream>
#include <queue>
using namespace std;

int main() {
  int poles = 0;
  int amp = 0;
  priority_queue<int> pole_q;

  scanf("%d %d\n",&poles, &amp);
  //처음에 폴의 위치들을 q에 입력받는다.
  // 자동으로 정렬이 된다.
  for(int i=0; i<poles; i++) {
    int temp = 0;
    scanf("%d\n",&temp);
    pole_q.push(temp);
  }
  // 오름차순으로 재정렬하기 위해 썼습니다.
  // 그런데 비교 연산자를 사용하면 이 부분을 생략할 수 있는데, 깜빡했습니다.
  int pole_arr[poles]={0,};

  for(int j=poles-1; j>=0; j--) {
    pole_arr[j]=pole_q.top();
    pole_q.pop();
  }
  // 시작을 1, 끝을 limit인 끝요소 - 첫요소로 놓습니다.
  int start = 1;
  int end= pole_arr[poles-1]-pole_arr[0];
  int answer = 0;
  int avg;
  // 그리고 이제 이분탐색을 시작합니다.
  // 평균값을 기준으로 하고, (이때의 평균값은 최소거리를 의미합니다. )
  // 결국 어떠한 최소거리값이 맞는지 찾아가는 과정이라고 볼 수 있습니다.
  while(start<=end) {
    avg = (start+end) / 2;
    // 저희는 양쪽 끝중 둘 모두 혹은 하나는 무조건 증폭기를 설치되어있다고 생각했습니다.
    // 왜냐하면 증폭기가 설치되었을 때 두 증폭기 거리는 최대한 커야하기 때문에 무조건 양쪽 끝이 정해져있을 것이기 때문입니다.
    // 그래서 여기서 한개를 설치하고 시작합니다.
    int temp_amp = 1;
    // 현재 index 위치
    int _current = pole_arr[0];
    int _next;

    for(int i=1; i<poles; i++) {
      _next = pole_arr[i];
      // 이제 다음 값과의 거리가 평균값, 즉 최소거리보다 클거나 같을 경우에는 발전기를 설치할 수 있기 때문에 설치하게 되고,
      // 현재 위치를 발전기를 설치한 위치로 변경합니다.
      if(_next - _current >= avg) {
        temp_amp++;
        _current = _next;
      }
    }
    // 이렇게 한턴이 끝났을 때에 목표값과 증폭기 값보다 같거나 크다면 answer를 업데이트합니다.
    // 물론 여기서 진짜 answer가 나오지 않지만, 결국 끝까지 이분탐색을 진행했을 때 정답이 나오게 됩니다.
    // 목표값보다 설치한 증폭기 값이 크다는 의미는, 최소 거리가 작았기 때문에 처음 정했던 평균값보다 더 큰 범위에서 최소 거리를 탐색해야 합니다.
    //
    if(temp_amp >= amp) {
      start = avg+1;
      answer = avg;
    }
    // 목표값보다 설치한 증폭기의 값이 작다는 의미는, 최소 거리가 컸기 때문에 처음 정했던 평균값보다 더 작은 범위에서 최소 거리를 탐색해야 합니다.
    else {
      end = avg-1;
    }
  }

  // 비교를 어떻게 하는지.

  printf("%d\n",answer);
  return 0;
}
