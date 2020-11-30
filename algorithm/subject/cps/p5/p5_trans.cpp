#include <iostream>
#include <map>
#include <stack>

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
  for(int i =0; i<_len2; i++) {
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
  for(iter = --_func.end(); ; iter--) {
    func.push(iter->first);
    val.push(iter->second);
    if(first == 0) {
      max_index = func.top();
      max_value = val.top();
      first++;
    }
    if(iter == _func.begin()) break;
  }
  double cur_index = 0;
  double cur_value = 0;

  // 이미 함수 범위 초과일 경우
  if(max_index <= start) {
    sum += (end+1 - start) * max_value;
    printf("%0.f\n",sum);
    return 0;
  }
  // 이미 함수 범위 미만일 경우
  else if(end <= func.top()) {
    printf("0\n");
    return 0;
  }
  // start 범위보다 func.top()이 더 클 때
  if(func.top() < start) {
    while(1) {
      if(func.size() == 1) break;
      cur_index = func.top();
      cur_value = val.top();
      func.pop(); val.pop();
      if(cur_index <= start && start <= func.top()) {
        printf("check : %0.f %0.f\n",func.top(), val.top());
        func.push(cur_index); val.push(cur_value);
        break;
      }
      else if(func.top() < start) continue;
    }
  }

  // start = func.top();
  // printf("start : %0.f, end : %0.f\n",start, end);
  cur_index = 0;
  cur_value = 0;

  // 여기서 i는 start와 end를 돌게된다.
  // 안의 for문은 func의 index 값들과 비교하는 것인데, cnt를 통해 func을 탐색한다.
  // 여기서 cnt는 func의 어디까지 탐색했고, 어디부터 탐색해야하는지를 알려준다.
  for(double i = start; i<=end;) {
    printf("i : %0.f\n", i);
    // printf("func_size : %d\n",func.size());
    // 함수 요소가 하나 뿐일 때.
    if(func.size() == 1) {
      // 함수 요소가 end보다 작을 때는 end부터 i까지 더하면 됨.
      sum += (end+1 - i) * val.top();
      func.pop(); val.pop();
      flag = 1;
      break;
    }
    // 함수 요소가 2개 이상일 때.
    else {
      cur_index = func.top();
      cur_value = val.top();
      func.pop(); val.pop();
      printf("%0.f %0.f / %0.f %0.f\n",cur_index, cur_value, func.top(), val.top());
      // 정상적으로 더하면 됨.
      if(cur_index < end && func.top() < end) {
        // if() // 수정중
        // (현재 인덱스 - i 값) * 이전 인덱스의 값
        sum += (func.top() - i) * cur_value;
        // 건너뛰도록 i index 설정
        i = func.top();
      }
      else if(cur_index < end && end < func.top()) {
        sum += (end+1 - cur_index) * cur_value;
        printf("i: %0.f, cur_index : %0.f, cur_value : %0.f\n", i, cur_index, cur_value);
        flag = 1;
        break;
      }
      // end보다 같거나 클 경우이면. 끝내면 됨.
      else {
        printf("cur_value : %0.f\n",cur_value);
        sum += (end+1 - i) * val.top();
        flag = 1;
        break;
      }
    }
    if(flag == 1) break;
    // printf("%0.f\n",sum);
  }

  printf("%0.f\n",sum);

  // for(iter = func.begin(); iter != func.end(); iter++) {
  //   cout << "[" << iter->first << "," << iter->second << "]" << " ";
  // }

  // double count = 0;
  // for(double i = 0; i<2000000000; i++) {
  //   count++;
  // }
  // printf("cnt : %0.f\n",count);
  return 0;
}
