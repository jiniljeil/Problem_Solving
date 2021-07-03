/*
Program: 울타리 잘라내기 
Explanation: 각 판자의 높이가 주어질 때, 잘라낼 수 잇는 직사각형의 최대 크기를 계산하는 프로그램
(판자의 너비는 1로 가정)

Input: 
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4 
1 8 2 2

Result:
20
16
8
*/
#include <iostream>
#include <vector> 

using namespace std;

// 최대 20,000 이므로 1초 내에 문제 해결 불가 
int bruteForce(vector<int> h) {
    int ret = 0 ;
    int min_height = 0; 

    for(int left = 0 ; left < h.size(); left++) {
        min_height = h[left]; 
        for(int right = left; right < h.size(); right++) {
            min_height = min(min_height, h[right]); 
            ret = max(ret, (right - left + 1) * min_height);
        }
    }

    return ret ; 
}

int cut_bars(vector<int> h, int left, int right) {
    if (left == right) return h[left]; 

    int mid = (left + right)/2; 
    // Divide 
    int ret = max(cut_bars(h, left, mid), cut_bars(h, mid+1, right)); 

    int lo = mid, hi = mid + 1; 
    // 낮은 막대 기준
    int height = min(h[lo], h[hi]); 
    ret = max(ret, height * 2) ;

    // 큰 쪽 선택 
    while(left < lo || hi < right) {
        // 오른쪽이 큰 경우 
        if(hi < right && (left == lo || h[lo-1] < h[hi+1]) ) {
            hi++; 
            height = min(height, h[hi]);
        // 왼쪽이 큰 경우 
        }else{
            lo--;
            height = min(height, h[lo]); 
        }
        // 넓이 구하기 
        ret = max(ret, height * (hi - lo + 1)); 
    }

    return ret; 
}   

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int num, k; 
    int tmp; 
    vector<int> h ;

    cin >> num; 

    for(int i = 0 ; i < num; i++) {
        cin >> k ;
        for(int j = 0;  j < k ; j++) {
            cin >> tmp ;
            h.push_back(tmp); 
        }
        // int result = bruteForce(h); 
        int result = cut_bars(h, 0, h.size()-1);

        cout << result << '\n'; 
        h.clear(); 
    }
    return 0;
}