#include <iostream>
#include <queue>
using namespace std;

int main() {
  int poles = 0;
  int amp = 0;
  priority_queue<int> pole_q;

  scanf("%d %d\n",&poles, &amp);

  for(int i=0; i<poles; i++) {
    int temp = 0;
    scanf("%d\n",&temp);
    pole_q.push(temp);
  }

  int pole_arr[poles]={0,};

  for(int j=poles-1; j>=0; j--) {
    pole_arr[j]=pole_q.top();
    pole_q.pop();
  }
  int start = 1;
  int end= pole_arr[poles-1]-pole_arr[0];
  int answer = 0;
  int avg;

  while(start<=end) {
    avg = (start+end) / 2;
    int temp_amp = 1;
    int _current = pole_arr[0];
    int _next;
    for(int i=1; i<poles; i++) {
      _next = pole_arr[i];
      if(_next - _current >= avg) {
        temp_amp++;
        _current = _next;
      }
    }
    if(temp_amp >= amp) {
      start = avg+1;
      answer = avg;
    }
    else {
      end = avg-1;
    }
  }

  printf("%d\n",answer);
  return 0;
}
