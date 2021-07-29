/*
Program: brackets2 
Explanation: 
짝이 맞지 않는 괄호: NO
짝이 맞는 괄호: YES 
() {} []
*/

#include <iostream> 
#include <stack> 
#include <string> 
using namespace std ;

bool matched(string str) {
    stack<char> S; 

    for(int i = 0 ; i < str.length(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            S.push(str[i]); 
        }else {
            if(S.empty()) return false; 

            if(str[i] == ')' && S.top() == '(') {
                S.pop(); 
            }else if(str[i] == '}' && S.top() == '{') {
                S.pop();
            }else if(str[i] == ']' && S.top() == '[') {
                S.pop(); 
            }else{
                return false; 
            }
        }
    }
    return S.empty(); 
}

bool match(string str) { 
    stack<char> S; 
    const string opening("({["), closing(")}]"); 

    for(int i = 0 ; i < str.length(); i++) {
        if (opening.find(str[i]) != -1) {
            S.push(str[i]); 
        }else{
            // 비어있는 경우 
            if (S.empty()) return false ;
            if (opening.find(S.top()) != closing.find(str[i])) return false; 
            S.pop(); 
        }
    }
    return S.empty(); 
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int num; 

    cin >> num; 

    for(int i = 0 ; i < num; i++) {
        string str; 
        cin >> str ;
        bool check = matched(str); 
        cout << ((check) ? "YES" : "NO") << "\n";
    }
    return 0; 
}