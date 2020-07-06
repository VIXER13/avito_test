#include "utils.hpp"
#include <fstream>

namespace utils {

void normalize_str(std::string& str) {
    for(auto& it : str) {
        if((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z')) {
            it = std::tolower(it);
        } else {
            it = ' ';
        }
    }
}

void parse_str_and_update_dict(const std::string& str, frequency_dictionary& dict) {
    std::string substr;
    size_t prev_pos = 0, curr_pos = str.find(' ');
    while(curr_pos != std::string::npos) {
        if(curr_pos - prev_pos > 1) {
            substr = str.substr(prev_pos, curr_pos - prev_pos);
            auto it = dict.find(substr);
            if (it == dict.end()) {
                dict.emplace(std::move(substr), 1);
            } else {
                ++it->second;
            }
        }
        prev_pos = curr_pos + 1;
        curr_pos = str.find(' ', prev_pos);
    }
}

frequency_dictionary read_file_and_make_dict(const std::string& path) {
    std::ifstream fin{std::string{path}};
    frequency_dictionary dict;
    std::string line;
    while(std::getline(fin, line)) {
        normalize_str(line);
        parse_str_and_update_dict(line, dict);
    }
    return std::move(dict);
}

std::vector<word_frequency> convert_dictionary_to_vector(const frequency_dictionary& dict) {
    std::vector<word_frequency> vec;
    vec.reserve(dict.size());
    for (const auto& it : dict) {
        vec.push_back(it);
    }
    return std::move(vec);
}

void print_to_file(const std::string& path, const std::vector<word_frequency>& vec) {
    std::ofstream fout{path};
    for(const auto& it : vec) {
        fout << it.second << " " << it.first << std::endl;
    }
}

}