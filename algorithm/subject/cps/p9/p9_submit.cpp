#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  double persons, time, answer=0, meet, x1, x2, v1, v2;
  cin >> persons >> time;
  vector<pair<double, double>> info(persons, {0,0});
  priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> arvPoint_sortList;
  priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> meeting_time;

  vector<double> arrival_point(persons,0);
  vector<double> check(persons, 0);
  for(double i=0; i<persons; i++) {
    cin >> info[i].first >> info[i].second;
    arrival_point[i] = info[i].first + time * info[i].second;
    arvPoint_sortList.push({info[i].first+time*info[i].second, i});
  }

  while(!arvPoint_sortList.empty()){
    if(check[arvPoint_sortList.top().second] == 0) {
      for(double i=0; i<arvPoint_sortList.top().second; i++) {
        if(check[i] == 0 && arvPoint_sortList.top().first <= arrival_point[i]) {
          check[i]=1;
        }
      }
    }
    arvPoint_sortList.pop();
  }

  for(double i=0; i<persons; i++) {
    if(check[i]==0) answer++;
  }
  cout<<answer;
}
