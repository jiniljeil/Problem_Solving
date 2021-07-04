/*
Program: WILDCARD 
Explanation: 와일드카드 패턴과 대응되는 파일명 찾기 

INPUT: 
3
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
*bb*
1
babbbc

RESULT: 
heap
help
help
papa
babbbc
*/

#include <iostream>
#include <vector>
#include <string.h> 

using namespace std ;

string wildcard_patt, tmp; 
int dp[100][100]; 
// 완전 탐색 
bool match_c(string w, string s) {
    int pos = 0 ; 

    while(pos < w.size() && pos < s.size() && 
        (w[pos] == s[pos] || w[pos] == '?')) {
        pos++; 
    }
    if( pos == w.size() ) return (pos == s.size());
    if( w[pos] == '*') {
        for(int skip = 0; pos + skip <= s.size(); skip++) {
            if(match_c( w.substr(pos+1), s.substr(pos + skip))){ 
                return true ;
            }
        }
    }
    return false; 
}

// DP 
int match_dp(int w, int s) {
    int ret = dp[w][s]; 
    if( ret != -1 ) return ret; 
    while(w < wildcard_patt.size() && s < tmp.size() && 
        (wildcard_patt[w] == '?' || wildcard_patt[w] == tmp[s])) {
        w++; s++; 
        /*
        return ret = match_dp(w+1, s+1); 
        */
    }
    if ( w == wildcard_patt.size()) return dp[w][s] = (s == tmp.size()) ? 1 : 0;

    if ( wildcard_patt[w] == '*') {
        for(int skip = 0 ; s + skip <= tmp.size(); skip++) {
            if(match_dp(w+1, s + skip)) {
                return dp[w][s] = 1; 
            }
        }
        /*
        if (match_dp(w+1, s) || (s < tmp.size() && match_dp(w, s+1))){
            return ret = 1 ; 
        }
        */
    }

    return dp[w][s] = 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int num ;
    vector<string> result ;
    cin >> num; 

    for(int i = 0 ; i < num; i++) {
        int num_of_test; 
        cin >> wildcard_patt; 
        cin >> num_of_test; 
        
        for(int j = 0 ; j < num_of_test; j++) {
            memset(dp, -1, sizeof(dp)); 
            cin >> tmp; 
            // bool b = match_c(wildcard_patt, tmp); 
            int b = match_dp(0, 0);
            if(b == 1) result.push_back(tmp); 
        }
    }
    cout << '\n' << "<RESULT>" << '\n'; 
    for(int i = 0 ; i < result.size() ; i++) {
        cout << result[i] << '\n'; 
    }
    return 0;
}