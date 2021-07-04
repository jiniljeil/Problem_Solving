/*
Program: TRIANGLE PATH
Explanation: 
삼각형으로 배치된 자연수 
맨 위의 숫자에서 시작해서, 한 번에 한 칸씩 아래로 내려가 맨 아래 줄까지 닿는 경로를 만듦
경로에 포함된 숫자들의 최대 합!

INPUT:
5 5
6
1 2 
3 7 4
9 4 1 7
2 7 5 9 4

5 5
1
2 4 
8 16 8
32 64 32 64
128 256 128 256 128

RESULT: 

*/

#include <iostream>
#include <string.h> 
using namespace std ;

int triangle[101][101]; 
int dp[101][101]; 
int n ; 
int path(int y, int x, int sum) {
    if (y == n - 1) return sum + triangle[y][x];
    int &ret = dp[y][x]; 
    if( ret != -1) return ret; 
    return ret = max(path(y+1, x, sum+triangle[y][x]), path(y+1, x+1, sum+triangle[y][x]));
}
int b_path(int y, int x){
    if (y == n - 1) return triangle[y][x]; 
    int &ret = dp[y][x]; 
    if( ret != -1) return ret; 
    return ret = max(b_path(y+1, x), b_path(y+1, x+1)) + triangle[y][x]; 
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0 ;i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> triangle[i][j]; 
        }
    }
    memset(dp, -1, sizeof(dp)); 
    // int result = path(0,0,0); 
    int result = b_path(0,0);
    cout << result << '\n'; 
    return 0;
}