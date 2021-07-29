/*
Program: 울타리 자르기 
Explanation: 
어떤 판자를 완전히 포함하는 사각형 중 면적이 최대인 사각형을 해당 판자의 최대 사각형이라고 한다. 
이 떄, 최대 사각형을 구해라. 

[스위핑 알고리즘 & 스택]

INPUT: 
8
4 5 7 8 5 6 3 2

OUTPUT:
25
*/

#include <iostream>
#include <stack> 
#include <vector> 
using namespace std; 

vector<int> V ;

void solve() { 
    stack<int> remain ;
    V.push_back(0); // 맨 오른쪽 높이 0 추가 
    int ret = 0; 
    for(int i = 0 ; i < V.size(); i++) {
        while(!remain.empty() && V[remain.top()] >= V[i]) {
            int j = remain.top(); 
            remain.pop(); 
            int width = -1; 

            if(remain.empty()) {
                width = i ; 
            }else{
                width = (i - remain.top() - 1); 
            }
            ret = max(ret, V[j] * width) ;
        }
        remain.push(i); 
    }

    cout << "MAX: " << ret << '\n'; 
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int num, t; 

    cin >> num; 
    
    for(int i = 0; i < num; i++) {
        cin >> t ;
        V.push_back(t); 
    }

    solve(); 
    return 0; 
}