#pragma once

#include <fstream>

namespace lab_2 {

class Stream {
public:
    Stream() = default;
    Stream(const std::string& filename);
    std::string getFilename();
    void OpenFile();
    void CloseFile();
    bool IsOpen();
    void WriteInt(int num);
    void WriteDouble(double num);
    void WriteString(const std::string& s);
private:
    std::ofstream os_;
    std::string filename_;
};

}  // namespace lab_2