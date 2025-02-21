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
    
    if (remaining_bits != 0) { //удаляем лишние биты из конца массива, если есть оставшиеся биты
        decodedBits.resize(decodedBits.size() - (8 - remaining_bits));
    }
    inFile.close();

    vector<unsigned char> decodedData;
    Node* current = root;
    
    //проходим по всем битам и восстанавливаем исходные данные
    for (bool bit : decodedBits) {
        //переходим по дереву Хаффмана в заивисимости от знач.бита
        current = bit ? current->right : current->left;
        if (!current->left && !current->right) {  //если достигли лист дерева, добавляем символ в декодекодированные данные
            decodedData.push_back(current->ch);
            current = root; //возвращение к корню дерева
        }
    }
    ofstream outFile(decompressed_filename, ios::binary);
    if (!outFile) {
        cout << "Cannot open output file for writing!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(decodedData.data()), decodedData.size());
    outFile.close();
    cout << "Decoded data written to " << decompressed_filename << endl;
}
