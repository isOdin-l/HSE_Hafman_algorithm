#ifndef HAFMAN_TREE
#define HAFMAN_TREE

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

struct Node {
    unsigned char ch; // Байт вместо символа
    int symb;
    Node* left, *right;

    // Конструктор
    Node(unsigned char ch, int symb, Node *left = nullptr, Node *right = nullptr)
            : ch(ch), symb(symb), left(left), right(right) {}
};

struct comp {
    bool operator()(Node* l, Node* r) {
        return l->symb > r->symb;
    }
};

Node* build_Hf_Tree(const std::vector<unsigned char>& data, std::unordered_map<unsigned char, std::string>& hf_Code);
void encode(Node* root, std::string str, std::unordered_map<unsigned char, std::string>& hf_Code);

#endif