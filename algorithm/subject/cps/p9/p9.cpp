#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  double persons, time, answer=0;
  cin >> persons >> time;
  vector<pair<double, double>> info(persons, {0,0});
  priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> arvPoint_sortList;
  vector<double> arrival_point(persons,0);
  vector<double> isGrouped(persons, 0);

  for(double i=0; i<persons; i++) {
    cin >> info[i].first >> info[i].second;
    arrival_point[i] = info[i].first + time * info[i].second;
    arvPoint_sortList.push({info[i].first+time*info[i].second, i});
  }

  while(!arvPoint_sortList.empty()){
    int current = arvPoint_sortList.top().second;
    if(isGrouped[current] == 0) {
      for(int previous=0; previous<current; previous++) {
        if(isGrouped[previous] == 0 && arrival_point[current] <= arrival_point[previous]) {
          isGrouped[previous]=1;
        }
      }
    }
    arvPoint_sortList.pop();
  }

  for(int i=0; i<persons; i++) {
    if(isGrouped[i]==0) answer++;
  }
  cout<<answer;
}
