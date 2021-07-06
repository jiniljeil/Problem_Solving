/*
Program: TRIPATHCNT
Explanation: 
삼각형 위의 최대 경로 개수 세기 

INPUT:
4
9
5 7 
1 3 2
3 5 5 6

4
24
13 15
6 8 8
3 5 5 6

RESULT: 

*/

#include <iostream>
#include <string.h> 

using namespace std; 

int dp[101][101]; 
int count_dp[101][101]; 
int triangle[101][101]; 
int num; 

int b_path(int y, int x){
    if (y == n - 1) return triangle[y][x]; 
    int &ret = dp[y][x]; 
    if( ret != -1) return ret; 
    return ret = max(b_path(y+1, x), b_path(y+1, x+1)) + triangle[y][x]; 
}

/*
count(y,x) = max(
                count(y+1, x)   (path(y+1, x+1) < path(y+1, x))
                count(y+1, x+1) (path(y+1, x+1) > path(y+1, x)) 
                count(y+1, x+1) (path(y+1, x) == path(y+1, x+1))
            )
*/

int count_path(int y, int x) {
    if( y == num - 1) return 1; 
    int &ret = count_dp[y][x]; 
    if( ret != -1) return ret; 
    ret = 0 ;
    if(b_path(y+1, x+1) >= b_path(y+1, x)) ret += count(y+1, x+1); 
    if(b_path(y+1, x+1) <= b_path(y+1, x)) ret += count(y+1, x);
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0) ;

    cin >> num; 

    for(int i = 0 ; i < num; i++) {
        for(int j = i ; j >= 0; j--) {
            cin >> triangle[i][j] ; 
        }
    }

    memset(dp, -1, sizeof(dp)); 



    return 0;
}