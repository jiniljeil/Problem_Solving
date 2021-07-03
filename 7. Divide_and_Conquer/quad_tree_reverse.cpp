/*
INPUT 
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
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