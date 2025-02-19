#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void compress(const vector<char>& data, const unordered_map<char, string>& huffman_code) {
    vector<bool> encoded_bits;
    for (char byte : data) {
        string code = huffman_code.at(byte);
        for (char bit : code) {
            encoded_bits.push_back(bit == '1');
        }
    }
}

int main()
{
    cout << "Nadeusy eto zarabotaet" << endl;
}
