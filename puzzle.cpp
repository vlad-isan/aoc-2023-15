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

    std::string seq{};
    std::istringstream iss(line);

    uint64_t sum = 0;

    while (std::getline(iss, seq, ',')) {
        sum += hash(seq);
    }

    return sum;
}

Boxes boxes{};

uint64_t do_puzzle_2(std::ifstream &file) {
    std::string line;
    std::getline(file, line);

    std::string seq{};
    std::istringstream iss(line);

    while (std::getline(iss, seq, ',')) {
        std::string label{};
        std::string focal_length{};

        std::istringstream lens_ss{seq};

        bool should_remove = false;

        if (seq.ends_with('-')) {
            std::getline(lens_ss, label, '-');
            should_remove = true;
        } else {
            std::getline(lens_ss, label, '=');
            std::getline(lens_ss, focal_length, '=');
        }

        uint64_t box_id = hash(label);

        if (should_remove) {
            boxes[box_id].remove_if([&label](const Lens &lens) {
                return lens.label == label;
            });
        } else {
            uint64_t focal_length_value = std::stoull(focal_length);
            Box &box = boxes[box_id];

            auto it = std::find_if(box.begin(), box.end(), [&label](const Lens &lens) {
                return lens.label == label;
            });

            if (it == box.end()) {
                boxes[box_id].push_back(Lens{label, focal_length_value});
            } else {
                it->focal_length = focal_length_value;
            }
        }
    }

    return focusing_power();
}

uint64_t hash(const std::string &str) {
    uint64_t hash = 0;

    for (char c: str) {
        hash += c;
        hash *= 17;
        hash %= 256;
    }

    return hash;
}

uint64_t focusing_power() {
    uint64_t result = 0;

    for(auto& [box_id, lenses]: boxes) {
        uint64_t sum = 0;

        size_t slot_no = 1;
        for(auto& lens: lenses) {
            sum += slot_no * lens.focal_length;
            slot_no++;
        }

        result += (box_id + 1) * sum;
    }

    return result;
}
