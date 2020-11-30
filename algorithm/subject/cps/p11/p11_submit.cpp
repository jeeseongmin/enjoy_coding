#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
inline void end_game() {cout<<0; exit(0);}

bool front_compare(const pair<string, int>& a, const pair<string, int>& b) {
  if(a.first.front() == b.first.front()) {
    if(a.first.front() == a.first.back() && b.first.front() != b.first.back()) {
      return true;
    }
    else if(a.first.front() != a.first.back() && b.first.front() == b.first.back()) {
      return false;
    }
    else {
      return a.first < b.first;
    }
  }else {
    return a.first.front() < b.first.front();
  }
}

bool back_compare(const pair<string, int>& a, const pair<string, int>& b) {
  if(a.first.back() == b.first.back()) {
    return a.first < b.first;
  }else {
    return a.first.back() < b.first.back();
  }
}

int main() {
  int num, flag = 0;
  string str = "";
  cin >> num;
  vector<pair<string,int>> _front;
  vector<pair<string,int>> _back;
  vector<string> data;
  vector<string> answer;
  stack<string> temp;
  vector<int> check(num, 0);
  vector<int> front_apb[26];
  vector<int> front_adj[num];
  vector<int> back_apb[26];
  vector<int> back_adj[num];


  for(int i=0; i<num; i++) {
    cin >> str;
    // data.push_back(str);
    _front.push_back({str, i});
    _back.push_back({str,i});
  }

  // for(int i=0; i<_front.size(); i++) {
  //   cout << _front[i] << endl;
  // }
  // cout << endl;
  // sort(data.begin(), data.end(), front_compare);
  sort(_front.begin(), _front.end(), front_compare);
  // sort(_back.begin(), _back.end(), back_compare);

  cout << "front" << endl;
  for(int i=0; i<_front.size(); i++) {
    cout << _front[i].first << endl;
    front_apb[_front[i].first.front() - 97].push_back(i);
    back_apb[_front[i].first.back() - 97].push_back(i);
  }
  cout << endl;
  for(int i=0; i<26; i++) {
    cout << (char)(i+97) << " - ";
    for(int j=0; j<front_apb[i].size(); j++) {
      cout << front_apb[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for(int i=0; i<_front.size(); i++) {
    printf("i : %d\n",i);
    // 현재 문자의 뒷문자와 이어지는 목록 구성
    cout << front_apb[_front[i].first.back() - 97].size() << endl;
    for(int j=0; j<front_apb[_front[i].first.back() - 97].size(); j++) {
      if(i != front_apb[_front[i].first.back() - 97][j]) {
        cout << front_apb[_front[i].first.back() - 97][j] << endl;
        back_adj[i].push_back(front_apb[_front[i].first.back()-97][j]);
      }
    }
    cout << "check??"<<endl;
    // 현재 문자의 앞문자와 이어지는 목록 구성
    for(int j=0; j<back_apb[_front[i].first.front() - 97].size(); j++) {
      if(i != back_apb[_front[i].first.front() - 97][j]) {
        cout << back_apb[_front[i].first.front() - 97][j] << endl;
        front_adj[i].push_back(back_apb[_front[i].first.front()-97][j]);
      }
    }
  }
  cout << "front!!" << endl;
  for(int i=0; i<26; i++) {
    printf("size : %d\n", front_adj[i].size());
    cout << "i : " << (char)(i+97) << " - ";
    for(int j=0; j<front_adj[i].size(); j++) {
      cout << front_adj[i][j] << " ";
    }
    cout << endl;
  }

  cout << "back!!" << endl;
  for(int i=0; i<26; i++) {
    cout << "i : " << (char)(i+97) << " - ";
    for(int j=0; j<back_adj[i].size(); j++) {
      cout << back_adj[i][j] << " ";
    }
    cout << endl;
  }


  // cout << "back" << endl;
  // for(int i=0; i<_back.size(); i++) {
  //   cout << _back[i].first << endl;
  // }
  // cout << endl;

  // for(int i=0; i<_back.size(); i++) {
  //   if(check[_back[i].second] == 0) {
  //     if(answer.size() != 0 && answer.size() != num-1) {
  //       if(answer[answer.size()-1].back() != _front[i].first.front()) {
  //         // end_game();
  //         break;
  //       }
  //       else {
  //         answer.push_back(_back[i].first);
  //         check[_back[i].second] = 1;
  //       }
  //     }
  //     else if(answer.size() == 0) {
  //       answer.push_back(_back[i].first);
  //       check[_back[i].second] = 1;
  //     }
  //
  //
  //     for(int j=0; j<_front.size(); j++) {
  //       if(check[_front[j].second] == 0) {
  //         if(answer[answer.size()-1].back() == _front[j].first.front()) {
  //           check[_front[j].second] = 1;
  //           answer.push_back(_front[j].first);
  //           break;
  //         }
  //         else continue;
  //         // end_game();
  //       }
  //     }
  //     if(answer.size() == num) break;
  //   }
  // }

  if(answer.size() == num) {
    for(int i=0; i<answer.size(); i++) {
      cout << answer[i] << endl;
    }
  }
  else {
  }
}
