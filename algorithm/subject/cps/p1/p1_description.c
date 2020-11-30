#include <stdio.h>
#include <math.h>

/*
1. 먼저 각 자리수(10의 8승)까지 4가 나오는 횟수를 적어놓는다.
2. 일정한 자리값의 숫자를 입력받으면 그 숫자까지 빼먹은 4의 횟수를 카운트해서하는 카운트 함수를 만든다.
3. input 값을 쪼개어 카운트 함수에 입력해서 그 모든 출력 값들을 더한다.
4. 그래서 input 값에서 그 출력 값을 빼면 output 값이 나오게 된다.
*/
int count_four(int input, int digit, int digit_number);
int fourCNT_arr[9] = {0,};
// input까지 카운트 됐을 때에 숫자 4가 나오는 경우를 빼면 된다.
// input = 13 - 12 / 1399 - 1052 / 999999 - 531440
int main(void) {
  int input;
  scanf("%d",&input);
  int copy_input = input;

  for(int i=1; i<9; i++) {
    fourCNT_arr[i] = pow(10,i-1) + fourCNT_arr[i-1]*9;
    printf("fourCNT_arr[%d] : %d\n",i,fourCNT_arr[i]);
  }

  int digit = 1;
  int total_fourCNT = 0;

  while(1) {
    float digit_number = pow(10,digit);
    int part_input = copy_input%(int)digit_number;
    if(copy_input - copy_input%(int)digit_number == 0) {
      // printf("%d | %d\n",part_input, cnt);
      total_fourCNT += count_four(part_input, digit, (int)digit_number/10);
      break;
    }
    else {
      // printf("%d | %d\n",part_input, cnt);
      total_fourCNT += count_four(part_input, digit, (int)digit_number/10);
      copy_input-=part_input;
      digit++;
      // printf("\n");
    }
  }
  printf("%d\n",input-total_fourCNT);
}

// 쪼개진 input들의 숫자 4 포함 개수를 세는 함수.
int count_four(int input, int digit, int digit_number) {
  // printf("input: %d, digit: %d, digit_number: %d\n",input, digit, digit_number);
  int front_digit = input/digit_number;
  if(front_digit <= 3) {
    // 자릿수 * 아래 cnt 개수
    return front_digit*fourCNT_arr[digit-1];
  }
  else if(5 <= front_digit) {
    // 자릿수 +
    // 여기서 front_digit-1을 해주는 이유는, digit_number를 더하면서 이미 4번째 자릿수는 제외하기 때문이다.
    return digit_number + (front_digit-1)*fourCNT_arr[digit-1];
  }
}
