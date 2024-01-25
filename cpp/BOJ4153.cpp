#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    while(true) {
        int a[3];
        for(int i = 0; i < 3; i++) {
            scanf("%d", a+i);
        }
        if (a[0] == 0) return 0;
        sort(a, a+3); //  혹은 a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b?"right":"wrong"

        if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}