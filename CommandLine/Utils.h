
#include <vector>
#include <string>
#include <sstream>
namespace Utils {
    inline std::vector<std::string> getWhiteSpaceSeperated(const std::string msg) {
        std::vector<std::string> result;
        std::istringstream stream(msg);
        std::string current;
        while (stream >> current) {
            result.emplace_back(current);
        }
        return result;
    }

    inline std::vector<std::string> getDelimiterSeperated(const std::string message, const std::string delimiter) {
        size_t counter = 0;
        std::vector<std::string> result;

        for (size_t i = 0; i < message.size(); i += delimiter.size()) {
            size_t pos = message.find(delimiter, i);
            pos = std::min(pos, message.size());
            size_t length = pos - i;
            std::string word = message.substr(i, length);
            i += length;
            result.emplace_back(word);
        }

        return result;
    }

}

