#ifndef UTILS_HPP
#define UTILS_HPP

#include <unordered_map>
#include <map>
#include <string>
#include <vector>

namespace utils {

using frequency_dictionary = std::unordered_map<std::string, uintmax_t>;
using word_frequency = std::pair<std::string, uintmax_t>;

frequency_dictionary read_file_and_make_dict(const std::string& path);
std::vector<word_frequency> convert_dictionary_to_vector(const frequency_dictionary& dict);
void print_to_file(const std::string& path, const std::vector<word_frequency>& vec);

} // namespace utils

#endif // UTILS_HPP