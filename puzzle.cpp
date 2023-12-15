//
// Created by Vlad Isan on 05/12/2023.
//

#include "puzzle.h"

uint64_t puzzle_sample_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

uint64_t puzzle_sample_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

uint64_t puzzle_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

uint64_t puzzle_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

uint64_t do_puzzle_1(std::ifstream &file) {
    std::string line;
    std::getline(file, line);

    return hash(line);
}

uint64_t do_puzzle_2(std::ifstream &file) {
    std::string line;

    while (std::getline(file, line)) {
        fmt::println("{}", line);
    }

    return 0;
}

uint64_t hash(const std::string &str) {
    std::string seq{};
    std::istringstream iss(str);

    uint64_t sum = 0;

    while(std::getline(iss, seq, ',')) {
        uint64_t hash = 0;

        for (char c : seq) {
            hash += c;
            hash *= 17;
            hash %= 256;
        }

        sum += hash;
    }

    return sum;
}
