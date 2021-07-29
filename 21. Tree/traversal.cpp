/*
Program: TRAVERSAL 
Explanation: 
preorder, inorder 가 주어졌을 때, postorder 를 출력 

INPUT: 
1
7
27 16 9 12 54 36 72
9 12 16 27 36 54 72

OUTPUT:
12 9 16 36 72 54 27
*/

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std ;

vector<int> slice(const vector<int> &v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b) ;
}

void printPostOrder(const vector<int> &preorder, const vector<int> &inorder) {
    if (preorder.empty()) return ;
    const int N = preorder.size(); 
    const int root = preorder[0]; 
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - 1 - L ;
    
    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N)); 
    cout << root << ' '; 
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int testcase, n, t;
    cin >> testcase ;

    for(int i = 0 ; i < testcase ; i++) {
        cin >> n ;
        vector<int> preorder, inorder ; 

        for(int j = 0; j < n; j++) {
            cin >> t ; 
            preorder.push_back(t);
        }
        for(int j = 0; j < n; j++) {
            cin >> t ;
            inorder.push_back(t); 
        }
        printPostOrder(preorder, inorder); 
        cout << '\n';
    }

    return 0; 
}