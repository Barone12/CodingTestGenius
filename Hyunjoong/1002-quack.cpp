/*
 *  BOJ 12933
 */

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    const std::string QUACK = "quack";
    constexpr int QUACK_LEN = 5;

    int answer = 0;
    std::vector<int> delete_indicies;
    std::string input;
    std::cin >> input;

    while (true) {
        int pos = 0;
        int current_char = 0;
        bool quack_flag = false;

        while (true) {
            pos = input.find(QUACK[current_char], pos);
            if (pos == std::string::npos)
                break;
            ++current_char;
            delete_indicies.push_back(pos);
            if (current_char >= QUACK_LEN) {
                current_char = 0;
                quack_flag = true;
            }
        }

        if (current_char > 0) {
            std::cout << "-1\n";
            return 0;
        }
        if (quack_flag) {
            ++answer;
        }
        /*
        * for (auto iter = delete_indicies.rbegin(); iter != delete_indicies.rend(); ++iter) {
        *     input.erase(*iter, 1);
        * }
        */
        for (int i = delete_indicies.size() - 1; i >= 0; --i) {
            input.erase(delete_indicies[i], 1);
        }
        delete_indicies.clear();

        pos = input.find(QUACK[current_char]);
        if (pos == std::string::npos)
            break;
    }

    if (input.size() > 0) {
        std::cout << "-1\n";
        return 0;
    }

    std::cout << answer << '\n';
}

