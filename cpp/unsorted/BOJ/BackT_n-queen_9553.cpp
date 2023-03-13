#include <cstdio>
#include <vector>
using namespace std;

int N, board[15][15];


void solve(int board[N][N], int col){
  if(col >= N) return;

  for(int i = 0; i < N; i++){
    if(isSafe(board, i, col))
      board[i][col] = 1;
    else continue;
  }

}


int main(){
  scanf("%d", &N);


}
