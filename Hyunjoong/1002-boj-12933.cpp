#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    const std::string QUACK = "quack";
    constexpr int QUACK_LEN = 5;

    int quack_count = 0;
    int current_char = 0;
    int i = 0;
    std::string quack;
    std::cin >> quack;

    while (!quack.empty()) {
        i = quack.find_first_of(QUACK[current_char], i);
        if (i == std::string::npos) {
            current_char = 0;
            i = 0;
            continue;
        }
        ++current_char;
        std::cout << i << ": " << quack << std::endl;
        quack.erase(i, 1);
        if (current_char >= QUACK_LEN) {
            ++quack_count;
            current_char = 0;
        }
    }

    std::cout << quack_count << std::endl;
}

