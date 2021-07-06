/*
Program: QUANTIZE 
Explanation: 
각 숫자별 오차 제곱의 합을 최소화하는 양자화 결과 출력 

INPUT: 
2
10 3
3 3 3 1 2 3 2 2 2 1 
9 3 
1 744 755 4 897 902 890 6 777

RESULT:
0
651
*/

#include <iostream>
#include <string.h> 
#include <algorithm>
#define INF 1e8
using namespace std; 

int rep, num; 
int dp[101][11]; 
// pSum: A[]의 부분합 저장 
// pSqSum: A[]제곱의 부분합 저장 
int A[101], pSum[101], pSqSum[101]; 

void precalc() {
    sort(A, A+rep); 
    pSum[0] = A[0]; 
    pSqSum[0] = A[0] * A[0]; 
    for(int i = 1; i < rep; i++) {
        pSum[i] = pSum[i-1] + A[i]; 
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i]; 
    }
}

int minError(int lo, int hi) {
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]); 
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]); 

    int m = int(0.5 + (double) sum / (hi - lo + 1)); 
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);

    return ret ; 
}   

int quantize(int from, int parts) {
    // 모든 숫자가 양자화 되었을 때 
    if (from == rep) return 0 ;
    
    // 아직 남았는데 더 묶을 수 없을 경우 
    if (parts == 0) return INF; 
    int &ret = dp[from][parts];
    if( ret != -1 ) return ret; 
    ret = INF ; 

    for(int partSize = 1; from + partSize <= rep; partSize++) {
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1)); 
    }
    return ret; 

}
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int n; 
    int tmp; 
    cin >> n; 

    for(int i = 0 ; i < n; i++) {
        cin >> rep >> num; 
        for(int j = 0 ; j < rep ;j++) {
            cin >> A[j]; 
        }
        memset(dp, -1, sizeof(dp)); 
        precalc(); 
        cout << quantize(0, num) << '\n';
    }

    return  0;
}