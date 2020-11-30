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
  printf("search(%d)\n",goal);
  check.assign(total+2,0);
  _day.clear();
  _day.assign(day.begin(), day.end());
  for(iter=info.begin(); iter!=info.end(); iter++) {
    // 옮길게 있다는 의미
    if(iter->first > goal && check[iter->second] == 0) {
      // 현재 위치를 기준으로 모두 오른쪽 정렬.
      // 옮기지 못한다면 실패
      if(!moveRight(iter->second, goal)) {
        return 0;
      }
      else {
        cout<<endl;
        cout<< "check!" << endl;
        for(int i=1; i<=total; i++) {
          printf("_day[%d] : %d\n",i, _day[i]);
        }
        check[iter->second] = 1;
        printf("success!!!\n");
      }
    }
    // 더이상 옮길게 없다는 의미
    else {
      return 1;
    }
  }
  // 정상적으로 종료
  return 1;
}
// 현재 index의 것만 limit 범위까지 채워넣기.
int move(int key, int goal) {
  printf("move(%d, %d)\n",key, goal);
  for(int i=key+limit; i>key; i--) {
    check[i] = 1;
    // 범위내에서만
    if(i<=total) {
      // 옮길 곳이 비어있다면
      if(_day[i] < goal) {
        // 옮길 수 있는 양
        int rest = goal - _day[i];
        // 옮길 수 있는 양보다 많을 때(정상)
        if(_day[key] > rest) {
          _day[key] -= rest;
          _day[i] += rest;
        }
        // 옮길 수 있는 양보다 적을 때
        // 그것만 옮기고 종료한다.
        else {
          _day[i] += _day[key];
          _day[key] = 0;
          return 1;
        }
      }
    }
    // 다 옮겼다면 정상 종료
    if(_day[key] == 0) return 1;
  }
  // 만약 정렬에 실패했다면 비정상 종료
  if(_day[key] > goal) return 0;
  else return 1;
}
// 최대 limit까지 우측정렬하는 함수
// key는 index, goal은 하루에 끝내야 하는 일의 양
int moveRight(int key, int goal) {
  printf("moveRight(%d, %d)\n",key, goal);
  int _end = total;
  // 맨 오른쪽부터 옮기기 시작.
  for(int i=_end; i>=key; i--) {
    if(!move(i, goal)) {
      return 0;
    }
    else {
      printf("* move(%d, %d)\n",i, goal);
    }
  }
  // 실패
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
    // sum+=day[i];
    start = (start > day[i]) ? day[i] : start;
    last = (last<day[i]) ? day[i] : last;
    max_val = last;
    // printf("day[%d] : %d\n",i, day[i]);
  }
  // if((double)sum/(double)total > sum/total) start = sum/total + 1;
  // else start = sum/total;
  printf("start : %d, end : %d\n", start, last);

  while(start <= last) {
    int avg = (start+last) / 2;
    // 가능하기 때문에 범위를 더 줄여본다.
    if(search(avg)) {
      printf("search(%d)\n",avg);
      // answer = (answer > avg) ? avg : answer;
      answer = avg;
      last = avg-1;
    }
    // 불가능하기 때문에 범위를 더 늘려본다.
    else {
      start = avg+1;
    }
    for(int i=1; i<=total; i++) {
      printf("_day[%d] : %d\n",i, _day[i]);
    }
    cout << endl;
  }

  cout << endl;
  printf("value / index\n");
  for(iter=info.begin(); iter != info.end(); iter++) {
    printf("%d -> %d\n",iter->first, iter->second);
  }
  if(answer == 100000) answer = max_val;
  cout << answer;
  exit(0);
  return 0;
}
