/*
Program: 원주율 외우기
Explanation: 
원주율의 일부가 입력으로 주어질 때, 
난이도의 합을 최소화 하도록 숫자들을 세 자리에서 다섯 자리까지 끊어 읽어 최소의 난이도를 계산 

1. 모든 숫자가 같을 때 (난이도: 1) 
2. 숫자가 1씩 단조 증가하거나 단조 감소할 때 (난이도: 2)
3. 두 개의 숫자가 번갈아가며 나타날 때 (난이도: 4) 
4. 숫자가 등차 수열을 이룰 때 (난이도: 5)
5. 그 외의 모든 경우 (난이도: 10) 

INPUT:
5
12341234
11111222
12122222
22222222
12673939

RESULT:
4
2
5
2
14
*/

#include <iostream>
#include <string.h> 
#define INF 1e8 
using namespace std;
string str ;
int dp[10001]; 

int classify(int a, int b) {
    string s = str.substr(a, b-a); 
    // 같은 숫자로만 이루어진 경우 

    if(s == string(s.size(), s[0])) return 1; 

    // 숫자가 등차 수열을 이룰 때
    int diff = s[1] - s[0]; 
    bool diff_seq = true; 
    for(int i = 0 ; i < s.size() - 1; i++) {
        if(diff != s[i+1] - s[i]) {
            diff_seq = false; 
        }
    }

    // 숫자가 1씩 단조 증가하거나 단조 감소할 때 
    if (diff_seq && (diff == 1 || diff == -1)) return 2; 

    // 두 개의 숫자가 번갈아가며 나타날 때 
    char one = s[0], two = s[1]; 
    bool ch = true; 
    for(int i = 0 ; i < s.size(); i++) {
        if( !((i % 2 == 0 && s[i] == one) || (i % 2 != 0 && s[i] == two))) {
            ch = false; 
        }
        /*
        if( s[i] != s[i%2]) ch = false;
        */
    }
    if(ch) return 4; 
    if(diff_seq) return 5; 
    // 그 외 모든 경우 
    return 10; 
}

int memorize(int begin) {
    if( begin == str.size()) return 0;
    int &ret = dp[begin]; 
    if( ret != -1) return ret; 
    ret = INF; 
    for(int L = 3 ; L <= 5 ; L++) {
        if( begin + L <= str.size())
            ret = min(ret, memorize(begin+L)) + classify(begin, begin+L-1);
    }
    return ret; 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int num ;
    cin >> num; 

    for(int i = 0 ;i < num; i++) {
        cin >> str; 
        memset(dp, -1, sizeof(dp)); 
        int result = memorize(0); 
        cout << result << '\n';
    }
    return 0;
}