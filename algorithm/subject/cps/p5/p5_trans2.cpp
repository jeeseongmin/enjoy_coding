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
  int first = 0;

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
  printf("start : %0.f, end : %0.f\n",start, end);
  map<double, double>::iterator iter;
  double sum = 0;
  double cnt = 0;
  int flag = 0;
  stack <double> func;
  stack <double> val;
  for(iter = --_func.end(); ; iter--) {
    func.push(iter->first);
    val.push(iter->second);
    if(iter == _func.begin()) break;
  }
  // while(!func.empty()) {
  //   printf("%f %f\n",func.top(), val.top());
  //   func.pop();
  //   val.pop();
  // }
  double cur_index = 0;
  double cur_value = 0;

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
      if(cur_index < end) {
        // (현재 인덱스 - i 값) * 이전 인덱스의 값
        sum += (func.top() - i) * cur_value;
        // 건너뛰도록 i index 설정
        i = func.top();
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
    printf("sum : %0.f\n",sum);
  }

  printf("sum : %0.f\n",sum);

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
