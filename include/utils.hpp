#ifndef UTILS_HPP
#define UTILS_HPP

#include <unordered_map>
#include <string>
#include <vector>

namespace utils {

using frequency_dictionary = std::unordered_map<std::string, uintmax_t>;
using word_frequency = std::pair<std::string, uintmax_t>;

void normalize_str(std::string& str);
void parse_str_and_update_dict(const std::string& str, frequency_dictionary& dict);
frequency_dictionary read_file_and_make_dict(const std::string& path);
std::vector<word_frequency> convert_dictionary_to_vector(const frequency_dictionary& dict);
void print_to_file(const std::string& path, const std::vector<word_frequency>& vec);

} // namespace utils

#endif // UTILS_HPP