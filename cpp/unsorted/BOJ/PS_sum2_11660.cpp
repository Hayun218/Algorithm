#include <cstdio>

int main()
{
    int n, m, psum[1025][1025];
    // 표의 크기인 n입력 && 합을 구하고자 하는 갯수 m 입력
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            scanf("%d", &a);
            psum[i+1][j+1] = psum[i+1][j] + psum[i][j+1] - psum[i][j] + a;
        }
    }
    
    // 합을 구하고자 하는 구간 입력 && 그 구간의 합을 알아내고 프린트
    for(int i = 0; i < m; i++){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        // 음.. 계산 과정 한번 더 살펴보기
        printf("%d\n", psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1]);
    }
}