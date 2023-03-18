#pragma once
#include <iostream>
#include <vector>

class Cells{
    private:
        std::vector<std::vector<unsigned int>> board;
        int last_row;
        int last_col;

    public:
        Cells(std::string input_file_name, int rows, int cols);

        int count_cells(int row, int col, int connection_type, int cells);
        void display_board();
};