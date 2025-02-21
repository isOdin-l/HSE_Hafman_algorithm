#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

// Подключаем файлы
#include "Hafman_tree.h"
#include "Compress.h"
#include "Decompress.h"
#include "Analyze.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    vector<vector<string>> files = {
        {"input", "txt"},  // Текстовый файл
        {"input", "bmp"},  // Изображение
        {"input", "wav"}   // Аудио
    };

    for (int i = 0; i < files.size(); ++i) {
        string file = files[i][0] + "." + files[i][1];
        string compressedFile = files[i][0] + "_" + files[i][1] + "_comp.bin";
        string decompressedFile = files[i][0] + "_decomp." + files[i][1];
        
        analyzeCompression(file, compressedFile, decompressedFile);
    }
}