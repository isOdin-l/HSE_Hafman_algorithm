#include <iostream>
#include "Hafman_tree.h"

using namespace std;

// Это сохранение кодов в таблице вместе с обходом дерева
void encode(Node* root, string str, unordered_map<unsigned char, string>& hf_Code) {
    if (!root) return;
    if (!root->left && !root->right) {
        hf_Code[root->ch] = str;
    }
    encode(root->left, str + "0", hf_Code);
    encode(root->right, str + "1", hf_Code);
}
//Создание дерева Хаффмана
Node* build_Hf_Tree(const vector<unsigned char>& data, unordered_map<unsigned char, string>& hf_Code) {
    unordered_map<unsigned char, int> symb;
    for (unsigned char byte : data) {
        symb[byte]++;
    }
//Заполняет приоритетную очередь узлами
    priority_queue<Node*, vector<Node*>,  comp> pq;
    for (auto list : symb) {
         pq.push(new Node(list.first, list.second));
    }
    while (pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left->symb + right->symb;
        pq.push(new Node('\0', sum, left, right));
    }
    Node* root = pq.top();
    encode(root, "",hf_Code);
    return root;

}

