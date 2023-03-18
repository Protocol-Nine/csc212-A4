#include "cells.h"
#include <iostream>
#include <fstream>
#include <sstream>

Cells::Cells(std::string input_file_name, int rows, int cols) {
    this->last_row = rows - 1;
    this->last_col = cols - 1;

    this->board.resize(rows, std::vector<unsigned int> (cols, 0));

    std::ifstream input_file_stream(input_file_name);
    std::string row_data;

    for (int row = 0; row < rows; row++) {
        // Get next line from file to convert to row in board
        std::getline(input_file_stream, row_data);
        std::stringstream ss(row_data);
        for(int col = 0; col < cols; col++) {
            ss >> (this->board)[row][col];
        }
    }
}

int Cells::count_cells(int row, int col, int connection_type, int cells) {
    // If the cell is empty, return the current value of "cells"
    if (!(this->board)[row][col]) {
        return cells;
    }

    // Empty the current cell and increment "cells"
    (this->board)[row][col] = 0;
    cells++;

    // Recrusively check surrounding cell and update value of "cells"
    // Check cell above
    if (row > 0) {
        cells = this->count_cells(row - 1, col, connection_type, cells);
    }
    
    // Check cell below
    if (row < this->last_row) {
        cells = this->count_cells(row + 1, col, connection_type, cells);
    }

    // Check cell to the left
    if (col > 0) {
        cells = this->count_cells(row, col - 1, connection_type, cells);
    }
    
    // Check cell to the right
    if (col < this->last_col) {
        cells = this->count_cells(row, col + 1, connection_type, cells);
    }
    // For connectivity type "8"
    if (connection_type == 8) {
        // Check upper left cell
        if(row > 0 && col > 0) {
            cells = this->count_cells(row - 1, col - 1, connection_type, cells);
        }

        // Check upper right cell
        if(row > 0 && col < this->last_col) {
            cells = this->count_cells(row - 1, col + 1, connection_type, cells);
        }

        // Check lower left cell
        if(row < this->last_row && col > 0) {
            cells = this->count_cells(row + 1, col - 1, connection_type, cells);
        }

        // Check lower right cell
        if(row < this->last_row && col < this->last_col) {
            cells = this->count_cells(row + 1, col + 1, connection_type, cells);
        }

    }
    
    // Return the updated value of cells
    return cells;
}

void Cells::display_board(){
    for (unsigned int i = 0; i <= this->last_row; i++) {
        for (unsigned int j = 0; j <= this->last_col; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[]) {
    std::string f_name(argv[1]);

    Cells c(f_name, std::stoi(argv[2]), std::stoi(argv[3]));

    std::cout << c.count_cells(std::stoi(argv[4]) - 1, std::stoi(argv[5]) - 1, std::stoi(argv[6]), 0) << std::endl;

    // c.display_board();
}