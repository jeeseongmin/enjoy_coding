#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int answer = 1;
int num, pairs, first, second, flag;

void bfs(int first, int second, vector<int> graph[], vector<int> &medicine) {
  // printf("bfs : first %d, second %d\n",first, second);
  priority_queue<int> q;
  vector<int> check;
  check.assign(num+1, 0);
  q.push(first);
  medicine[first] = (medicine[first]-1) * -1;
  flag = 0;

  while(!q.empty()) {
    int tmp = q.top();
    check[tmp] = 1;
    q.pop();
    // printf("tmp : ");
    // printf(" %d", tmp);
    // cout<< endl;
    if(tmp == second) {
      cout << answer;
      exit(0);
    }
    // check에 문제가 있는 것 같음.
    for(int i=0; i<graph[tmp].size(); i++) {
      if(check[graph[tmp][i]] == 0) {
        // printf("----- %d\n",graph[tmp][i]);
        // 처음에는 그냥 q에 안넣고, 두번째 항목에 나오면 break;
        if(tmp != first || graph[tmp][i] != second) {
          medicine[graph[tmp][i]] = (medicine[graph[tmp][i]]-1) * -1;
          q.push(graph[tmp][i]);
          check[graph[tmp][i]] = 1;
          // printf("check[%d] = %d\n",graph[tmp][i], check[graph[tmp][i]]);
        }
      }
    }
  }
  // printf("first : medicine[%d] = %d\n",first, medicine[first]);
  // printf("second : medicine[%d] = %d\n",second, medicine[second]);
}


int main() {
  cin >> num >> pairs;
  vector<int> medicine;
  vector<int> graph[num+1];
  medicine.assign(num+1, 1);
  // cout << "num : "<<num << ", pairs : " << pairs << endl;

  for(int i=0; i<pairs; i++) {
    cin >> first >> second;
    // 두 알의 state가 같다면 바꿔야되고
    graph[first].push_back(second);
    graph[second].push_back(first);
    // cout << "first : " << first << ", second : " << second << endl;
    // 만약 같다면 첫번째 약의 flag를 변경한다.
    // printf("medicine[%d] = %d, medicine[%d] = %d\n",first, medicine[first], second, medicine[second]);
    if(medicine[first] == medicine[second]) {
      // printf("before medicine[%d] = %d\n",first, medicine[first]);
      // medicine[first] = (medicine[first]-1) * -1;
      // 그리고나서 첫번째 약의 flag가 변경되었기 때문에 첫번째 약과 관련된 모든 항목을 집어넣는다.
      // bfs를 진행해야 한다.
      // printf("after medicine[%d] = %d\n",first, medicine[first]);
      bfs(first, second, graph, medicine);
      // cout<<endl;
      // cout<<"result : " << endl;
      // for(int x=1; x<=num; x++) {
      //   printf("medicine[%d] : %d\n",x, medicine[x]);
      // }
      // cout<<endl;


    }
    else {
      // printf("diffrent!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    answer++;
  }
  return 0;
}
