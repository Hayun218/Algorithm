#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int N, M, arr[MAX];

void binarySearch(int num) {
    int start = 0;
    int end = N - 1;
    int mid;

    while(start <= end) {
        mid = (start + end) / 2;

        if(arr[mid] == num) {
            cout << '1' << '\n';
            return;
        } else if(arr[mid] > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << '0' << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tmp;

    cin >> N;

    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N);

    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        binarySearch(tmp);
    }
    return 0;
}