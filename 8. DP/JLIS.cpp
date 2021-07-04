/*
Program: JLIS(Joined Longest Increasing Subsquence)
Explanation: 
두 개의 정수 수열 A와 B에서 각각 길이 0 이상의 증가 부분 수열을 얻은 뒤 이들을 크기 순서대로 합친 것 

INPUT: 
3
3 3
1 2 4
3 4 7
3 3
1 2 3
4 5 6
5 3
10 20 30 1 2
10 20 30

RESULT:
5
6
5
*/

#include <iostream>
#include <vector> 
#include <string.h>
using namespace std ;

vector<int> A, B; 
const long long NEGINF = numeric_limits<long long>::min(); 
int dp[101][101];

int JLIS(int indexA, int indexB) {

    int &ret = dp[indexA+1][indexB+1]; 
    if( ret != -1) return ret; 

    // 기본 값 두 개 
    ret = 2 ; 
    
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]); 
    long long maxvalue = max(a,b); 

    for(int nextA = indexA + 1 ; nextA < A.size(); nextA++) {
        if(maxvalue < A[nextA]) {
            ret = max(ret, JLIS(nextA, indexB) + 1); 
        }
    }
    for(int nextB = indexB + 1 ; nextB < B.size(); nextB++) {
        if(maxvalue < B[nextB]) {
            ret = max(ret, JLIS(indexA, nextB) + 1); 
        }
    }
    return ret ;
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    int num, a, b, c;
    cin >> num; 

    for(int i = 0; i < num; i++) {
        cin >> a >> b ;
        for(int j = 0 ; j < a ; j++) {
            cin >> c ;
            A.push_back(c); 
        }
        for(int j = 0 ; j < b ; j++) {
            cin >> c ;
            B.push_back(c); 
        }
        
        memset(dp, -1 ,sizeof(dp)); 
        int result = JLIS(-1, -1) -2; 
        cout << result<< '\n'; 
    } 

    return 0; 
}