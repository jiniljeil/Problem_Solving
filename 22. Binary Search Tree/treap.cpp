/*
Program: treap (tree + heap) 
Explanation: 
Binary Search Tree 에서 skewed 한 것을 막기 위해 
각 원소에 우선순위를 랜덤화를 사용하여 지정해주어 binary search tree 를 구성 

1. 이진 검색 트리 조건:
   모든 노드에 대해 왼쪽 서브트리에 있는 노드들의 원소는 해당 노드의 원소보다 작고, 
   오른쪽 서브트리에 있는 노드들의 원소는 해당 노드의 원소보다 큽니다. 
2. 힙의 조건: 
   모든 노드의 우선순위는 각자의 자식 노드보다 크거나 같습니다. 
*/

#include <iostream> 

typedef int KeyType; 
using namespace std; 

struct Node { 
    KeyType key; 
    // 이 노드의 우선 순위 (priority) 
    // 이 노드를 루트로 하는 서브트리의 크기 (size)
    int priority, size; 
    Node *left, *right; 
    // 생성자에서 난수 우선순위를 생성하고, size 와 left/right 초기화 
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node * newLeft) {left = newLeft; calcSize(); }
    void setRight(Node * newRight) {right = newRight; calcSize(); }
    void calcSize() {
        size = 1; 
        if(left) size += left->size;  
        if(right) size += right->size; 
    }
}

typedef pair<Node*, Node*> NodePair ;

// root 를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는 두 개의 트립으로 분리 
NodePair split(Node* root, keyType key) {
    if(root == NULL) return NodePair(NULL, NULL) ;
    
    //  루트가 key 미만이면 오른쪽 서브 트리를 쪼갠다. 
    if(root->key < key) {
        NodePair rs = split(root->right, key); 
        root->setRight(rs.first); 
        return NodePair(root, rs.second); 
    // 루트가 key 보다크면 왼쪽 서브 트리를 쪼갠다. 
    }else{
        NodePair ls = split(root->left, key) ;
        root->setLeft(ls.second) ;
        return NodePair(ls.first, root); 
    }
}

Node* insert(Node* root, Node* node) {
    if(root == NULL) return node; 

    // root 보다 node 가 우선 순위가 높은 경우 
    // node 를 root 로 바꿔줘야하기 때문에 split
    if(root->priority < node->priority) {
        NodePair splitted= split(root, node->key); 
        node->setLeft(splitted.first); 
        node->setRight(splitted.second); 
        return node; 
    // root 보다 node 가 우선 순위가 낮은 경우     
    }else{
        if (root->key < node->key) {
            root->setRight(insert(root->right, node)); 
        }else{
            root->setLeft(insert(root->left, node));
        }
    }
    return root; 
}

Node* marge(Node* a , Node* b) {
    if (a == NULL) return b ;
    if (b == NULL) return a ;
    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left)); 
        return b ;
    }else{
        a->setRight(merge(a->right, b));
        return a; 
    }
}

Node* erase(Node *root, keyType key) {
    if (root == NULL) return root; 

    if(root->key == key) {
        Node * ret = merge(root->left, root->right); 
        delete root; 
        return ret; 
    }else{ 
        if(key < root->key) {
            root->setLeft(erase(root->left, key)); 
        }else{
            root->setright(erase(root->right, key)); 
        }
    }
    return root ;
}

Node* kth(Node* root, int k) {
    // 왼쪽 서브 트리 크기 계산 
    int leftSize = 0 ; 
    if(root->left != NULL) leftSize = root->left->size; 
    if(k <= leftSize) {
        return kth(root->left, k);
    }else{
        return kth(root->right, k - leftSize - 1) ;
    }
}

int countLessThan(Node* root, KeyType key) {
    if(root == NULL) return 0 ;
    if(root->key >= key) {
        return countLessThan(root->left, key); 
    }
    int ls = (root->left ? root->left->size : 0) ; 
    return ls + 1 + countLessThan(root->right, key); 
}
