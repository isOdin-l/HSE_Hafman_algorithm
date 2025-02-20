include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){}

void decompressData(Node* root, const string& compressed_filename, const string& decompressed_filename) {
    //открываем файл с сжатыми данными для чтения в бин.режиме
    ifstream inFile(compressed_filename, ios::binary);
    if (!inFile) {
        cout << "Cannot open file for reading!" << endl;
        return;
    }
