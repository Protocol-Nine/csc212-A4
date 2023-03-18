#pragma once
#include <iostream>
#include <vector>

class Blobs{
    private:
        std::vector<std::vector<unsigned int>> board;
        int last_row;
        int last_col;

        // Recursively empties all cells in a blob
        void clear_blob(unsigned int row, unsigned int col, unsigned int connection_type);

    public:
        Blobs(std::string input_file_name, int rows, int cols);
        unsigned int count_blobs(int connection_type);
        void display_board();
};