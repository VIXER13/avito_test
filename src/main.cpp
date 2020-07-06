#include <iostream>
#include <algorithm>
#include <exception>
#include "utils.hpp"

namespace file_type {
static constexpr size_t IN = 1, OUT = 2;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "Error: input format <program_name> [file.in] [file.out]" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        using namespace utils;
        const auto dict = read_file_and_make_dict(argv[file_type::IN]);
        auto vec = convert_dictionary_to_vector(dict);
        std::sort(vec.begin(), vec.end(), 
            [](const word_frequency& lhs, const word_frequency& rhs) {
                return lhs.second == rhs.second ? lhs.first  < rhs.first :
                                                  lhs.second > rhs.second;
        });
        print_to_file(argv[file_type::OUT], vec);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch(...) {
        std::cerr << "???" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}