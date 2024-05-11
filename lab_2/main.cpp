#include "include/lab_2.hpp"

#include <iostream>

namespace lab_2 {

enum Commands {
    kSetFilename, kWriteInt, kWriteString, kWriteDouble, kGetFilename, kExit,
};

void PrintCommands() {
    std::cout << "-----------------" << std::endl;
    std::cout << "0 - set filename" << std::endl;
    std::cout << "1 - write int" << std::endl;
    std::cout << "2 - write string" << std::endl;
    std::cout << "3 - write double" << std::endl;
    std::cout << "4 - get filename" << std::endl;
    std::cout << "5 - exit" << std::endl;
}

class Menu {
public:
    Menu() {
    }
    std::string GetFilename() {
        return stream.getFilename();
    }

    bool StreamWithoutFilename() {
        return GetFilename().empty();
    }
    void OpenStream() {
        if (!stream.IsOpen()) {
            stream.OpenFile();
        }
    }
    void CloseStream() {
        if (stream.IsOpen()) {
            stream.CloseFile();
        }
    }
    void ChangeOrSetFilename(const std::string& filename) {
        stream = Stream(filename);
    }
    void WriteInt(int num) {
        if (stream.IsOpen()) {
            stream.WriteInt(num);
        }
    }
    void WriteDouble(double num) {
        if (stream.IsOpen()) {
            stream.WriteDouble(num);
        }
    }
    void WriteString(std::string s) {
        if (stream.IsOpen()) {
            stream.WriteString(s);
        }
    }
private:
    Stream stream;
};

}  // namespace lab_2

int main() {
    using namespace lab_2;

    Menu menu{};
    while (1) {
        if (menu.StreamWithoutFilename()) {
            std::string filename;
            std::cout << "write filename: ";
            std::cin >> filename;

            menu.ChangeOrSetFilename(filename);
            continue;
        }

        int type;
        PrintCommands();
        std::cout << "write command: ";
        std::cin >> type;

        switch (type) {
            case Commands::kSetFilename: {
                std::string filename;
                std::cin >> filename;
                menu.ChangeOrSetFilename(filename);
            } break;
            case Commands::kGetFilename: {
                std::cout << "current filename: " << menu.GetFilename() << std::endl;
            } break;
            case Commands::kWriteInt: {
                int num;
                std::cout << "which interger do you want to save to the file?"
                    << std::endl << "write int: ";
                std::cin >> num;
                menu.WriteInt(num);
            } break;
            case Commands::kWriteDouble: {
                double num;
                std::cout << "which double do you want to save to the file?"
                    << std::endl << "write double: ";
                std::cin >> num;
                menu.WriteDouble(num);
            } break;
            case Commands::kWriteString: {
                std::string s;
                std::cout << "which string do you want to save to the file?"
                    << std::endl << "write string: ";
                std::cin >> s;
                menu.WriteString(s);
            } break;
            case Commands::kExit: {
                std::cout << "goodbye";
                menu.CloseStream();
                return 0;
            }
        }
    }
}