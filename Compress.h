#ifndef Compression
#define Compression

#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

void compress(const std::vector<unsigned char>& data, const std::unordered_map<unsigned char, std::string>& huffman_code, const std::string& compressed_filename);

#endif