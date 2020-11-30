#include<stdio.h>
#include<stdlib.h>

int main() {
  float max_value = 10000000000;
  float min_value = 0;
  int buildings;
  int limit;
  int *building_people;
  float *building_point;
  scanf("%d %d",&buildings, &limit);
  // printf("result : %d %0.f\n",buildings, limit);
  getchar();

  building_people=malloc(sizeof(int *) * buildings);
  building_point=malloc(sizeof(float *) * buildings);
  // printf("buildings : %d\n",buildings);
  for(int i=0; i<buildings; i++) {
    building_people[i] = 0;
    building_point[i] = 0;
  }
  // 값 입력 구간
  //[0]에 있는 것이 building의 point, [1]에 있는 것이 people
  float max_point = min_value;
  float min_point = max_value;
  for(int i=0; i<buildings; i++) {
    scanf("%d %f",&building_people[i], &building_point[i]);
    max_point = (max_point<building_point[i]) ? building_point[i] : max_point;
    min_point = (min_point>building_point[i]) ? building_point[i] : min_point;
    getchar();
  }
  // printf("after: \n");
  // for(int i=0; i<buildings; i++) {
  //   printf("%0.f %d",building_point[i], building_people[i]);
  //   printf("\n");
  // }
  float dist_min;
  float dist_max;
  int count_people_min;
  int count_people_max;
  int max_people=0;

  for(int i=0; i<buildings; i++) {
    // printf("i:%d\n",i);
    count_people_min=building_people[i];
    count_people_max=building_people[i];
    dist_min = (building_point[i]-(float)limit*2 > 0) ? building_point[i]-(float)limit*2 : 0;
    dist_max = (building_point[i]+(float)limit*2<max_value) ? building_point[i]+(float)limit*2 : max_value;
    // printf("%d - dist_min: %0.f, dist_max: %0.f\n",i,dist_min, dist_max);
    // 크다고 할 때
    for(int j=0; j<buildings; j++) {
      if(i !=j) {
        if(dist_min <= building_point[j] && building_point[j] <= building_point[i]) {
          // printf("j:%d\n",j);
          count_people_min+=building_people[j];
        }
        if(building_point[i] <= building_point[j] && building_point[j] <= dist_max) {
          // printf("j:%d\n",j);
          count_people_max+=building_people[j];
        }
      }
    }
    if(max_people<count_people_min) max_people = count_people_min;
    if(max_people<count_people_max) max_people = count_people_max;
  }

  printf("%d\n",max_people);
  free(building_people);
  free(building_point);
  return 0;
}
