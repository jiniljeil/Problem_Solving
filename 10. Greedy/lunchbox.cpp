/*
Program: LANCHBOX 
Explanation: 
각 도시락을 데우는 데 걸리는 시간, 각 도시락을 먹는데 걸리는 시간이 주어질 때 
점심을 먹는데 걸리는 최소 시간 구하기 

INPUT: 
2
3
2 2 2
2 2 2
3
1 2 3
1 2 1

RESULT: 
8
7
*/
#include <iostream>
#include <algorithm>
#include <vector> 
#define MAX 10001

using namespace std ;

// 데우는 시간, 먹는 시간 
int D[MAX], E[MAX]; 
int n; 
int solve(){ 
    vector<pair<int,int> > order; 
    // 빨리 데울 수 있는 것부터 먹는게 최적
    for(int i = 0 ; i < n ; i++) {
        order.push_back(make_pair(-D[i], i)); 
    } 
    sort(order.begin(), order.end()); 
    int ret = 0 ; int beginEat = 0 ; 
    for(int i = 0 ; i < n; i++) {
        int idx = order[i].second; 
        beginEat += E[idx] ;
        ret = max(ret, beginEat + D[idx]); 
    }
    return ret; 
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int testcase; 
    
    cin >> testcase; 
    
    for(int i = 0 ; i < testcase ; i++) {
        cin >> n; 
        for(int j = 0; j < n; j++) {
            cin >> D[j]; 
        }
        for(int j = 0; j < n; j++) {
            cin >> E[j]; 
        }
        int result = solve(); 
        cout << result << '\n';
    }
    return 0; 
}
