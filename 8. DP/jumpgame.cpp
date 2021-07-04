/*
Program: JUMPGAME 
Explanation: 
게임판의 왼쪽 위 칸에서 시작해서 게임판의 맨 오른쪽 아래 칸에 도착하는 것 
칸에 적혀있는 숫자만큼 아래쪽이나 오른쪽으로 이동 가능 
중간에 게임판 밖으로 벗어나면 안됨.

INPUT: 
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0 

RESULT: TRUE
*/

#include <iostream> 
#include <string.h> 
using namespace std;

int map[100][100]; 
int dp[100][100]; 
int row, col; 
int solve(int y, int x) {
    if( y >= row || x >= col) return 0; 
    if (map[y][x] == 0) { // 0: 끝지점
        return 1 ;
    }
    int ret = dp[y][x]; 
    if( ret != -1) return ret;
    return ret = (solve(y + map[y][x], x) || solve(y, x + map[y][x]));
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> row >> col; 
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col; j++) {
            cin >> map[i][j] ; 
        }
    }
    memset(dp, -1, sizeof(dp)); 
    int result = solve(0,0); 
    if(result == 1) cout << "Possible" << '\n'; 
    else cout << "Impossible" << '\n'; 
    return 0; 
} 