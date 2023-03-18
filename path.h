#pragma once
#include <iostream>
#include <vector>

class Path{
    private:
        std::vector<std::vector<int>> board;
        int last_row;
        int last_col;

        // Low and high point cooridinates, index starting at 1
        int lr,
            lc,
            hr,
            hc;

        void find_extreme_points();

    public:
        Path(std::string input_file_name, int rows, int cols);
        bool good_path(int row, int col);
        int get_lr();
        int get_lc();
        int get_hr();
        int get_hc();
        void display_board();
};