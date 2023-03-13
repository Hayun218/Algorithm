#include <cstdio>
#include <vector>
using namespace std;

typedef struct{
    int a, b, c;
} box;

int main(){
    int n, k, d;
    long long mid, cnt, high, low;
    box in;
    vector<box> doto;
    scanf("%d %d %d", &n, &k, &d);

    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &in.a, &in.b, &in.c);
        doto.push_back(in);
    }
    high = n;
    low = 1;
    while(low + 1 < high){
        mid = (high+low)/2;
        cnt = 0;
        for(int i = 0; i < doto.size(); i++){
            if(doto[i].b < mid){
                cnt += (doto[i].b - doto[i].a)/doto[i].c + 1;
            } 
            else if(doto[i].a > mid){
                continue;
            }
            else if(doto[i].a == mid){
                cnt += 1;
            }
            else {
                cnt += (mid - doto[i].a)/doto[i].c + 1; //   mid 와 doto[i].b가 같을경우 
            }
        }
        if(cnt >= d){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    printf("%lld", high);
    return 0;
}
