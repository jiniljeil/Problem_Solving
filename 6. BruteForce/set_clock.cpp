#include <iostream> 
#define CLOCKS 16
#define SWITCH_NUM 10 
#define INF 1e8
using namespace std; 

char switch_linked[SWITCH_NUM][CLOCKS+1] = { 
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x..",
};

bool finish(int clock_set[12]) {
    for(int i = 0 ; i < 12 ; i++) {
        if(clock_set[i] != 12) {
            return false;
        }
    }
    return true; 
}

void set(int clock_set[12], int type) {
    for(int i = 0 ; i < CLOCKS; i++) {
        if (switch_linked[type][i] == 'x') {
            clock_set[i] += 3 ;
            if (clock_set[i] == 15) clock_set[i] = 3; 
        }
    }
}
int solve(int clock_set[12], int swtch) {
    if (swtch == SWITCH_NUM) return finish(clock_set) ? 0 : INF; 
    int ret = INF; 

    for(int cnt = 0 ; cnt < 4 ; cnt++) {
        ret = min(ret, cnt + solve(clock_set, swtch + 1));
        set(clock_set, swtch); 
    }
    return ret ;
}

int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0);

    int num ;
    cin >> num ;

    for(int i = 0 ; i < num; i++) {
        int clock_set[12]; 
        for(int j = 0 ; j < 12; j++) {
            cin >> clock_set[j] ;
        }
        int cnt = solve(clock_set, 0); 
        cout << cnt << '\n'; 
    }

    return 0; 
}