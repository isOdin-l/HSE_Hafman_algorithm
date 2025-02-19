#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

void compress(const vector<char>& data, const unordered_map<char, string>& huffman_code, const string& compressed_filename) {
    vector<bool> encoded_bits;
    for (char byte : data) {
        string code = huffman_code.at(byte);
        for (char bit : code) {
            encoded_bits.push_back(bit == '1');
        }
    }

    ofstream outFile(compressed_filename, ios::binary);
    if (!outFile) {
        cout << "Cannot open file for writing!" << endl;
        return;
    }

    int remainingBits = encoded_bits.size() % 8;
    outFile.write(reinterpret_cast<const char*>(&remainingBits), sizeof(remainingBits));
}

int main()
{
    cout << "Nadeusy eto zarabotaet" << endl;
}
