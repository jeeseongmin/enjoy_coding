# P6. Polyomino Puzzle

Polyomino는 한개 이상의 1x1 사각 블럭들이 섞여있는 사각 모양이다.

예를 들어, figure 1은 각각 다른 형태의 네개의 polyomino들이다. 우리는 퍼즐들로 사각형을 만들어볼 수 있다. 이 퍼즐에서 각 polyomino는 회전할 수 없고, 모든 polyomino들은 사각형으로 되어야 한다. Figure 2는 어떻게 우리가 사각형을 만드는지 보여준다.

---

#### Input Data :

standard input의 첫 줄은 integer n을 말한다. 이 숫자는 puzzle에서 polyomoni들의 숫자이며, 1<=n<=5의 범위를 가진다. 다음 라인들은 n polyomino들의 모양들을 정의한다.

이 폴리오미노들은 1부터 n까지를 가진다.

1<=n<=5 까지의 각 폴리오미노들은 두 숫자들로 구성이 되는데, h와 w이다. h는 height, w는 width를 의미한다.그리고 h 줄들에서, 각각은 w의 binary digit을 가진다. 이것은 폴리오미노의 모양을 정의해준다.
binary digit 1은 사각 블럭을 가지고 있음을 말해준다.

-----

#### Output Data : 

배열들은 주어진 폴리오미노들의 배열 배치를 나타내야 한다. 배열은 사각형이 되어야 하며, 즉, 열의 숫자들은 행의 숫자들과 같아야 한다. 배열에서 사각 블럭은 폴리오미노의 아이디에 의해 특정이 되어야 한다. 

h == 4 or w == 4 일 때에 mark[i] = 1; and

------

먼저 height == 4이거나 width == 4인 경우를 체크한다. 이러한 경우에는 4가지 경우밖에 없기 때문이다.

0) 기존의 값들을 먼저 입력받는다.

1) 값들의 크기를 비교해서 순서를 정렬한다. h+w 기준으로 정렬 + fix[퍼즐 개수] 배열도 만든다. 확정된건지 아닌지. --> fix됐다면 아래 final 배열에 입력한다.

2) 초기에 입력받는 final 배열 설정. + 연습할 temp 배열도 설정. 둘다 {0,} 으로

3) 정렬된 순서대로 temp 배열에 입력하기 시작한다.

4) 

이미 채워졌다면 범위를 좁힌다. ex) 첫줄이 모두 찼다면, for(int i =2; i<5; i++) 이런 식으로

-------

```
1. 맨 처음 main에서

puzzle_i를 final에 픽스해가는 과정.
for(int i=1; i<=cnt; i++) {
	if(fix[i]==0) {
		combi(final, puzzle[i]);
	}
}

void combi(int final[], int puzzle[]) {
	
}
```

