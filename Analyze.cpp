#include "Analyze.h"
using namespace std;

void analyzeCompression(const string& input_file, const string& compress_file, const string& decompress_file) {
    // Измерение времени сжатия
    auto startCompression = chrono::high_resolution_clock::now();
    compress(input_file, compress_file);
    auto endCompression = chrono::high_resolution_clock::now();

    // Измерение времени декомпрессии
    auto startDecompression = chrono::high_resolution_clock::now();
    decompress(compress_file, decompress_file);
    auto endDecompression = chrono::high_resolution_clock::now();

    


