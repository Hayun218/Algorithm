#include <cstdio>

int stu[3][7];
int N, K;

int main(){
  scanf("%d %d",&N, &K);
  int S, Y;
  for(int i = 0; i < N; i++){ // or while(N--)
    scanf("%d %d",&S, &Y);
    stu[S][Y]++;
  }
  int room = 0;

  for(int i = 0; i < 2; i++){
    for(int j = 1; j <= 6; j++){
      if(!stu[i][j]) continue; // 해당 성별, 학년의 학생이 없을때
      if(stu[i][j] < K)
        room++;
      else {
        if(stu[i][j] % K == 0)
          room = room+ stu[i][j]/K;
        else{
          room = room + stu[i][j]/K + 1;
        }
      }
    }
  }
  printf("%d\n", room);
  return 0;
}
