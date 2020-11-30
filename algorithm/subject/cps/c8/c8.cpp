#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double inter_well_min=-10000, inter_well_max=10000, cur_well_min, cur_well_max, x, y;
int village, dist_max, wells=0;

vector<pair<int, int>> location;

bool compare(pair<int, int>a, pair<int, int>b) {
  if(a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}

int main() {
	cin >> village >> dist_max;
	for(int i=0; i<village; i++) {
		cin >> x >> y;
    location.push_back({x, y});
	}
	sort(location.begin(), location.end(), compare);

  for(int i=0; i<village; i++) {
    x=location[i].first;
    y=location[i].second;

    cur_well_min = x-sqrt(pow(dist_max,2) - pow(y,2));
    cur_well_max = x+sqrt(pow(dist_max,2) - pow(y,2));

    if(inter_well_max < cur_well_min) {
      inter_well_min = cur_well_min;
      inter_well_max = cur_well_max;
      wells++;
    }
    else if(inter_well_min <= cur_well_min && cur_well_max <= inter_well_max) {
      inter_well_min = cur_well_min;
      inter_well_max = cur_well_max;
    }
    else {
      inter_well_min = cur_well_min;
    }
  }
  wells++;
	cout << wells;
}
