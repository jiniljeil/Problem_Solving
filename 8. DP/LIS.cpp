/*
program: LIS (Longest Increasing Subsquence)
Explanation: 
주어진 수열에서 얻을 수 있는 증가 부분 수열 중 가장 긴 것
*/

#include <iostream>
#include <vector> 

using namespace std; 

vector<int> seq; 
int dp[100]; 
// 완전 탐색 
int LIS(vector<int> set) {
    if(set.empty()) return 0;
    int ret = 0 ; 
    for(int i = 0 ; i < set.size(); i++) {
        vector<int> B ;
        for(int j = i + 1; j < set.size(); j++) {
            if(set[i] < set[j]) {
                B.push_back(set[j]);
            }
        }
        ret = max(ret, LIS(B) + 1 ) ;
    }
    return ret; 
}
// 동적 계획법
int LIS_DP(int start) {
    int &ret = dp[start] ;
    if(ret != -1) return ret; 
    ret = 1 ; // 최소 start 값이 존재하므로
    for(int i = start + 1 ; i < seq.size(); i++) {
        if(seq[start] < seq[i]) {
            ret = max(ret, LIS_DP(i) + 1); 
        }
    }
    return ret ;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int n, c;
    cin >> n; 

    for(int i = 0 ; i < n; i++) {
        cin >> c ;
        seq.push_back(c); 
    }
    memset(dp, -1 , sizeof(dp)); 
    int result = LIS_DP(0);
    cout << result << '\n'; 
    return 0; 
}

