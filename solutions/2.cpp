#include <iostream>

enum plays { rock, paper, scissors };

int main() {
    int total_score = 0;
    std::string line;

    while (std::getline(std::cin, line)) {
        char opponent_char = line[0];
        int opponent_play = opponent_char - 'A';

        char your_char = line[2];
        int your_play = your_char - 'X';

        /*  PART 1

        // Get score based on what you played
        total_score += your_play + 1;

        // Get score if you won or drew
        if (your_play == opponent_play) {
            total_score += 3;
        } else if (your_play == (opponent_play + 1) % 3) {
            total_score += 6;
        }
        */

        // Get score based on if you want to win
        total_score += (your_play - 1) * 3 + 3;

        // Get score based on what you played
        total_score += ((opponent_play + your_play - 1) % 3 + 3) % 3 + 1;

        std::cout << opponent_char << " " << your_char << " " << total_score << std::endl;
    }

    std::cout << "Total score: " << total_score << std::endl;
}