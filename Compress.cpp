#include <iostream>
#include "Compress.h"

using namespace std;

void compress(const vector<unsigned char>& data, const unordered_map<unsigned char, string>& huffman_code, const string& compressed_filename) {
    vector<bool> encoded_bits;
    for (char byte : data) { // проходим по всем байтам
        string code = huffman_code.at(byte); // возвращает код Хафмана по текущему байту
        for (char bit : code) { // перебираем каждый бит из Хафмана
            encoded_bits.push_back(bit == '1');
        }
    }

    ofstream outFile(compressed_filename, ios::binary);
    if (!outFile) {
        cout << "Cannot open file for writing!" << endl;
        return;
    }

    int remaining_bits = encoded_bits.size() % 8;
    outFile.write(reinterpret_cast<const char*>(&remaining_bits), sizeof(remaining_bits)); // запись в начало файла первых (remaining_bits) битов

    for (int i = 0; i < encoded_bits.size(); i += 8) { // перебираем биты по блокам = 8 битов
        unsigned char byte = 0;
        for (int j = 0; j < 8 && (i + j) < encoded_bits.size(); ++j) { // составляем из 8 битов целый байт
            if (encoded_bits[i + j]) {
                byte |= (1 << (7 - j));
            }
        }
        outFile.write(reinterpret_cast<const char*>(&byte), sizeof(byte)); // запись полученного байта в файл
    }
    outFile.close();
    cout << "Encoded data written to " << compressed_filename<< endl;
}