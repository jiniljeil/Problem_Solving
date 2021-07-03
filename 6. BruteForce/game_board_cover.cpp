#include <iostream>

using namespace std; 

int row, col; 

// type, direction, x, y
int coverType[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}}, // 아래, 오른쪽 
    {{0, 0}, {1, 1}, {1, 0}},// 아래, 왼쪽 
    {{0, 0}, {0, 1}, {1, 1}},// 위, 왼쪽
    {{0, 0}, {0, 1}, {-1, 1}}  // 위, 오른쪽 
}; 

bool set(int value[21][21], int y, int x, int type, int v) {
    bool cover_check = true; 

    for(int i = 0 ; i < 3 ;i++) { 
        int dir_x = x + coverType[type][i][0]; 
        int dir_y = y + coverType[type][i][1]; 

        // Out of range
        if(dir_y < 0 || dir_y >= row || dir_x < 0 || dir_x >= col) { 
            cover_check = false; 
        // Covered space 
        }else if((value[dir_y][dir_x] += v) > 1) {
            cover_check = false ;
        }
    }
    return cover_check ;
}



int num_of_case(int value[21][21]){ 
    int y = -1, x = - 1;
    // Find the empty space
    for(int i = 0 ; i < row; i++) {
        for(int j = 0 ; j < col; j++) {
            if(value[i][j] == 0) {
                y = i; x = j ; 
                break;
            }
        }
        if( y != -1 ) break; 
    }

    // Completion
    if( y == -1 ) return 1; 
    
    int count = 0 ; 

    // Type 
    // **   **   *     *
    // *     *   **   **
    for(int type = 0 ; type < 4; type++) {
        // cover 
        if (set(value, y, x, type, 1)) {
            count += num_of_case(value);
        }
        // clear 
        set(value, y, x, type, -1);
    }

    return count; 
}

int main(void) {
    int num = 0; 

    char c; 
    int matrix[21][21]; 
    string m[21]; 
    printf("Enter the number of case: "); 
    scanf("%d", &num); 

    for(int k = 0 ; k < num ;k++) {
        scanf("%d %d", &row, &col); 
        for(int i = 0 ; i < row; i++) {
            cin >> m[i];
            for(int j = 0 ; j < m[i].length(); j++) {
                matrix[i][j] = (m[i][j] == '#') ? 1 : 0 ;
            }
        }
        int cnt = num_of_case(matrix); 
        printf("%d\n", cnt); 
    }


    return 0; 
}