/*
Program: JAEHASAFE
Explanation: 
주어진 다이얼을 최소 몇 칸이나 돌려야 금고를 열 수 있는지 출력 

INPUT: 
2
3
abbab
babab
ababb
bbaba
2
RMDCMRCD
MRCDRMDC
DCMRCDRM

[다시]
OUTPUT:
6
10
*/
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

vector<int> getPartialMatch(const string &pattern) {
    int m = pattern.length(); 
    vector<int> pi(m, 0); 

    int begin = 1, matched = 0 ;
    while(begin + matched < m) {
        if(pattern[begin + matched] == pattern[matched]) {
            matched++;
            pi[begin + matched -1] = matched ;
        }else{
            if(matched == 0) begin++; 
            else{
                begin += matched - pi[matched - 1]; 
                matched = pi[matched - 1]; 
            }
        }
    }
    return pi; 
}

vector<int> kmpSearch(const string &original, const string &pattern) {
    int n = original.length(), m = pattern.length(); 
    vector<int> ret; 
    vector<int> pi = getPartialMatch(pattern); 

    int begin = 0, matched = 0 ; 
    while( begin <= n - m ) {
        if (matched < m && original[begin + matched] == pattern[matched]) {
            matched++; 
            if(matched == m) ret.push_back(begin); 
        }else {
            if(matched == 0) begin++; 
            else{
                begin += matched - pi[matched - 1] ;
                matched = pi[matched - 1] ;
            }
        }
    }

    return ret; 
}

int shifts (const string &original, const string &target) {
    return kmpSearch(original + original, target)[0];
}

int main(void) {
    int testcase, n ; 
    int min_v = 1e8;
    string dial; 
    cin >> testcase ; 
    for(int i = 0 ; i < testcase ;i++) {
        cin >> n; 
        cin >> dial ;
        string dial_test; 
        for(int j = 0 ; j < n ; j++) {
            cin >> dial_test; 
            min_v = min(min_v, shifts(dial, dial_test)); 
        }
        cout << min_v << '\n';
        min_v = 1e8; 
    }
    return 0;
}