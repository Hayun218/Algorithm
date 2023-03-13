#include <iostream>
#include <string>
using namespace std;

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
string input[101];
char map[101][101];
int R, C;

void findMine(){
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(input[i][j] == '*') map[i][j] = '*';
      else{
        int sum = 0;

        for(int k = 0; k < 8; k++){
          int ddx = i + dx[k];
          int ddy = j + dy[k];
          if(ddx >= 0 && ddx < R && ddy >= 0 && ddy < C )
            if(input[ddx][ddy] == '*') sum++;
        }
        map[i][j] = sum + '0';
      }
    }
  }
}

int main(){

  while(1){
    cin >> R >> C;
    if(R == 0 && C == 0) break;

    for(int i = 0; i < R; i++)
      cin >> input[i]; // char이 아닌 string으로 받아야함 (줄 유지)

    findMine();

    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        cout << map[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
