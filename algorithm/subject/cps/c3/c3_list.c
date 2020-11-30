#include <stdio.h>

int afuel;
int bfuel;
int tfuel;
int city=0; // 정점
int rel; // 간선

int amax=0;
int bmax=0;
int tmax=0;

typedef struct Node *P_Node;

typedef struct Node {
  P_Node link;
  int vtx;
}Node;

// struct Max {
//   int alpha;
//   int beta;
//   int total;
// };


int main() {
  int afuel;
  int bfuel;
  int tfuel;
  int city;
  int rel;

  GraphList *g;

  scanf("%d %d %d %d %d",&afuel, &bfuel, &tfuel, &city, &rel);
  printf("afuel : %d, bfuel:%d, tfuel:%d, city:%d, rel:%d\n",afuel,bfuel,tfuel,city,rel);
  P_Node graph[city+1];
  int mark[city+1];

  for(int i=0; i<=city; i++) {
    tmp = (P_Node)malloc(sizeof(Node));
    tmp->vtx = y;

    if(graph[i] == st) {
      move = tmp;
      graph[i] = tmp;
    }
    else {
      move->link = tmp;
      move = tmp;
    }
  }


  // g->vertexCnt = city;
  // g->edgeCnt = rel;
  // printf("%d %d\n",g->vertexCnt, g->edgeCnt);
  getchar();

  // for(int i=0; i<rel; i++) {
  //   int tempi;
  //   int tempj;
  //   scanf("%d %d", &tempi, &tempj);
  //   left[tempi] = tempj;
  //   right[tempj] = tempi;
  //   getchar();
  // }

}
