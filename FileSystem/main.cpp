#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;


uintmax_t get_file_size(const std::filesystem::path &path) {
    if (std::filesystem::exists(path) && std::filesystem::is_regular_file(path)) {
        try {
            auto size = std::filesystem::file_size(path);
            return size;
        } catch (std::filesystem::filesystem_error error) {
            return static_cast<uintmax_t>(-1);
        }
    }

    return std::numeric_limits<uintmax_t>::max();
}

void print_directory(const fs::path &my_path, int level) {
    if (fs::exists(my_path)) {
        if (fs::is_regular_file(my_path)) {
            for (auto i = 0; i < level; ++i) {
                std::cout << "\t";
            }
            std::cout << my_path.filename() << std::endl;
            return;
        }
        for (auto &entry : fs::directory_iterator(my_path)) {
            print_directory(entry.path(), level + 1);
        }
    }
}


int main() {

    //learning a little about file-systems

    fs::path my_path("/home/robin/DarkHorse/Checkers/CheckerEngineX");
    std::cout << "Exists:" << fs::exists(my_path) << std::endl;
    std::cout << "Root_Name: " << my_path.root_name() << std::endl;
    std::cout << "Root_Path: " << my_path.root_path() << std::endl;
    std::cout << "File_Name: " << my_path.filename() << std::endl;
    std::cout << "\n";
    std::cout << my_path << std::endl;

    std::cout << "I am curious if that works" << std::endl;
    std::cout << "Size of uintmax_t" << std::numeric_limits<uintmax_t>::max() << std::endl;

    std::cout << "File_Size: " << get_file_size(my_path) << std::endl;


    return 0;
}
