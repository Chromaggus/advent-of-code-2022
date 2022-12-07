#include <iostream>
#include <queue>

int main() {
    int first, second, third;
    int cur_elf_calories = 0;
    std::string line;
    std::priority_queue<int> queue;

    while (std::getline(std::cin, line)) {

        // Empty line
        if (line.length() == 1) {
            std::cout << line;
            // max = max > cur_elf_calories ? max : cur_elf_calories;
            queue.push(cur_elf_calories);
            cur_elf_calories = 0;

        // Line with number
        } else {
            int cur_calories = stoi(line);
            cur_elf_calories += cur_calories;

        }
    }

    first = queue.top();
    queue.pop();
    second = queue.top();
    queue.pop();
    third = queue.top();
    std::cout << "max: " << first << std::endl;
    std::cout << "sum of top 3: " << first + second + third << std::endl;

}