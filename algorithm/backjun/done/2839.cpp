#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, answer=2000;
  cin >> N;
  int _three = N/3, _five=N/5;
  answer = (N%3 == 0)&&(answer > (N/3)) ? N/3 : answer;
  answer = (N%5 == 0)&&(answer > (N/5)) ? N/5 : answer;

  for(int i=0; i<_three; i++) {
    int rest = N-i*3;
    if(i<answer && (rest%5)==0) {
      answer = (answer > (i+rest/5)) ? (i+rest/5) : answer;
    }
  }
  if(answer == 2000) answer = -1;
  cout << answer;
}
