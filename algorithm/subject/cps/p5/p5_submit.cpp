#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
int main() {
  int _len1;
  int _len2;
  int start;
  int end;
  stack<int> s1;
  stack<int> v1;
  stack<int> s2;
  stack<int> v2;

  scanf("%d",&_len1);
  for(int i=0; i<_len1; i++) {
    int temp_index;
    int temp_value;
    scanf("%d %d",&temp_index, &temp_value);
    s1.push(temp_index);
    v1.push(temp_value);
  }
  scanf("%d",&_len2);
  for(int i=0; i<_len2; i++) {
    int temp_index;
    int temp_value;
    scanf("%d %d",&temp_index, &temp_value);
    s2.push(temp_index);
    v2.push(temp_value);
  }
  scanf("%d %d",&start, &end);
  int sum = 0;
  int cnt = 0;
  int flag = 0;
  stack <int> func;
  stack <int> val;
  int first = 0;
  int max_index=0;
  int max_value=0;

  while(!(s1.empty() && s2.empty())) {
    if(s1.size() == 0) {
      if(s2.top() < func.top()) {
        func.push(s2.top());
        val.push(v2.top());
      }
      s2.pop(); v2.pop();
    }
    else if(s2.size() == 0) {
      if(s1.top() < func.top()) {
        func.push(s1.top());
        val.push(v1.top());
      }
      s1.pop(); v1.pop();
    }
    else {
      if(v1.top() > v2.top()) {
        if(s1.top() > s2.top()) {
          func.push(s1.top());
          val.push(v1.top());
          s1.pop(); v1.pop();
        }
        else {
          func.push(s1.top());
          val.push(v1.top());
          s2.pop();
          v2.pop();
        }
      }
      else if(v2.top() > v1.top()) {
        if(s2.top() > s1.top()) {
          func.push(s2.top());
          val.push(v2.top());
          s2.pop(); v2.pop();
        }
        else {
          func.push(s2.top());
          val.push(v2.top());
          s2.pop(); v2.pop();
          s1.pop(); v1.pop();
        }
      }
      else {
        if(s1.top() <= s2.top()) {
          func.push(s1.top());
          val.push(v1.top());
          s1.pop(); v1.pop();
          s2.pop(); v2.pop();
        }
        else {
          func.push(s2.top());
          val.push(v2.top());
          s2.pop(); v2.pop();
          s1.pop(); v1.pop();
        }
      }
    }
    if(first == 0) {
      max_index = func.top();
      max_value = val.top();
      first++;
    }
  }

  int cur_index = 0;
  int cur_value = 0;
  if(end <= func.top()) {
    if(end == func.top()) sum += val.top()%10007;
    printf("%d\n",sum);
    return 0;
  }
  else if(max_index <= start) {
    sum += ((end+1 - start)%10007) * max_value%10007;
    printf("%d\n",sum%10007);
    return 0;
  }
  else if(start <= func.top()) {
    if(start == func.top()) ;
    else {
      start = func.top();
    }
  }
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
      sum += ((end+1 - start)%10007) * cur_value%10007;
      flag = 1;
      printf("%d\n",sum%10007);
      return 0;
    }
    else if(end == func.top()) {
      sum += ((end - start)%10007) * cur_value%10007;
      sum += val.top()%10007;
      flag = 1;
      printf("%d\n",sum%10007);
      return 0;
    }
    else {
      if(cur_value != 0) {
        sum += ((func.top() - start)%10007) * cur_value%10007;
        start = func.top();
      }
    }
  }


  for(int i= start; i<=end;) {
    if(start == end) {
      sum += val.top()%10007;
      flag = 1;
      break;
    }
    if(func.size() == 1) {
      sum += ((end+1 - i)%10007) * val.top()%10007;
      func.pop(); val.pop();
      flag = 1;
      break;
    }
    else {
      cur_index = func.top();
      cur_value = val.top();
      func.pop(); val.pop();
      if(func.top() < end) {
        sum += ((func.top() - i)%10007) * cur_value%10007;
        sum = sum%10007;
        i = func.top();
      }
      else if(func.top() == end) {
        sum += ((end - cur_index)%10007) * cur_value%10007;
        sum += val.top()%10007;
        flag = 1;
        break;
      }
      else if(end < func.top()){
        sum += ((end+1 - cur_index)%10007) * cur_value%10007;
        flag = 1;
        break;
      }
    }
    if(flag == 1) break;
  }
  printf("%d\n",sum%10007);
  return 0;
}
