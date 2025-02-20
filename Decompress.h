#ifndef Decompress
#define Decompress

#include <vector>
#include <unordered_map>
#include <fstream>
#include "Hafman_tree.h"

void decompress(Node* root, const std::string& compressed_filename, const std::string& decompressed_filename);

#endif