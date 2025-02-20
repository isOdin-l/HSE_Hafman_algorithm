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
    
    char* remaining_bits; //кол-во ост. битов
    inFile.read(reinterpret_cast<char*>(&remaining_bits), sizeof(remaining_bits));
    
    vector<bool> decodedBits;
    <<<<<<< HEAD
    char byte;
    //читаем файл побайтово и преобразуем каждый байт в последовательность битов
    while (inFile.read(&byte, sizeof(byte))) {
        for (int i = 0; i < 8; ++i) {
            decodedBits.push_back((byte >> (7 - i)) & 1); //каждый бит из байта добавили в массив декодированных битов
        }
    }
    
    if (remainingBits != 0) { //удаляем лишние биты из конца массива, если есть оставшиеся биты
        decodedBits.resize(decodedBits.size() - (8 - remainingBits));
    }
    inFile.close();
    =======
    char byte;
    //читаем файл побайтово и преобразуем каждый байт в последовательность битов
    while (inFile.read(&byte, sizeof(byte))) {
        for (int i = 0; i < 8; ++i) {
            decodedBits.push_back((byte >> (7 - i)) & 1); //каждый бит из байта добавили в массив декодированных битов
        }
    }
    >>>>>>> decompress
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
