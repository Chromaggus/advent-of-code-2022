#include <iostream>
#include <vector>

std::vector<std::string> split_string(std::string line, std::string delimiter);

int main() {

    std::string line;
    int num_completely_overlapping_pairs = 0;
    int num_partially_overlapping_pairs = 0;

    while (std::getline(std::cin, line)) {

        // Split line into two ranges
        std::vector<std::string> ranges = split_string(line, ",");
        std::string first_range = ranges[0];
        std::string second_range = ranges[1];


        // Find the start and end of each range
        std::vector<std::string> first_range_limits = split_string(first_range, "-");
        int first_range_start = stoi(first_range_limits[0]);
        int first_range_end = stoi(first_range_limits[1]);

        std::vector<std::string> second_range_limits = split_string(second_range, "-");
        int second_range_start = stoi(second_range_limits[0]);
        int second_range_end = stoi(second_range_limits[1]);

        // Check if completely overlapping
        if ((first_range_start <= second_range_start && first_range_end >= second_range_end) ||
            (first_range_start >= second_range_start && first_range_end <= second_range_end)) {
                num_completely_overlapping_pairs++;
            }


        // Check if partially overlapping
        if (std::max(first_range_start, second_range_start) <= std::min(first_range_end, second_range_end)) {
            num_partially_overlapping_pairs++;
        }
    }

    std::cout << "Number of completely overlapping pairs: " << num_completely_overlapping_pairs << std::endl;
    std::cout << "Number of partially overlapping pairs: " << num_partially_overlapping_pairs << std::endl;

}

std::vector<std::string> split_string(std::string line, std::string delimiter) {

    std::vector<std::string> result;

    std::string first_half = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + 1);
    std::string second_half = line.substr(0, line.find(delimiter));

    result.push_back(first_half);
    result.push_back(second_half);
    return result;
}
