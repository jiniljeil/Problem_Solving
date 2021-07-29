/*
Program: JOSEPHUS 
Explanation:
첫 번째 병사 번호: 1
다른 사람들의 변호는 첫 번째 병사에서부터 시계 방향으로 정해진다. 
시계 방향으로 K 번째 살아 있는 사람 제거 

마지막 살아남는 두 사람의 번호를 오름차순으로 출력 

INPUT: 
2
6 3
40 3

OUTPUT: 
3 5 
11 26
*/

#include <iostream>
#include <list> 
#include <vector> 
using namespace std ;

// Linear 
void josephus(int n, int k) {
    list<int> survivors; 
    for(int i = 1; i <= n; i++) survivors.push_back(i); 

    list<int>::iterator kill = survivors.begin(); 
    list<int>::iterator itr ;
    while(n > 2) {
        kill = survivors.erase(kill); // 지운 다음 원소 RET 
        if(kill == survivors.end()) kill = survivors.begin(); 
        n--; 
        for(int i = 0 ; i < k - 1; i++) {
            kill++;
            if(kill == survivors.end()) kill = survivors.begin();
        }
    }
    cout << survivors.front() << " " << survivors.back() << '\n'; 
}

// MOD 사용
void josephus_m(int N, int K) {
    vector<int> T; 

    int rN = N;

    for(int i = 1 ; i <= N; i++) {
        T.push_back(i); 
    }
    int p = 0; 
    cout << "<" ;
    for(int i = 0 ; i < N - 1; i++) {
        cout << T[p] <<  ", "; 
        T.erase(T.begin() + p); 
        p += (K - 1); 
        if(p >= (--rN)) p %= (rN); 
    }
    cout << T[p] << ">"; 
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int testcase, N, K, i, rN; 
    cin >> testcase ;
    for(int k = 0 ; k < testcase ; k++) {
        cin >> N >> K ; 
        josephus(N,K);
        // josephus_m(N,K); 
    }

    return 0; 
}