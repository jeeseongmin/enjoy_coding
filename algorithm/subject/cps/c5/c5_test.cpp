#include <iostream>
#include <map>
#include <cmath>

using namespace std;
int main() {
  int total;
  cin >> total;
  double balloon;
  double init_radius;
  map<double, double> init_info;
  for(int i =0; i<total; i++) {
    cin >> balloon;
    cin >> init_radius;
    init_info.insert(pair<double, double>(balloon, init_radius));
  }
  // 지금은 일단 index, radius 형태로 저장이 되어있다.
  map<double, double>::iterator iter;
  map<double, double>::iterator before_iter;
  multimap<double, double, greater<double>> sort_right;
  multimap<double, double, greater<double>>::iterator _iter;
  // for(iter = init_info.begin(); iter != init_info.end(); iter++) {
  //   cout << "[" << iter->first << ", " << iter->second << "]" << " " ;
  // }
  // 여기서부터 앞부분 index부터 풍선을 만들어나가기 시작한다.
  // 이때의 multimap sort_info는 radius가 key가 되고, index가 value가 된다. (radius가 정렬되어야 하기 때문에)
  for(iter = init_info.begin(); iter != init_info.end(); iter++) {
    double cur_x = iter->first;
    double cur_y = iter->second; // radius를 의미.
    double cur_left = cur_x - cur_y;
    // 첫 요소일 때는 그냥 집어넣는다.
    if(iter == init_info.begin()) {
      sort_right.insert(pair<double, double>(cur_x+cur_y, cur_x));
    }
    // 두번째 요소부터는
    // sort_right의 index_right, 즉 iter->first가 높은 곳부터 검사를 하기 시작한다. 내림차순으로 자동 정렬 되어있음.
    else {
      double min =1000000001;
      double temp_min = 1000000001;
      for(_iter = sort_right.begin(); _iter != sort_right.end(); _iter++) {
        double last_x = _iter->second;
        double last_right = _iter->first; // = x + radius
        double last_y = _iter->first - last_x;
        // 절대 겹치지 않으므로 현재 반지름 그대로 설정 후 멈춘다.
        if(sort_right.begin()->first <= cur_left) {
          min = cur_y;
          break;
        }
        else {
          // 높은 경우에 반지름의 최솟값을 계속 구한다.
          if(last_right > cur_left) {
            temp_min = ((pow(cur_x-last_x,2)/(4*last_y))<cur_y) ? (pow(cur_x-last_x,2)/(4*last_y)) : cur_y;
            if(temp_min < min) {
              min = temp_min;
            }
          }
          // 같거나 작은 경우이기 때문에 이 이상은 겹치지 않는다.
          else {
            break;
          }
        }
      }
      sort_right.insert(pair<double, double>(cur_x+min, cur_x));
      // 마지막에 init_info의 현재 인덱스의 radius를 최종적으로 업데이트해줌.
      init_info[cur_x] = min;
    }
  }

  // for(iter = init_info.begin(); iter != init_info.end(); iter++) {
  //   cout << "[" << iter->first << ", " << iter->second << "]" << " " ;
  // }
  cout << fixed;
  cout.precision(3);
  for(iter = init_info.begin(); iter != init_info.end(); iter++) {
    cout <<iter->second<<endl;
  }

}
