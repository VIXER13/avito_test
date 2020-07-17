#include "utils.hpp"
#include <fstream>

namespace utils {

using alphabet = std::array<char, 256>;

static alphabet make_filter() noexcept {
    alphabet filter = {};
    for(size_t c = 0; c < filter.size(); ++c) {
        filter[c] = std::tolower(c);
        if(filter[c] < 'a' || filter[c] > 'z') {
            filter[c] = '\0';
        }
    }
    return filter;
}

static const alphabet filter = make_filter();

static void parse_str_and_update_dict(std::string& str, frequency_dictionary& dict) {
    size_t pos = 0;
    std::string substr;
    for(size_t i = 0; i < str.size(); ++i) {
        str[i] = filter[str[i]];
        if(str[i] == '\0') {
            if(i - pos > 1) {
                substr = str.substr(pos, i - pos);
                auto res = dict.try_emplace(std::move(substr), 0);
                ++res.first->second;
            }
            pos = i+1;
        }
    }
}

frequency_dictionary read_file_and_make_dict(const std::string& path) {
    std::ifstream fin{std::string{path}};
    frequency_dictionary dict;
    std::string line;
    while(std::getline(fin, line)) {
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
        fout << it.second << ' ' << it.first << '\n';
    }
}

}