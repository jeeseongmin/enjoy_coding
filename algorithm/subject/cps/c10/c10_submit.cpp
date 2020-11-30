// cmd 에서 안되고, repl.it 에서 가능.
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
// #include <map>

inline size_t key(int i, int j) {return (size_t) i << 32 | (unsigned int) j;}
using namespace std;

int x, y, _x, _y, newx, newy, num, answer=0;
int even=0, odd=0;
vector<int> mark;
vector<int> adj[50000];

void dfs(int key, int depth) {
  if(adj[key].size() == 0) return ;
  if(mark[key] == 0) {
    if(depth == 1) odd++;
    else even++;
    // printf("dfs(%d)\n",key);
    mark[key] = 1;
    int next_depth = (depth == 1) ? 2 : 1;
    // printf("next_depth : %d\n",next_depth);
    for(int i=0; i<adj[key].size(); i++) {
      // if(mark[adj[key][i]] == 0) {
      //   if(depth == 1) odd++;
      //   else even++;
      // }
      // printf("adj[%d][%d] : %d\n",key, i, adj[key][i]);
      dfs(adj[key][i], next_depth);
    }
  }
}


int main() {
  cin >> num;
  unordered_map<size_t, int> index;
  // map<pair<int,int>, int> index;
  // printf("num:%d\n",num);
  for(int i=0; i<num; i++) {
    cin >> x >> y;
    for(int _x=-5; _x<=5; _x++) {
      for(int _y=-5; _y<=5; _y++) {
        newx = x+_x;
        newy = y+_y;
        if(index.find(key(newx, newy)) != index.end()) {
          if(sqrt(pow(newx-x, 2) + pow(newy-y, 2)) <= 5) {
            adj[i].push_back(index[key(newx, newy)]);
            adj[index[key(newx, newy)]].push_back(i);
          }
        }
      }
    }
    index[key(x,y)] = i;
    // index.insert(make_pair(key(x,y),i));
  }
  // for(int i=0; i<num; i++) {
  //   printf("adj[%d] : ",i);
  //   for(int j=0; j<adj[i].size(); j++) {
  //     printf("%d ",adj[i][j]);
  //   }
  //   cout<<endl;
  // }

  // cout << "check!!!" << endl;
  mark.assign(num,0);
  for(int i=0; i<num; i++) {
    odd = 0;
    even = 0;
    // printf("mark[%d] :%d\n",i, mark[i]);
    if(mark[i]==0 && adj[i].size() != 0) {
      dfs(i, 1);
      answer += (even>odd) ? odd : even;
      // printf("odd : %d, event : %d\n",odd, even);
    }
  }
  cout << answer << endl;

}
