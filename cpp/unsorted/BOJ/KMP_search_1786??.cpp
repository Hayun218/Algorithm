#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
    int fail[MAX];
    for (int i = 1, j = 0; i < M; i++)
    {
        while (j > 0 && W[i] != W[j])
            j = fail[j - 1];
        if (W[i] == W[j])
            fail[i] = ++j;
    }
    char W[MAX + 1], S[MAX + 1];
    int M, N;
    gets(S);
    gets(W);
    N = strlen(S);
    M = strlen(W);

    // S, W의 일치하는 지점을 result에 모음
    vector<int> result;
    for (int i = 0, j = 0; i < N; i++)
    {
        // 현재 글자가 불일치하면 fail 값을 계속 따라감
        while (j > 0 && S[i] != W[j])
            j = fail[j - 1];
        // 현재 글자가 일치
        if (S[i] == W[j])
        {
            // W를 S[i:i+M-1]에서 찾음
            if (j == M - 1)
            {
                // i=0부터 시작한다면 i-M+1. 문제 조건에 따라 1을 더함
                result.push_back(i - M + 2);
                // 찾지 못한 것처럼 j를 이동시키면 됨
                j = fail[j];
            }
            else
                j++;
        }
    }
    return 0;
}