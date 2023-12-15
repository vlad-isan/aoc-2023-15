//
// Created by Vlad Isan on 05/12/2023.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <ranges>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "fmt/core.h"

struct Lens {
    std::string label{};
    uint64_t focal_length{};
};

using Box = std::list<Lens>;
using Boxes = std::unordered_map<uint64_t, Box>;
extern Boxes boxes;

uint64_t puzzle_sample_1(const std::string &base_file_path);
uint64_t puzzle_sample_2(const std::string &base_file_path);
uint64_t puzzle_1(const std::string &base_file_path);
uint64_t puzzle_2(const std::string &base_file_path);
uint64_t do_puzzle_1(std::ifstream &file);
uint64_t do_puzzle_2(std::ifstream &file);

uint64_t hash(const std::string &str);
uint64_t focusing_power();

#endif //PUZZLE_H
