#include <iostream>

int main() {

    std::string line;
    int num_completely_overlapping_pairs = 0;
    int num_partially_overlapping_pairs = 0;

    while (std::getline(std::cin, line)) {

        // Split line into two ranges
        std::string delimiter1 = ",";
        std::string first_range = line.substr(0, line.find(delimiter1));
        line.erase(0, line.find(delimiter1) + 1);
        std::string second_range = line.substr(0, line.find(delimiter1));


        // Find the start and end of each range
        std::string delimiter2 = "-";
        int first_range_start = stoi(first_range.substr(0, first_range.find(delimiter2)));
        first_range.erase(0, first_range.find(delimiter2) + 1);
        int first_range_end = stoi(first_range.substr(0, first_range.find(delimiter2)));

        int second_range_start = stoi(second_range.substr(0, second_range.find(delimiter2)));
        second_range.erase(0, second_range.find(delimiter2) + 1);
        int second_range_end = stoi(second_range.substr(0, second_range.find(delimiter2)));


        // Check if completely overlapping
        if ((first_range_start <= second_range_start && first_range_end >= second_range_end) ||
            (first_range_start >= second_range_start && first_range_end <= second_range_end)) {
                num_completely_overlapping_pairs++;
            }


        // Check if partially overlapping
        if ((first_range_start <= second_range_start && first_range_end >= second_range_start) ||
            (first_range_start <= second_range_end && first_range_end >= second_range_end) ||
            (first_range_start >= second_range_start && first_range_end <= second_range_end)) {
                num_partially_overlapping_pairs++;
        }

    }

    std::cout << "Number of completely overlapping pairs: " << num_completely_overlapping_pairs << std::endl;
    std::cout << "Number of partially overlapping pairs: " << num_partially_overlapping_pairs << std::endl;

}
