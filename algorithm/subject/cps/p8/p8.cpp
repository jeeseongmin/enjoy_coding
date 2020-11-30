#include <iostream>
#include <vector>
#include <map>
using namespace std;

int total, limit, lists, temp;
int start=100000, last=0, sum=0, max_val = 0, answer=100000;

vector<int> day;
vector<int> _day;
multimap<int, int, greater<int>> info;
multimap<int, int, greater<int>>::iterator iter;
vector<int> check;
int moveRight(int key, int goal);
int move(int key, int goal);

int search(int goal) {
  check.assign(total+2,0);
  _day.clear();
  _day.assign(day.begin(), day.end());
  for(iter=info.begin(); iter!=info.end(); iter++) {
    if(iter->first > goal && check[iter->second] == 0) {
      if(!moveRight(iter->second, goal)) {
        return 0;
      }
      else {
        check[iter->second] = 1;
      }
    }
    else {
      return 1;
    }
  }
  return 1;
}
int move(int key, int goal) {
  for(int i=key+limit; i>key; i--) {
    check[i] = 1;
    if(i<=total) {
      if(_day[i] < goal) {
        int rest = goal - _day[i];
        if(_day[key] > rest) {
          _day[key] -= rest;
          _day[i] += rest;
        }
        else {
          _day[i] += _day[key];
          _day[key] = 0;
          return 1;
        }
      }
    }
    if(_day[key] == 0) return 1;
  }
  if(_day[key] > goal) return 0;
  else return 1;
}
int moveRight(int key, int goal) {
  int _end = total;
  for(int i=_end; i>=key; i--) {
    if(!move(i, goal)) {
      return 0;
    }
    else {
    }
  }
  if(_day[key] > goal) return 0;
  else return 1;
}


int main() {
  cin >> total >> limit >> lists;
  day.assign(total+2,0);
  check.assign(total+2,0);
  for(int i =0; i<lists; i++) {
    cin >> temp;
    day[temp]++;
  }
  for(int i=1; i<=total; i++) {
    info.insert(pair<int, int>(day[i], i));
    start = (start > day[i]) ? day[i] : start;
    last = (last<day[i]) ? day[i] : last;
    max_val = last;
  }
  while(start <= last) {
    int avg = (start+last) / 2;
    if(search(avg)) {
      answer = avg;
      last = avg-1;
    }
    else {
      start = avg+1;
    }
  }
  if(answer == 100000) answer = max_val;
  cout << answer;
  exit(0);
  return 0;
}
