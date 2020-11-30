#include <iostream>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
int main() {
  map<double, double> _func;
  int _len1;
  int _len2;
  double start;
  double end;

  scanf("%d",&_len1);
  for(int i =0; i<_len1; i++) {
    double temp_index;
    double temp_value;
    scanf("%lf %lf",&temp_index, &temp_value);
    _func.insert(pair <double,double>(temp_index, temp_value));
  }
  scanf("%d",&_len2);
  for(int i=0; i<_len2; i++) {
    double temp_index;
    double temp_value;
    scanf("%lf %lf",&temp_index, &temp_value);
    if(_func.find(temp_index) == _func.end()) {
      _func.insert(pair <double, double>(temp_index, temp_value));
    }
    else {
      _func[temp_index] = (_func[temp_index] > temp_value) ? _func[temp_index] : temp_value;
    }
  }
  scanf("%lf %lf",&start, &end);
  // printf("start : %0.f, end : %0.f\n",start, end);
  map<double, double>::iterator iter;
  double sum = 0;
  double cnt = 0;
  int flag = 0;
  stack <double> func;
  stack <double> val;
  int first = 0;
  double max_index;
  double max_value;
  // for(iter = _func.begin(); iter != _func.end(); iter++) {
  //   printf("%0.f %0.f\n",iter->first, fmod(iter->second,10007));
  // }
  for(iter = --_func.end(); ; iter--) {
    func.push(iter->first);
    val.push(iter->second);
    // val.push(fmod(iter->second,10007));
    if(val.top() >= 10007) {
      int temp = fmod(val.top(),10007);
      val.pop();
      val.push(temp);
    }
    if(first == 0) {
      max_index = func.top();
      max_value = val.top();
      first++;
    }
    if(iter == _func.begin()) break;
  }
  double cur_index = 0;
  double cur_value = 0;
  // printf("max_index : %0.f, max_value : %0.f\n",max_index, max_value);
  // printf("start : %0.f, end : %0.f\n",start, end);

  // 이미 함수 범위 미만일 경우
  if(end <= func.top()) {
    if(end == func.top()) sum += val.top();
    // printf("result : %0.f %0.f %0.f\n",func.top(), val.top(), sum);
    printf("%0.f",fmod(sum, 10007));
    return 0;
  }
  // 이미 함수 범위 초과일 경우
  else if(max_index <= start) {
    sum += (end+1 - start) * max_value;
    // printf("result : %0.f %0.f %0.f\n",max_index, max_value, sum);
    printf("%0.f",fmod(sum, 10007));
    return 0;
  }
  // start와 end 사이에 함수가 있는 경우
  // 이 경우 stack에서 start를 func.top()으로 맞춰야 함.
  // 이 경우에도 start가 무조건 func.top과 맞춰져 있는 상태로 시작됨.
  // func.top() 미만은 0이기 때문이다. 그래서 func.top()부터 시작하는게 맞음.
  else if(start <= func.top()) {
    if(start == func.top()) ;
    else {
      start = func.top();
    }
  }
  // 함수 사이에 start와 end가 있는 경우
  // 이 경우에는 cur_index와 cur_value를 저장해가면서
  // start보다 작은 func.top()들을 모두 지운다.
  // start보다 크거나 같으면 break;
  // 그러면 현재 cur_index와 cur_value에는 이전 value가 남아있기 때문에 무조건 그 index부터 시작하면 된다.
  else if(func.top() < start) {
    while(1) {
      if(func.size() == 1) break;
      if(func.top() < start) {
        cur_index = func.top();
        cur_value = val.top();
        func.pop(); val.pop();
      }
      else if(func.top() == start) {
        cur_index = 0; cur_value = 0;
        break;
      }
      else {
        break;
      }
    }
    if(end < func.top()) {
      sum += (end+1 - start) * cur_value;
      flag = 1;
      printf("%0.f",fmod(sum, 10007));
      return 0;
    }
    else if(end == func.top()) {
      sum += (end - start) * cur_value;
      sum += val.top();
      flag = 1;
      printf("%0.f",fmod(sum, 10007));
      return 0;
    }
    else {
      if(cur_index != 0 && cur_value != 0) {
        sum += (func.top() - start) * cur_value;
        start = func.top();
      }
    }
  }
  // printf("func_top : %0.f, func_value : %0.f, cur_index : %0.f, cur_value : %0.f\n", func.top(), val.top(), cur_index, cur_value);
  // printf("sum : %0.f\n",sum);
  // printf("start : %0.f\n",start);

  for(double i= start; i<=end;) {
    if(start == end) {
      sum += val.top();
      // printf("result : %0.f %0.f %0.f\n",func.top(), val.top(), sum);
      flag = 1;
      break;
    }
    // printf("i : %0.f\n",i);
    if(func.size() == 1) {
      sum += (end+1 - i) * val.top();
      // printf("result : %0.f %0.f %0.f\n",func.top(), val.top(), sum);
      // printf("%0.f - %0.f : %0.f\n",end+1, i, val.top());
      func.pop(); val.pop();
      flag = 1;
      break;
    }
    else {
      cur_index = func.top();
      cur_value = val.top();
      func.pop(); val.pop();
      // 다음 요소도 아직 end에 닿긴 멀었을 떄.
      if(func.top() < end) {
        sum += (func.top() - i) * cur_value;
        // printf("result : %0.f %0.f %0.f\n",cur_index, cur_value, sum);
        // printf("result : %0.f %0.f %0.f\n",func.top(), val.top(), sum);
        // printf("%0.f - %0.f : %0.f\n",func.top(), i, cur_value);
        i= func.top();
      }
      // 다음 요소까지가 end일 때에.
      else if(func.top() == end) {
        sum += (end - cur_index) * cur_value;
        sum += val.top();
        // printf("result : %0.f %0.f %0.f\n",cur_index, cur_value, sum);
        // printf("result : %0.f %0.f %0.f\n",func.top(), val.top(), sum);
        // printf("%0.f - %0.f : %0.f\n",end, cur_index, cur_value);
        flag = 1;
        break;
      }
      // end 가 다음 요소보다 작을 때.
      else if(end < func.top()){
        // printf("val : %0.f\n", (end+1 - cur_index) * cur_value);
        sum += (end+1 - cur_index) * cur_value;
        // printf("%0.f - %0.f : %0.f\n",end+1, cur_index, cur_value);
        flag = 1;
        break;
      }
    }
    if(flag == 1) break;
  }
  // printf("before : %0.f\n",sum);
  sum = fmod(sum, 10007);
  printf("%0.f",sum);
  // printf("final : %0.f\n",fmod(2000000000, 10007));
  return 0;
}
