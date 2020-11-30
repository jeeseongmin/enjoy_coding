#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int all_person;
  cin >> all_person;
  vector<pair<int,int>> score_xy(all_person, {0,0});
  vector<int> group_score_y;

  for(int i=0; i<all_person; i++) {
    cin >> score_xy[i].first >> score_xy[i].second;
  }

  sort(score_xy.begin(), score_xy.end());

  group_score_y.push_back(score_xy[0].second);
  for(int new_person=1; new_person<all_person; new_person++) {
    int group_pivot=group_score_y.size();
    while(group_pivot>0) {
      if(group_score_y[group_pivot-1] > score_xy[new_person].second) group_pivot--;
      else {
        if(group_pivot==group_score_y.size()) group_score_y.push_back(score_xy[new_person].second);
        break;
      }
    }
    group_score_y.erase(group_score_y.begin()+group_pivot, group_score_y.end()-1);
  }
  printf("%d", group_score_y.size());
}
