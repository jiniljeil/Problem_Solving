/*
Program: NERD2
Explanation:
너드인가, 너드가 아닌가? 

- 알고스팟 온라인 채점 시스템에서 푼 문제수 p 
- 밤 새면서 지금까지 끓여먹은 라면 그릇 수 q 

pa < pb, qa < qb 이면 a 유저는 참여 X 
시간 제한: 2 초 
참가 신청한 사람 수 (1 <= N <= 50000)

INPUT: 
2
4
72 50
57 67
74 55
64 60
5
1 5
2 4
3 3
4 2
5 1

OUTPUT:
8
15
*/

#include <iostream>
#include <map>

using namespace std ;

map<int, int> coordinates; 

// 새로운 점 (x, y)가 기존의 다른 점들에 지배당하는지 확인한다. 
bool isDominated(int x, int y) {
    // x보다 오른족에 있는 점 중 가장 왼쪽에 있는 점을 찾는다. 
    map<int,int>::iterator itr = coordinates.lower_bound(x); 
    // 그런 점이 없으면 (x, y)는 지배당하지 않는다. 
    if(itr == coordinates.end()) return false; 
    // x 보다 오른쪽에 있는 점 중 가장 위에 있는 점이므로, 
    // (x, y)가 어느 점에 지배되려면 이 점에도 지배되어야 한다. 
    return y < itr->second; 
}

// 새로운 점 (x, y)에 지배당하는 점들을 트리에서 지운다. 
void removeDominated(int x, int y) {
    map<int,int>::iterator itr = coordinates.lower_bound(x); 
    // (x, y)보다 왼쪽에 있는 점이 없다. 
    if(itr == coordinates.begin()) return ;
    --itr;  
    // 반복문 불변식: itr 는 (x, y)의 바로 왼쪽에 있는 점
    while(true) {
        // (x, y) 바로 왼쪽에 오는 점을 찾는다. 
        // itr 가 표시하는 점이 (x, y)에 지배되지 않는다면 종료 
        if(itr->second > y) break;
        // 이전 점이 더 없으므로 itr 만 지우고 종료 
        if(itr == coordinates.begin()) {
            coordinates.erase(itr);
            break; 
        // 이전 점으로 iterator 를 하나 옮겨 놓고 itr 지운다. 
        }else{
            map<int,int>::iterator jt = itr;
            jt--;
            coordinates.erase(itr);
            itr = jt ;
        }
    }
}

// 새 점 (x, y)가 추가되었을 때 coordinates 를 갱신 
// 다른 점에 지배당하지 않는 점들의 개수를 반환 
int registered(int x, int y) {
    // (x, y) 가 이미 지배당하는 경우에는 그냥 (x, y)를 버린다.  
    if(isDominated(x,y)) return coordinates.size(); 
    // 기존에 있던 점 중 (x, y)에 지배당하는 점들을 지운다. 
    removeDominated(x, y); 
    coordinates[x] = y; 
    return coordinates.size();
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int testcase, applicants ;
    int p, q; 
    cin >> testcase; 

    for(int i = 0 ; i < testcase; i++) {
        cin >> applicants;
        int size = 0 ; 
        for(int j = 0 ; j < applicants; j++) {
            cin >> p >> q; 
            size += registered(p, q); 
        }
        cout << size << '\n';
    }
    return 0; 
}