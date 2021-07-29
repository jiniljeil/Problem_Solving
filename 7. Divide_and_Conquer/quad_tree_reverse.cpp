/*
Program: 쿼드 트리 뒤집기
Explanation: 
모든 픽셀이 검은 색 일 경우: b
모든 픽셀이 흰색 일 경우: w
모든 픽셀이 같은 색이 아닐 경우: x
위 과정을 통해 압축된 쿼드 트리를 상하로 뒤집은 쿼드 트리 출력 

INPUT:
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

Result:
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
*/

#include <iostream>
#define MAX 1000
using namespace std;

string reverse(string::iterator &itr) {
    char head = *(itr++); 

    if( head == 'b' || head == 'w') {
        return string(1, head); 
    }
    string upper_left = reverse(itr); 
    string upper_right = reverse(itr); 
    string lower_left = reverse(itr);
    string lower_right = reverse(itr); 

    return string("x") + lower_left + lower_right + upper_left + upper_right; 
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int num; 
    cin >> num; 
    string quad_form; 
    for(int i = 0 ; i < num; i++) {
        cin >> quad_form ; 
        string::iterator itr = quad_form.begin(); 
        string result = reverse(itr); 
        cout << result << '\n'; 
    }


    return 0;
}