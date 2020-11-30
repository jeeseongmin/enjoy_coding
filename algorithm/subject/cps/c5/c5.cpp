#include <iostream>
#include <map>
#include <cmath>
#define MAX_VAL 1000000001

using namespace std;
int main() {
  int total;
  cin >> total;
  double balloon;
  double _radius;

  map<double, double> info;
  map<double, double>::iterator iter;
  multimap<double, double, greater<double>> pre_info;
  multimap<double, double, greater<double>>::iterator mul_iter;

  for(int i =0; i<total; i++) {
    cin >> balloon;
    cin >> _radius;
    info.insert(pair<double, double>(balloon, _radius));
  }

  for(iter = info.begin(); iter != info.end(); iter++) {
    double cur_x = iter->first;
    double cur_y = iter->second;
    double cur_leftX = cur_x - cur_y;
    if(iter == info.begin()) {
      pre_info.insert(pair<double, double>(cur_x+cur_y, cur_x));
    }
    else {
      double min = MAX_VAL;
      double temp_min = MAX_VAL;
      for(mul_iter = pre_info.begin(); mul_iter != pre_info.end(); mul_iter++) {
        double last_x = mul_iter->second;
        double last_rightX = mul_iter->first;
        double last_y = mul_iter->first - last_x;
        if(pre_info.begin()->first <= cur_leftX) {
          min = cur_y;
          break;
        }
        else {
          if(last_rightX > cur_leftX) {
            temp_min = ((pow(cur_x-last_x,2)/(4*last_y))<cur_y) ? (pow(cur_x-last_x,2)/(4*last_y)) : cur_y;
            if(temp_min < min) {
              min = temp_min;
            }
          }
          else {
            break;
          }
        }
      }
      pre_info.insert(pair<double, double>(cur_x+min, cur_x));
      info[cur_x] = min;
    }
  }
  cout << fixed;
  cout.precision(3);
  for(iter = info.begin(); iter != info.end(); iter++) {
    cout <<iter->second<<endl;
  }
  return 0;
}
