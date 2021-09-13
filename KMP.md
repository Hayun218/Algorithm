##KMP
	문자열로 검색하기! 시간복잡도: O(N+M)

이중 for문으로 나타내는 경우 

~~~
String S = "I have a pen";
string W = "have";

for(int i = 0; i < S.size()-W.size(); i++){
	bool flag = true;
	for(int j = 0; j < W.size(); j++){
	if(S[i+j] != W[j]){
		flag = false;
		break;
	}
}
~~~

=> 이 경우는 O(NM) 의 시간복잡도 too much waste of time!

KMP에서 길을 안내해주는 것은 => 실패 함수!

- 불일치가 발생하였을 때 j가 어디로 이동해야 하는지 알려주는 값
- fail(x) = W의 처음 (x+1)글자 중, 일치하는 접두사/접미사 중 최대 길이
	- abcdeab 를 찾아야 할때 abceab 를 찾게 되면 해당 단어의 접미사인 ab는 접두사가 될 수 있음! => f(x)의 값은 2가 되고
	- j = fail[j] 로 바로 점프 시켜줌!

- [기본연습문제] <https://www.acmicpc.net/problem/1786>

