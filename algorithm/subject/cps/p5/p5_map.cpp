#include <iostream>
#include <map>

using namespace std;
int main() {
  map<double, double> func;
  int _len1;
  int _len2;
  double start;
  double end;

  scanf("%d",&_len1);
  for(int i =0; i<_len1; i++) {
    double temp_index;
    double temp_value;
    scanf("%lf %lf",&temp_index, &temp_value);
    func.insert(pair <double,double>(temp_index, temp_value));
  }

  scanf("%d",&_len2);
  for(int i =0; i<_len2; i++) {
    double temp_index;
    double temp_value;
    scanf("%lf %lf",&temp_index, &temp_value);
    if(func.find(temp_index) == func.end()) {
      func.insert(pair <double, double>(temp_index, temp_value));
    }
    else {
      func[temp_index] = (func[temp_index] > temp_value) ? func[temp_index] : temp_value;
    }
  }

  scanf("%lf %lf",&start, &end);
  map<double, double>::iterator iter;
  double sum = 0;
  double cnt = 0;
  int flag = 0;

  // 여기서 i는 start와 end를 돌게된다.
  // 안의 for문은 func의 index 값들과 비교하는 것인데, cnt를 통해 func을 탐색한다.
  // 여기서 cnt는 func의 어디까지 탐색했고, 어디부터 탐색해야하는지를 알려준다.
  for(double i = start; i<=end; i++) {
    iter = func.begin()+cnt;
      // 함수의 첫 요소일 경우.
      if(iter == func.begin()) {
        // 함수의 첫 요소인데, 그것보다는 클 경우
        // 이때는 함수의 다음요소와 검사한다.
        // 왜냐면 그러면 함수의 첫 요소~i 요소까지는 값이 있기 때문에 이것을 sum에 넣어줘야 하기 때문.
        if(iter->first < i) {
          // 이번요소가 마지막이라면. 즉 함수 요소가 하나라면.
          if((++iter) == func.end()) {
            sum += (end+1 -i) * (iter)->second;
            flag = 1;
            break;
          }
          // 이번요소가 마지막이 아니라면
          else {
            // 수정 필요
            if((++iter)->first < end) {
              next = (++iter)->first;
              sum += (next - i) * (iter)->second;
              i = next;
              cnt++;
              break;
            }
            // 다음 요소가 end 요소보다 클 경우.
            // 그냥 end 요소까지만 더하고 종료한다.
            else {
              sum += (end - i) * (iter)->second;
              flag = 1;
              break;
            }
          }
        }
        // 함수의 첫 요소인데 그것보다 작을 경우
        else {
          // 이번요소가 마지막이라면. 즉 함수 요소가 하나라면.
          if((++iter) == func.end()) {
            sum += (end+1 - iter->first) * (iter)->second;
            flag = 1;
            break;
          }
          // 그냥 첫 요소를 i로 만들고 끝낸다.
          // 왜냐면 함수의 첫 인덱스까지는 0이기 때문이다.
          if(iter->first < end) {
            next = iter->first;
            i = next;
            cnt++;
            break;
          }
          // 이 경우는, start와 end가 함수의 첫 요소보다 작은 경우이기 때문에 그냥 종료. sum==0
          else {
            flag = 1;
            break;
          }
        }
      }

      // 함수의 첫 요소가 아닐 경우.
      // 이 경우가 본게임
      else {
        // 이번 요소가 마지막 요소라면. end부터 마지막 요소만 더해주고 끝낸다.
        if((++iter) == func.end()) {
          sum += (end+1 - i) * iter->second;
          flag = 1;
          break;
        }
        // 근데 i는 첫 요소가 아니면 무조건 현재 index와 같을 수밖에 없다.
        // 다음 인덱스를 end와 비교한다.

        // 그래서 다음 인덱스가 end보다 작다면
        // 다음 인덱스 - 현재 인덱스까지의 차이 * 현재 인덱스의 value로 곱해서 더한 뒤 i값을 변경한다.
        else if((++iter)->first < end) {
          next = (++iter)->first;
          sum += (next - i) * (iter)->second;
          i = next;
          cnt++;
          break;
        }
        // 다음 요소가 end 요소보다 크거나 같을 경우.
        // 그냥 end 요소까지만 더하고 종료한다.
        else {
          sum += (end+1 - i) * (iter)->second;
          flag = 1;
          break;
        }

      }
    if(flag == 1) break;
  }

  printf("sum : %d\n",sum);

  // for(iter = func.begin(); iter != func.end(); iter++) {
  //   cout << "[" << iter->first << "," << iter->second << "]" << " ";
  // }

  // double count = 0;
  // for(double i = 0; i<2000000000; i++) {
  //   count++;
  // }
  // printf("cnt : %0.f\n",count);
  return 0;
}
