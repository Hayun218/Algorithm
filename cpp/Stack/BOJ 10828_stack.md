## BOJ 10828 스택

- 문제 푼 날짜: 2023.3.27 (월) 
- 문제링크: [BOJ10828](https://www.acmicpc.net/problem/10828)



### 내가 이해한 문제 내용

- Stack을 이해하기 위한 문제로 Stack 명령어를 입력 받고 그대로 실행하는 것

-----

- 입력: 테스트 케이스 갯수 T, 문자열 T개
- 출력: stack 실행하여 알맞게 출력



### 접근방식

- Switch 문으로 구현할려고 했는데, string 자체를 case로 두지 못해 hash를 써야한다고 해서 간단하게 if else if 문으로 차근차근 접근하여 문제 해결
- 이전에 배운 공백을 포함하여 문자열을 입력받는 getline()을 활용 (+ cin.ignore())

---

### 어려웠던 점 or 새로알게된점

- string을 비교하는 함수는 다양한거 같다.. 주로 쓰던 함수는 따로 없어서 새로 찾아서 compare 함수를 사용함 => string.compare("text") 함수

- Push 명령어의 경우 뒤에 int 도 같이 입력받기에 find() 함수로 공백이 있을 경우, substr를 통해 공백의 앞과 뒤를 구분하여 string에 넣어줌

  

### 부족했던 부분

- string을 다루는 부분에 여전히 익숙하지 않은 듯 하다.

- 클린코드를 추구하는데.. 그냥 순차적으로 막 진행하다보니까 클린하지가 않은거 같다 ㅠㅠ 나중에 참고하여 수정해봐야지..

- 

- 

  


### 궁금한 점

- -



##### 참고자료

- -