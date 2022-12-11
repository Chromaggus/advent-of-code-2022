#include <iostream>
#include <set>

#define GROUP_NUM 3

int char_score(char c);

int main() {

    std::string line;
    int total_score = 0;
    int cur_line = 0;
    std::string group[3];
    while (std::getline(std::cin, line)) {

        /* PART 1

        // Split line into 2 sets of chars
        int strlen = line.length();
        std::string first_half = line.substr(0, strlen / 2);
        std::set<char> first_half_set(begin(first_half), end(first_half));
        std::string second_half = line.substr(strlen / 2, strlen);
        std::set<char> second_half_set(begin(second_half), end(second_half));

        for (char c : first_half_set) {
            if (second_half_set.find(c) != second_half_set.end()) {
                total_score += char_score(c);
            }
        }
        */

        group[cur_line] = line;

        if (cur_line == GROUP_NUM - 1) {
            // Find the common item within the group
            std::set<char> first_line_set(begin(group[0]), end(group[0]));
            std::set<char> second_line_set(begin(group[1]), end(group[1]));
            std::set<char> third_line_set(begin(group[2]), end(group[2]));

            std::set<char> common_letters;
            for (char c : first_line_set) {
                if (second_line_set.find(c) != second_line_set.end()) {
                    common_letters.insert(c);
                }
            }

            for (char c : common_letters) {
                if (third_line_set.find(c) != third_line_set.end()) {
                    total_score += char_score(c);
                }
            }
        }

        cur_line = (cur_line + 1) % 3;
    }

    std::cout << "Final score: " << total_score << std::endl;

}

int char_score(char c) {
    if (islower(c)) {
        return c - 'a' + 1;
    } else if (isupper(c)) {
        return c - 'A' + 26 + 1;
    }

    return 0;
}
