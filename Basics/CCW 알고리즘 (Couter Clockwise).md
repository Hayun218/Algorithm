## CCW 알고리즘 (Couter Clockwise)
- 기하와 벡터가 기본 => 후에 수학적인 부분 더 공부하고.. 현재는 기본적인 암기만 살펴봄 
- 평명위에 놓여진 3점의 방향 관계 파악 가능!

### 3개의 return 값


- 2차원 평면벡터 이므로 3번째 값들은 0이므로 아래와 같은 식 성립

![공식](https://t1.daumcdn.net/cfile/tistory/99AE303359DB53141F)


1. S = 0 => 평행 

![세점이 평행](https://t1.daumcdn.net/cfile/tistory/99AA053359DB523F11)

2. S > 0 => 반시계 방향

![S>0](https://t1.daumcdn.net/cfile/tistory/99B3A53359DB504326)


3. S < 0 => 시계 방향

![S<0](https://t1.daumcdn.net/cfile/tistory/9961C33359DB516D26)

#### 소스코드 
- 삼각형의 넓이 구하는 공식 -> 사선공식 기억! 동일..

```
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}
```

- 페어를 쓰지 않고 공식을 그대로 전개할 때..
	- (x2−x1)(y3−y1)−(x3−x1)(y2−y1) =x1y2+x2y3+x3y1−(y1x2+y2x3+y3x1)

```
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}
```

[참고]<https://degurii.tistory.com/47>
<https://jason9319.tistory.com/358>
