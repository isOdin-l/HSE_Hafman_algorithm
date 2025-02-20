#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
// Узел
struct Node {
    unsigned char ch;
    int symb;
    Node *left, *right;

    // Конструктор
    Node(unsigned char ch, int symb, Node *left = nullptr, Node *right = nullptr)
            : ch(ch), symb(symb), left(left), right(right) {}
};
// Упорядачиваем кучу с помощью объекта сравнения
struct comp {
    bool operator()(Node* l, Node* r) {
        return l->symb > r->symb;
    }
};

// Это сохранение кодов в таблице вместе с обходом дерева
void encode(Node* root, string str, unordered_map<unsigned char, string>& hf_Code) {
    if (!root) return;
    if (!root->left && !root->right) {
        hf_Code[root->ch] = str;
    }
    encode(root->left, str + "0", hf_Code);
    encode(root->right, str + "1", hf_Code);
}
// 1. Создание дерева Хаффмана
Node* build_Hf_Tree(const vector<unsigned char>& data, unordered_map<unsigned char, string>& build_Hf_Tree) {
    unordered_map<unsigned char, int> symb;
    for (unsigned char byte : data) {
        symb[byte]++;
    }
//Заполняет приоритетную очередь узлами
    priority_queue<Node*, vector<Node*>,  comp> pq;
    for (auto list : symb) {
         pq.push(new Node(list.first, list.second));
    }

}
int main(){
};

