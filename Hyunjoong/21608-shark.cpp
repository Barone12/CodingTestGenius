#include <cmath>
#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<int>>;

struct like_report {
    int like, vacant;
};

int get_like(const int val, const std::vector<int> &likes) {
    auto cur_like = 0;
    for (const auto l : likes) {
        if (val == l) {
            ++cur_like;
            break;
        }
    }
    return cur_like;
}

like_report get_seat_like(const matrix &mat, int row, int col, const std::vector<int> &likes, int n) {
    constexpr int VACANT = 0;
    like_report report { .like = 0, .vacant = 0 };
    if (row > 0) {
        auto top = mat[row - 1][col];
        if (top == VACANT)
            ++report.vacant;
        else
            report.like += get_like(top, likes);
    }
    if (col > 0) {
        auto left = mat[row][col - 1];
        if (left == VACANT)
            ++report.vacant;
        else
            report.like += get_like(left, likes);
    }
    if (row < n - 1) {
        auto down = mat[row + 1][col];
        if (down == VACANT)
            ++report.vacant;
        else
            report.like += get_like(down, likes);
    }
    if (col < n - 1) {
        auto right = mat[row][col + 1];
        if (right == VACANT)
            ++report.vacant;
        else
            report.like += get_like(right, likes);
    }
    return report;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    constexpr int LIKES_LEN = 4;

    int n;
    std::cin >> n;
    int student_cnt = n * n;

    matrix mat(n, std::vector<int>(n));
    matrix likes_mat(student_cnt + 1, std::vector<int>(LIKES_LEN));

    for (int i = 0; i < student_cnt; ++i) {
        int id;
        std::cin >> id;
        std::vector<int> &likes = likes_mat[id];
        for (int j = 0; j < LIKES_LEN; ++j) {
            std::cin >> likes[j];
        }

        int best_row = 0, best_col = 0;
        like_report best_like { .like = -1, .vacant = 0 };
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int cur = mat[row][col];
                if (cur != 0)
                    continue;
                auto like = get_seat_like(mat, row, col, likes, n);
                if (like.like > best_like.like) {
                    best_like = like;
                    best_row = row, best_col = col;
                } else if (like.like == best_like.like) {
                    if (like.vacant > best_like.vacant) {
                        best_like = like;
                        best_row = row, best_col = col;
                    }
                }
            }
        }
        mat[best_row][best_col] = id;
    }

    int total_satis = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            auto id = mat[row][col];
            auto like = get_seat_like(mat, row, col, likes_mat[id], n).like;
            total_satis += std::pow(10, like - 1);
        }
    }
    std::cout << total_satis << '\n';
}

