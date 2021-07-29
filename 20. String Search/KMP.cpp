/*
Program: KMP algorithm 
Explanation: 
Prefix, Suffix 이용하여 일치하는 문자열 검색 
*/
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

vector<int> getPartialMatch(const string &pattern) {
    int m = pattern.length(); 
    vector<int> pi(m, 0); 

    int begin = 1 , matched = 0 ; 
    while(begin + matched < m) {
        if (pattern[begin + matched] == pattern[matched]) {
            matched++; 
            pi[begin + matched - 1] = matched ;
        }else {
            if( matched == 0 ) begin++; 
            else{
                begin += matched - pi[matched - 1] ; 
                matched = pi[matched - 1] ;
            } 
        }
    }
    return pi ; 
}

vector<int> kmpSearch(const string &str, const string &pattern) {
    int n = str.length(), m = pattern.length(); 
    vector<int> ret ; 
    vector<int> pi = getPartialMatch(pattern); 

    int begin = 0, matched = 0 ; 
    while(begin <= n - m) {
        if( matched < m && str[begin + matched] == pattern[matched]) { 
            matched++; 
            // 모두 일치할 경우 
            if(matched == m) ret.push_back(begin); 
        }
        else { 
            if(matched == 0) begin++; 
            else{
                // pi[matched-1] 만큼은 항상 일치 
                begin += matched - pi[matched - 1] ; 
                matched = pi[matched - 1]; 
            }
        }
    }
    return ret ;
}
int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0); 

    string str, pattern; 

    vector<int> v = kmpSearch(str, pattern); 
    for(int i = 0 ; i < v.size(); i++) {
        cout << v[i] << ' '; 
    }
    return 0;
}

