#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;
int goal, rel, start, dist[3][40001];

void cal_distance() {
  for(int i=0; i<3; i++) {
    if(i == 0) start = goal;
    else start = i;
    int from = i;
    // printf("from : %d, index : %d\n",from, start);
    queue<int> buf;
    buf.push(start);
    dist[from][start] = 1;
    while(!buf.empty()) {
      int front = buf.front();
      buf.pop();
      int position = dist[from][front];
      vector<int> &adj_temp = adj_list[front];
      for(int j = 0; j < adj_temp.size(); j++) {
        int next = adj_temp[j];
        // printf("dist[%d][%d] : %d\n",from,next, dist[from][next]);
        if(dist[from][next]) continue;
        dist[from][next] = position + 1;
        buf.push(adj_temp[j]);
      }
    }
  }
}

int main() {
  int afuel, bfuel, tfuel, x, y;
  scanf("%d %d %d %d %d", &afuel, &bfuel, &tfuel, &goal, &rel);
  adj_list = vector<vector<int>>(goal+1);
  for(int i =0; i<rel; i++) {
    scanf("%d %d", &x, &y);
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }
  cal_distance();
  int answer = afuel * (dist[1][goal] - 1) + bfuel * (dist[2][goal] - 1);
  for(int i =1; i<=goal; i++) {
    if(dist[0][i] && dist[1][i] && dist[2][i]) {
      int fuel = tfuel * (dist[0][i] - 1) + afuel * (dist[1][i] - 1) +  bfuel * (dist[2][i] - 1);
      if(fuel < answer) answer = fuel;
    }
  }
  printf("%d\n",answer);
}
