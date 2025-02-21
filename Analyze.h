#ifndef Analyze
#define Analyze

#include <string>
#include <fstream>
#include <chrono>


int getFileSize(const std::string& filename);
void analyzeCompression(const std::string& input_file, const std::string& compressed_file, const std::string& decompressed_file);

#endif