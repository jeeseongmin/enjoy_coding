#include<stdio.h>

double max_value = 10000000000;
double min_value = 0;
int buildings;
int limit;
double max_point;
double min_point;
double dist_max;
int max_people=0;

void dq(double *building_point, int *building_people, int *mark, int left, int right) {
  int count_people_max = 0;
  int mid = left + (right-left)/2;
  if(right-left == 1) {
    if(mark[left]==1) {
      if(building_people[left]>max_people) max_people=building_people[left];
      if(right==buildings-1) {
        if(building_people[buildings-1]>max_people) max_people=building_people[buildings-1];
      }
      return ;
    }
    else {
      count_people_max=building_people[left];
      dist_max = (building_point[left]+limit*2<max_value) ? building_point[left]+limit*2 : max_point;
      for(int j=left; j<buildings; j++) {
        if(left==j) continue;
        if(building_point[left] <= building_point[j] && building_point[j] <= dist_max) {
          count_people_max+=building_people[j];
        }
        else {
          break;
        }
      }
      if(right==buildings-1) {
        if(building_point[left] <= building_point[right] && building_point[right] <= dist_max) {
          count_people_max+=building_people[right];
        }
        else {
          if(building_people[buildings-1]>max_people) max_people=building_people[buildings-1];
        }
      }
      if(max_people<count_people_max) max_people = count_people_max;
      return ;
    }

  }
  else {
    dq(building_point, building_people, mark, left, mid);
    dq(building_point, building_people, mark, mid, right);
  }
}

void qsorting(double *building_point, int *building_people, int left, int right) {
  if(left >= right) {
    return;
  }
  int key = left;
  int i=left+1;
  int j=right;
  int temp;

  while(i<=j) {
    while(i <= right && building_point[i] <= building_point[key]) {
      i++;
    }
    while(j > left && building_point[j] >= building_point[key]) {
      j--;
    }
    if(i > j) {
      temp = building_point[j];
      building_point[j] = building_point[key];
      building_point[key] = temp;
      temp = building_people[j];
      building_people[j] = building_people[key];
      building_people[key] = temp;
    } else {
      temp = building_point[i];
      building_point[i] = building_point[j];
      building_point[j] = temp;
      temp = building_people[i];
      building_people[i] = building_people[j];
      building_people[j] = temp;
    }
  }
  qsorting(building_point, building_people, left, j - 1);
  qsorting(building_point, building_people, j + 1, right);
}

int main() {
  scanf("%d %d",&buildings, &limit);
  int building_people[buildings];
  double building_point[buildings];
  int between[buildings];
  int mark[buildings];

  getchar();

  max_point = min_value;
  min_point = max_value;
  for(int i=0; i<buildings; i++) {
    scanf("%d %lf",&building_people[i], &building_point[i]);
    max_point = (max_point<building_point[i]) ? building_point[i] : max_point;
    min_point = (min_point>building_point[i]) ? building_point[i] : min_point;
    getchar();
  }
  qsorting(building_point, building_people, 0, buildings-1);
  for(int i=0; i<buildings; i++) {
    mark[i] = 0;
  }
  for(int i=buildings-1; i>0; i--) {
    between[i] = building_point[i]-building_point[i-1];
    if(between[i]>2*limit) mark[i-1] = 1;
  }
  between[0] = 0;

  dq(building_point, building_people, mark, 0, buildings-1);

  printf("%d\n",max_people);
  return 0;
}
