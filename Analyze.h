#ifndef Analyze
#define Analyze

namespace fs = std::filesystem;

int getFileSize(const string& file) {
    return fs::file_size(file);
}

void analyzeCompression(const string& input_file, const string& compressed_file, const string& decompressed_file)

#endif