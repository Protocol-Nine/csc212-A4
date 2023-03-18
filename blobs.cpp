#include "blobs.h"
#include <iostream>
#include <fstream>
#include <sstream>

Blobs::Blobs(std::string input_file_name, int rows, int cols) {
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

void Blobs::clear_blob(unsigned int row, unsigned int col, unsigned int connection_type) {
    // If the cell is empty, return
    if (!(this->board)[row][col]) {
        return;
    }

    // Empty the current cell
    (this->board)[row][col] = 0;

    // Recrusively check surrounding cells and empty
    // Check cell above
    if (row > 0) {
        this->clear_blob(row - 1, col, connection_type);
    }
    
    // Check cell below
    if (row < this->last_row) {
        this->clear_blob(row + 1, col, connection_type);
    }

    // Check cell to the left
    if (col > 0) {
        this->clear_blob(row, col - 1, connection_type);
    }
    
    // Check cell to the right
    if (col < this->last_col) {
        this->clear_blob(row, col + 1, connection_type);
    }
    // For connectivity type "8," clear diagonal cells
    if (connection_type == 8) {
        // Check upper left cell
        if(row > 0 && col > 0) {
            this->clear_blob(row - 1, col - 1, connection_type);
        }

        // Check upper right cell
        if(row > 0 && col < this->last_col) {
            this->clear_blob(row - 1, col + 1, connection_type);
        }

        // Check lower left cell
        if(row < this->last_row && col > 0) {
            this->clear_blob(row + 1, col - 1, connection_type);
        }

        // Check lower right cell
        if(row < this->last_row && col < this->last_col) {
            this->clear_blob(row + 1, col + 1, connection_type);
        }
    }
}

unsigned int Blobs::count_blobs(int connection_type) {
    unsigned int num_of_blobs = 0;
    for (unsigned int row = 0; row <= this->last_row; row++) {
        for (unsigned int col = 0; col <= this->last_col; col++){
            if ((this->board)[row][col]) {
                num_of_blobs++;
                this->clear_blob(row, col, connection_type);
            }
        }
    }

    return num_of_blobs;
}

void Blobs::display_board(){
    for (unsigned int row = 0; row <= this->last_row; row++) {
        for (unsigned int col = 0; col <= this->last_col; col++){
            std::cout << (this->board)[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[]) {
    std::string f_name(argv[1]);

    Blobs b(f_name, std::stoi(argv[2]), std::stoi(argv[3]));

    std::cout << b.count_blobs(std::stoi(argv[4])) << std::endl;

    // b.display_board();
}