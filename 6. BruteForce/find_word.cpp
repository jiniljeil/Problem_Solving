#include <iostream>
#include <stdlib.h> 

using namespace std; 

char matrix[5][5] = { 
    {'U','R','L','P','M'}, 
    {'X','P','R','E','T'}, 
    {'G','I','A','E','T'}, 
    {'X','T','N','Z','Y'}, 
    {'X','O','Q','R','S'}
};

int dx[8] = {-1, -1, -1,  0,  1, 1, 1, 0}; 
int dy[8] = { 1,  0, -1, -1, -1, 0, 1, 1};

int find_word(int y, int x, string word){
    if (y < 0 || y >= 5 || x < 0 || x >= 5) return 0; 
    if (matrix[y][x] != word[0]) return 0; 
    if (word.size() == 1) return 1; 
    for (int i = 0 ; i < 8; i++) {
        int dir_y = y + dy[i]; 
        int dir_x = x + dx[i]; 

        if(find_word(dir_y, dir_x, word.substr(1))) {
            return 1; 
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0) ;
    string word ; 

    cout << "Enter a finding word: "; 
    cin >> word ; 

    for (int i = 0 ; i < 5 ;i++) {
        for(int j = 0; j < 5; j++) {
            if (word[0] == matrix[i][i]) {
                if (find_word(i,j, word) == 1 ) { 
                    cout << "EXIST!" << '\n'; 
                    exit(1); 
                }
            }
        }
    }
    cout << "NOTHING!" << '\n'; 
    return 0; 
}