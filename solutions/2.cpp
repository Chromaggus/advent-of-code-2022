#include <iostream>

enum plays { rock, paper, scissors };

int main() {
    int total_score = 0;
    std::string line;

    while (std::getline(std::cin, line)) {
        char opponent_char = line[0];
        char your_char = line[2];

        int opponent_play = opponent_char - 'A';
        int your_play = your_char - 'X';

        // Get score based on what you played
        total_score += your_play + 1;

        // Get score if you won or drew
        if (your_play == opponent_play) {
            total_score += 3;
        } else if (your_play == (opponent_play + 1) % 3) {
            total_score += 6;
        }

        // std::cout << opponent_char << " " << your_char << " " << total_score << std::endl;
    }

    std::cout << "Total score: " << total_score << std::endl;

}