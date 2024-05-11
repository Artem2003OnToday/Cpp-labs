#include "../include/lab_2.hpp"

#include <iostream>

namespace lab_2 {

Stream::Stream(const std::string& filename): os_(filename), filename_(filename) {
}

std::string Stream::getFilename() {
    return filename_;
}

void Stream::OpenFile() {
    os_.open(filename_);

    if (os_.fail()) {
        std::cerr << "cannot open file";
        return;
    }
}

void Stream::CloseFile() {
    os_.close();

    if (os_.fail()) {
        std::cerr << "cannot close file";
        return;
    }
}

bool Stream::IsOpen() {
    return os_.is_open();
}

void Stream::WriteInt(int num) {
    os_ << num;
    // os_.write(reinterpret_cast<char*>(&num), sizeof(num));
}

void Stream::WriteDouble(double num) {
    os_ << num;
    // os_.write(reinterpret_cast<char*>(&num), sizeof(num));
}

void Stream::WriteString(const std::string& s) {
    os_ << s;
    // os_.write(s.c_str(), sizeof(s));
}

}  // namespace lab_2