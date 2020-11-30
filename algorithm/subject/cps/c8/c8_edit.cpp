#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
  return a.first < b.first;
}

int vgs, limit, answer=0;
double x, y;
vector<pair<int, int>> pos;
vector<int> check;

// start와 end가 의미하는 바는, 구간의 index를 의미.
void function(int start, int end) {
  // printf("start : %d, end : %d\n", start, end);
	double _x, _y;
  // 인덱스가 같다는 말은, 우물이 한개 적용된다는 말.
	if(start == end) {
      // printf("answer!! - start : %d\n",start);
    // if(check[start] == 0) {
      // printf("equls!!!!!!\n");
      answer++;
      check[start] = 1;
    // }
	}
  else {
    x = pos[start].first;
    y = pos[start].second;
    _y = 0;
    _x = abs(0-x - sqrt(pow(limit, 2)-pow(y, 2)));
    if(y==0) _x=x;
    answer++;
    // printf("answer : %d - (%f, %f)\n",answer, _x, _y);
    for(int i=start+1; i<=end; i++) {
      x=pos[i].first;
      y=pos[i].second;
      // printf("i:%d, x:%f, y:%f\n",i, x, y);
      if(sqrt(pow(x-_x, 2)+pow(y-_y, 2)) < limit) {
        // check[i] = 1;
        // printf("continue\n");
        continue;
      }
      else {
        // printf("this\n");
        x=pos[i].first;
        y=pos[i].second;
        _y=0;
        _x = abs(0-x - sqrt(pow(limit, 2)-pow(y, 2)));
        if(y==0) _x=x;
        answer++;
        // printf("answer : %d - (%f, %f)\n",answer, _x, _y);
      }
    }
  }
}

int main() {
	cin >> vgs >> limit;
  vector<int> minus(vgs+1, 0);
  check.assign(vgs+1, 0);

  pos.push_back({-20001,-1});
	for(int i=1; i<=vgs; i++) {
		cin >> x >> y;
    pos.push_back({x, y});
	}
	// x좌표 별로 오름차순 정렬.
	sort(pos.begin(), pos.end(), compare);

  // int _x, _y;
  for(int i=1; i<=vgs; i++) {
    // printf("pos[%d] : (%d, %d)\n",i, pos[i].first, pos[i].second);
  }
  for(int i=1; i<vgs; i++) {
    minus[i] = pos[i+1].first - pos[i].first;
  }

	// x좌표들의 차이가 d 이상인 경우.
	// 구간을 나누기 시작한다. (start ~ end)
	int start=1, end;
	for(int i=1; i<vgs; i++) {
    // 둘 사이의 거리가 limit 이상이면 만날 수가 없기 때문에 함수에 들어가게 된다.
    if(minus[i] >= limit && check[i] == 0) {
			end = i;
			function(start, end);
			start = i+1;
		}
	}
	// 마지막 요소를 포함한 구간.
	end = vgs;
	function(start, end);

	cout << answer;
}
