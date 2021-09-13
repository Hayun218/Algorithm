### pair
	<utility>



---------------
### vector
	<vector>



-------------
### sort,unique,erase 
	<algorithm>

- vector 배열에서 중복 원소 제거 => int 뿐만 아니라 문자열에서도 가능!

- unique 
	- 정렬이 이루어진 이후 사용가능!
	- 연속된 중복 원소를 vector의 제일 뒷부분으로 보내고 그 뒤의 주솟값(쓰레기값)을 보냄
	- unique가 끝났으면 반환되는값은 vector의 쓰레기값의 첫번째 위치!	- ex) 
	
~~~
10 20 20 20 30 30 20 20 10
10 20 30 20 10 ?  ?  ?  ?
~~~

- erase
	- unique 이후에 삭제하면 뒤 쪽 쓰레기값들은 삭제되고 남은 숫자는 => 10 20 30 


- 구현방법 (v = vector)

~~~
v.erase(unique(v.begin(), v.end()), v.end());
~~~


