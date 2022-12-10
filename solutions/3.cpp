#include <iostream>
#include <set>

int char_score(char c);

int main() {

    std::string line;
    int total_score = 0;
    while (std::getline(std::cin, line)) {

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