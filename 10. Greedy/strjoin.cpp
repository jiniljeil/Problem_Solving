/*
Program: STRJOIN 
Explanation: 
두 문자열을 합치는 비용: 두 문자열의 길이 
{al, go, spot} 
al + go = 4 
algo + spot = 8 
총 12 
al + spot = 6
alspot + go = 8 
총 18 

필요한 최소 비용을 구하기 

INPUT: 
3
3
2 2 4
5
3 1 3 4 1
8
1 1 1 1 1 1 1 2

*/

#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 

using namespace std; 

int n ; 
vector<int> string_len_set ;

int solve() {   
    priority_queue<int, vector<int>, greater<int> > pq; 

    for(int i = 0 ; i < string_len_set.size() ;i++) {
        pq.push(string_len_set[i]); 
    }
    int ret = 0 ;

    // 작은 값들 우선으로 계산 
    while(pq.size() > 1) {
        int n1 = pq.top(); pq.pop(); 
        int n2 = pq.top(); pq.pop();
        ret += (n1 + n2) ;
        pq.push(n1 + n2); 
    }

    return ret; 
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int testcase, input ; 
    cin >> testcase; 
    
    for(int i = 0 ; i < testcase; i++) {
        cin >> n; 
        for(int j = 0; j < n; j++) {
            cin >> input;
            string_len_set.push_back(input); 
        }   
        int result = solve(); 
        cout << result << '\n'; 
        string_len_set.clear(); 
    }

    return 0; 
}