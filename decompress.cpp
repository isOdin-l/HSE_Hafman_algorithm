#include <iostream>
#include "Decompress.h"

using namespace std;

void decompress(Node* root, const string& compressed_filename, const string& decompressed_filename) {
    //открываем файл с сжатыми данными для чтения в бин.режиме
    ifstream inFile(compressed_filename, ios::binary);
    if (!inFile) {
        cout << "Cannot open file for reading!" << endl;
        return;
    }
    
    int remaining_bits; //кол-во ост. битов
    inFile.read(reinterpret_cast<char*>(&remaining_bits), sizeof(remaining_bits));
    
    vector<bool> decodedBits;
    char byte;
    //читаем файл побайтово и преобразуем каждый байт в последовательность битов
    while (inFile.read(&byte, sizeof(byte))) {
        for (int i = 0; i < 8; ++i) {
            decodedBits.push_back((byte >> (7 - i)) & 1); //каждый бит из байта добавили в массив декодированных битов
        }
    }
}
