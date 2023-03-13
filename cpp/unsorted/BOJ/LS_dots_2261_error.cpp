#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point() {
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (const Point &v) const {
        if(y == v.y)
            return x < v.x;
        else
            return y < v.y;
    }
};
bool cmp(Point &u, Point &v){   
    return u.x < v.x;   
}
int dist(const Point p1, const Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); // 두 점 사이의 거리의 제곱
}
int main()
{
    int N;
    scanf("%d", &N);
    vector<Point> a(N); 
    for(int i = 0; i < N; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    sort(a.begin(), a.end(), cmp);  // 순서대로 정렬 => 불필요한 검사를 줄이기 위한 첫시작
    set <Point> cand;
    cand.insert(a[0]);
    cand.insert(a[1]);              // 후보자들 
    int start = 0;                  //set에 입력받은 구간의 시작점 (위에서 0으로 시작하였기에 0)
    int ans = dist(a[0], a[1]);     // 0과 1사이의 거리
    // x(좌우) 점들을 비교 
    for(int i = 2; i < N; i++){     // 0과 1은 제외하고 (위에서 했으니까) 계산 
        Point now = a[i];           // 현재 위치를 i로
        while(start < i){           // 시작구간이 i보다 작으면 계속 반복
            auto p = a[start];      // auto(자동으로 type 맞춤) p에 벡터 a[i]
            int x = now.x - p.x;    // 현재 x좌표 - 시작 x 좌표
            if(x*x > ans) {         // 전에 구한 ans(두 점 사이의 거리의 제곱)과 위에서 구한 x좌표들의 차이의 제곱 비교
                cand.erase(p);      // ans보다 크다면 p값 즉 본 시작 x값을 후보에서 지움
                start += 1;         // 시작 값을 1 더해서 반복
            } else break;           // ans보다 작다면 break하고 밑으로 (아직 for문이 끝나지 X)
        }
        // y(위아래) 점들을 비교
        int d = (int)sqrt((double)ans) + 1;         // 두 점 사이의 거리 + 1 을 d로 선언
        auto lower_point = Point(-100000, now.y-d); // x의 최솟값, 현재 y값 - d
        auto upper_point = Point(100000, now.y+d);  // x의 최댓값, 현재 y값 + d  => 
        auto lower = cand.lower_bound(lower_point); // lower_point는 lower_bound에 넣고. . . 
        auto upper = cand.upper_bound(upper_point);
        for(auto it = lower; it != upper; it++){    // lower이 upper보다 커지지 않을 때까지 반복
            int d = dist(a[start], it);                 // now = a[i]
            if(d < ans)                             // d가 ans보다 작다면 ans를 d로 갱신
                ans = d;
        }
    cand.insert(now);                               
    }
    printf("%d\n", ans);
    return 0;
}