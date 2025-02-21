#include <iostream>
#include "Analyze.h"
#include "Compress.h"
#include "Decompress.h"

using namespace std;

int getFileSize(const std::string& filename){
     ifstream file(filename, ios::binary);
     if (!file) {
          cout << "Cannot open file: " << filename << endl;
          return 0;
     }
     file.seekg(0, ios::end);
     int size = file.tellg();
     file.close();
     return size;
}

void analyzeCompression(const string& input_file, const string& compress_file, const string& decompress_file) {
     ifstream inputFile(input_file, ios::binary);
     if (!inputFile) {
         cerr << "Cannot open input file: " << input_file << endl;
         return;
     }
     vector<unsigned char> data((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
     inputFile.close();
 
     // Построение дерева Хаффмана и генерация кодов
     unordered_map<unsigned char, string> huffman_code;
     Node* root = build_Hf_Tree(data, huffman_code);
 
     // Измерение времени сжатия
     cout << endl;
     auto startCompression = chrono::high_resolution_clock::now();
     compress(data, huffman_code, compress_file);
     auto endCompression = chrono::high_resolution_clock::now();
 
     // Измерение времени декомпрессии
     auto startDecompression = chrono::high_resolution_clock::now();
     decompress(root, compress_file, decompress_file);
     auto endDecompression = chrono::high_resolution_clock::now();
     
     cout << endl;

     // Получение размера файлов
     int originalSize = getFileSize(input_file);
     int compressedSize = getFileSize(compress_file);
 
     // Вычисление коэффициента сжатия
     double compressionRatio = static_cast<double>(originalSize) / compressedSize;
 
     // Вывод результатов
     cout << "Анализ эффективности для файла: " << input_file << endl;
     cout << "Размер исходного файла: " << originalSize << " байт" << endl;
     cout << "Размер сжатого файла: " << compressedSize << " байт" << endl;
     cout << "Коэффициент сжатия: " << compressionRatio << endl;
     cout << "Время сжатия: "
          << chrono::duration_cast<chrono::milliseconds>(endCompression - startCompression).count()
          << " мс" << endl;
     cout << "Время декомпрессии: "
          << chrono::duration_cast<chrono::milliseconds>(endDecompression - startDecompression).count()
          << " мс" << endl;
}