#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

// Подключаем файлы
#include "Hafman_tree.h"
#include "Compress.h"
#include "Decompress.h"

using namespace std;

int main(){
    string input_file = "input.txt";
    string compress_file = "compress.bin";
    string decompress_file = "decompress.txt";

    ifstream inputFile(input_file, ios::binary);
    if (!inputFile) {
        cout << "Cannot open input file!" << endl;
        return -1;
    }

    vector<unsigned char> data((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    unordered_map<unsigned char, string> huffman_code;
    Node* root = build_Hf_Tree(data, huffman_code);
    compress(data, huffman_code, compress_file);
    decompress(root, compress_file, decompress_file);
}