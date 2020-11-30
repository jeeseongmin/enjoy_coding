#include <stdio.h>

int count_four(int input, int digit, int digit_number);
int power(int base, int expo);
int fourCNT_arr[9] = {0,};

int main() {
  int input;
  scanf("%d",&input);
  int copy_input = input;

  for(int i=1; i<9; i++) {
    fourCNT_arr[i] = power(10,i-1) + fourCNT_arr[i-1]*9;
  }

  int digit = 1;
  int total_fourCNT = 0;

  while(1) {
    float digit_number = power(10,digit);
    int part_input = copy_input%(int)digit_number;
    if(copy_input - copy_input%(int)digit_number == 0) {
      total_fourCNT += count_four(part_input, digit, (int)digit_number/10);
      break;
    }
    else {
      total_fourCNT += count_four(part_input, digit, (int)digit_number/10);
      copy_input-=part_input;
      digit++;
    }
  }
  printf("%d\n",input-total_fourCNT);
}

int count_four(int input, int digit, int digit_number) {
  int front_digit = input/digit_number;
  if(front_digit <= 3) {
    return front_digit*fourCNT_arr[digit-1];
  }
  else if(5 <= front_digit) {
    return digit_number + (front_digit-1)*fourCNT_arr[digit-1];
  }
  return 0;
}

int power(int base, int expo) {
  int result = 1;
  for(int i=0; i<expo; i++) {
    result *= base;
  }
  return result;
}
