#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int main() {
  int _len1;
  int _len2;

  scanf("%d",&_len1);
  stack<int> _func1;
  stack<int> _value1;
  for(int i =0; i<_len1; i++) {
    int temp_index;
    int temp_value;
    scanf("%d %d",&temp_index, &temp_value);
    _func1.push(temp_index);
    _value1.push(temp_value);
  }

  scanf("%d",&_len2);
  stack<int> _func2;
  stack<int> _value2;
  for(int i =0; i<_len2; i++) {
    int temp_index;
    int temp_value;
    scanf("%d %d",&temp_index, &temp_value);
    _func2.push(temp_index);
    _value2.push(temp_value);
  }

  stack<int> _func3;
  stack<int> _value3;

  while(1) {
    int _max = 0;
    int _index = 0;
    int _flag = 0;
    if(!_func1.empty() && _func2.empty()) {
      _func3.push(_func1.top());
      _value3.push(_value1.top());
      _func1.pop();
      _value1.pop();
    }
    else if(_func1.empty() && !_func2.empty()) {
      _func3.push(_func2.top());
      _value3.push(_value2.top());
      _func2.pop();
      _value2.pop();
    }
    else if(_func1.empty() && _func2.empty()) {
      int size = _func3.size();
      printf("_func3_size : %d\n",size);
      break;
    }
    else {
      // 만약 두 stack index가 똑같을 떄.
      if(_func1.top() == _func2.top()) {
        // 두 stack value가 똑같을 때.
        if(_value1.top() == _value2.top()) {
          _func3.push(_func1.top());
          _value3.push(_value3.top());
          _func1.pop();
          _value1.pop();
          _func2.pop();
          _value2.pop();
        }
        // 두 stack value가 다를 떄.
        else {
          if(_value1.top() > _value2.top()) {
            _func3.push(_func1.top());
            _value3.push(_value1.top());
          }
          else {
            _func3.push(_func2.top());
            _value3.push(_value2.top());
          }
          _func1.pop();
          _value1.pop();
          _func2.pop();
          _value2.pop();
        }
      }
      // 만약 두 stack index가 다를 때.
      else {
        // func1의 index가 더 클 때
        // func1의 것을 집어넣는다.
        if(_func1.top() > _func2.top()) {
          _func3.push(_func1.top());
          _value3.push(_value1.top());
          _func1.pop();
          _value1.pop();
        }
        // func2의 index가 더 클 때
        // func2의 것을 집어넣는다.
        else {
          _func3.push(_func2.top());
          _value3.push(_value2.top());
          _func2.pop();
          _value2.pop();
        }
      }
    }
  }
  while(!_func3.empty()) {
    printf("%d %d\n",_func3.top(), _value3.top());
    _func3.pop();
    _value3.pop();
  }
  // double count = 0;
  // for(double i = 0; i<2000000000; i++) {
  //   count++;
  // }
  // printf("cnt : %0.f\n",count);
  return 0;
}
