#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int vgs, max_dist, answer=0;
double x, y;

vector<pair<int, int>> pos;

bool compare(pair<int, int>a, pair<int, int>b) {
  if(a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}

int main() {
  double left=-10000, right=10000, _left=0, _right=0;
	cin >> vgs >> max_dist;
  pos.push_back({-20000,-20000});
	for(int i=1; i<=vgs; i++) {
		cin >> x >> y;
    pos.push_back({x, y});
	}
	sort(pos.begin(), pos.end(), compare);

  // for(int i=1; i<=vgs; i++) {
  //   printf("pos[%d] : (%d, %d)\n",i, pos[i].first, pos[i].second);
  // }

  for(int i=1; i<=vgs; i++) {
    // 마을의 위치
    x=pos[i].first;
    y=pos[i].second;
    // 마을의 우물이 생길 수 있는 범위
    // max_range
    _left = x-sqrt(pow(max_dist,2) - pow(y,2));
    _right = x+sqrt(pow(max_dist,2) - pow(y,2));
    // 첫 요소일 경우, left와 right를 변경한다.
    // cur_well_range

    // 여기부터 max_range와 cur_well_range를 비교하기 시작한다.
    // 만약 cur_well_range와 max_range가 겹치는 부분이 생긴다면,
    // max_range의 left ~ cur_well_range의 right가 새로운 cur_well_range가 된다.

    // 만약 cur_well_range와 max_range가 겹치지 않는다면,
    // max_range의 left ~ max_range의 right가 새로운 cur_well_range가 된다.
    // 그리고 answer을 추가한다.

    // printf("left : %f, right : %f\n",_left, _right);
    // 겹치지 않을 때
    if(right < _left) {
      left = _left;
      right = _right;
      // printf("answer[%d]\n",i);
      answer++;
    }
    // 맨 처음, 그니까 left와 riht 사이 범위에 완전히 겹치는 경우 - 맨처음.
    else if(left <= _left && _right <= right) {
      left = _left;
      right = _right;
    }
    // 겹칠 때
    else {
      left = _left;
    }
  }
  answer++;
	cout << answer;
}
