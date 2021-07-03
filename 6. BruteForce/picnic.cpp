#include <iostream>
#include <vector> 
using namespace std; 

bool relationship[10][10]; 

int num_of_case(vector<bool> v) {
    int person = -1; 

    for(int i = 0 ; i < v.size(); i++) {
        if(!v[i]) {
            person = i; 
            break;
        }
    }
    if( person == -1) return 1; 
    int count = 0 ; 
    for(int _friend = person; _friend < v.size(); _friend++) {
        if( !v[_friend] && relationship[person][_friend]) {
            v[person] = v[_friend] = true; 
            count += num_of_case(v); 
            v[person] = v[_friend] = false; 
        }
    }

    return count; 
}

void clear() {
    for(int i = 0 ; i < 10; i++) {
        for(int j = 0 ;j < 10; j++) {
            relationship[i][j] = false;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    int num_test ; 

    cout << "Enter the number of test case: "; 
    cin >> num_test; 

    int a, b; 
    int c, d; 

    for(int i = 0 ; i < num_test; i++) {
        cin >> a >> b; 
        vector<bool> v(a); 
        for(int j = 0; j < b ; j++) {
            cin >> c >> d ; 
            relationship[c][d] = true; 
            relationship[d][c] = true;  
        }
        int num = num_of_case(v); 
        cout << num << '\n';
        clear(); 
    }
    return 0; 
}