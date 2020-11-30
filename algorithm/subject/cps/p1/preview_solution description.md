10까지 4 한개

20까지 4 한개

30까지 4 한개

40까지 4 두개

50까지 4 





1의 자리에서 4가 제외되면, 1개

10의 자리에서 4가 제외되면, 10개(40자리 대) + 9개

100의 자리에서 4가 제외되면, 100개(400자리 대) +
100~200 -> 18개,



1000의 자리에서 4가 제외되면, 1000개

x라는 input이 들어왔다면, x까지의 숫자가 카운트될때까지 4의 자리는 카운트 되지 않은 것으로 판단할 수 있다. 따라서 이를 통해 실제 값 (output)을 구할 수 있다.

1399는
1000+399
1000+300+99
1000+300+90+9

1000 : 100 + 19 x 9(171) = 271
300 : 19 x 3 = 57
90 : 10+8 = 18

4 14 24 34 54 64 74 84 + 10
9 : 1 = 1 

= 347

10의 0승 - 1 : 0
10의 1승 - 10 : 1
10의 2승 - 100 : 10 + 1 x 9
10의 3승 - 1000 : 100 + 19 x 9
10의 4승 - 10000 : 1000 + 271 x 9
10의 5승 - 

1. 먼저 각 자리수(10의 8승)까지 4가 나오는 횟수를 적어놓는다.
2. 일정한 자리값의 숫자를 입력받으면 그 숫자까지 빼먹은 4의 횟수를 카운트해서하는 카운트 함수를 만든다.
3. input 값을 쪼개어 카운트 함수에 입력해서 그 모든 출력 값들을 더한다.
4. 그래서 input 값에서 그 출력 값을 빼면 output 값이 나오게 된다.



--------

10 -> 9
100 -> 90 
1000 -> 300
10000 -> 1000

--------------

**시나리오 :** 

문제에서 input값은 비정상 count 값이고, output은 정상 count 값인데 제가 파악한 input과 output의 관계는 input값까지 순차적으로 카운트 했을 때에, input에서 digit 4가 포함되는 경우를 빼면 output이 된다고 이해했습니다.

그래서 input을 각 자릿수로 분리해서 생각해보았습니다.

예를 들어, 1399 -> 1000 + 300 + 90 + 9 와 같은 형식입니다.

이렇게 했을 때 문제가 없는 이유는, 단순히 4라는 digit이 포함됐는지의 여부만 판단하면 되기 때문입니다. 

먼저 10의 8승까지의 non-negative number를 input으로 받기 때문에 10의 8승까지의 non-negative number까지 카운트했다고 가정했을 때에 4의 digit이 나타나는 수를 배열(이하 fourCNT_arr)로 설정해놓았습니다. (나중에 input을 자릿수로 나눴을 때에 count 함수에서 활용할 수 있도록)
(그림을 보여주며 )

그 방식은, 10의 0승일 때는 0, 10의 1승일 때는 4 하나, 
10의 2승인 100 부터는 10^(n-1) + fourCNT_arr[n-1] * 9 를 해주는 방식으로 진행합니다.
이유는 예를 들어 1부터 100까지 count하게 될 때에는, 
40자리대의 숫자들을 모두 건너뛰기 때문에 10^(n-1)의 값을 모두 더하는 것이고, 
 10^(n-1), 4 ~ 94 까지의 카운트를 포함하지만, 44 또한 39 -> 50으로 건너 뛸 것이기 때문에 10을 곱하는 것이 아닌, fourCNT_arr[n-1] * 9로 배열을 만듭니다.

(참고로 여기서 사용한 math 함수는 pow(num,n)으로 num을 n승만큼 제곱해주는 함수입니다.)

그렇게 배열을 만들었다면, 이제 input값을 1의 자리수부터 쪼개어 갑니다.

input 값을 복사한 copy_input 값과 1의 자리부터 쪼갤 것이기 때문에 digit을 1로 놓습니다.

(이 자릿수 값은 점점 커져가면서 10의 n승이 될 예정입니다.)

그래서 copy_input 값을 쪼개어 분리하며, 해당 자릿수의 정보를 배열에서 파악하기 위해서 digit을, 빠르게 최고 자리의 숫자를 파악하기 위해 필요한 digit_number(ex:1, 10, 100)을 count_four 함수에 함께 parameter로 입력합니다.

그러면, count_four 함수에서는 part_input의 front_digit 값을 체크합니다.

(1) front_digit이 3이하인지 :
만약 3이하이면, front_digit x fourCNT_arr[digit-1] 을 return합니다.

(2) front_digit의 앞자리 숫자가 5이상인지 : 
만약 5이상이면, digit_number + (front_digit-1) x fourCNT_arr[digit-1]을 return합니다. 
(여기서 digit_number는 100일 때 40자리의 수(10개), 1000일 때 400자리 수(100개)의 개수를 말합니다. 그리고 4자리대를 건너뛰기 때문에 3이하의 경우와 달리 front_digit-1을 해줍니다.)

그렇게 count_four의 return 값들은 모두 total_fourCNT라는 변수에 모두 저장이 됩니다. 
(이 변수는 input 값까지 count 했을 때에 4라는 digit의 모든 count 값입니다.)

그래서 결국 input에서 모아진 total_fourCNT 값을 빼면 원래 정상적인 count값인 output이 나오게 됩니다.