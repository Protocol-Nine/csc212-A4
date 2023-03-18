#include "path.h"
#include <iostream>
#include <fstream>
#include <sstream>

Path::Path(std::string input_file_name, int rows, int cols) {
    this->last_row = rows - 1;
    this->last_col = cols - 1;

    this->board.resize(rows, std::vector<int> (cols, 0));

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
    this->find_extreme_points();
}

void Path::find_extreme_points() {
    int lr = 0,
        lc = 0,
        hr = 0,
        hc = 0;
    for (unsigned int row = 0; row <= this->last_row; row++) {
        for (unsigned int col = 0; col <= this->last_col; col++){
            if ((this->board)[row][col] < (this->board)[lr][lc]) {
                lr = row;
                lc = col;
            }

            if ((this->board)[hr][hc] < (this->board)[row][col]) {
                hr = row;
                hc = col;
            }
        }
    }

    // Shift by 1 for output index starting at 1
    this->lr = lr + 1;
    this->lc = lc + 1;
    this->hr = hr + 1;
    this->hc = hc + 1;
}

bool Path::good_path(int row, int col) {
    // Return true if highest point is reached
    if (row + 1 == this->hr && col + 1 == this->hc) {
        return true;
    }

    int temp = this->board[row][col];

    // Set current cell to -1, marking it as visited
    this->board[row][col] = -1;

    // Recursively move to adjacent cells that are higher or equal elevation
    // Cell above
    if (row > 0 && temp <= (this->board)[row - 1][col] && this->good_path(row - 1, col)) {
        return true;
    }

    // Cell below
    if (row < this->last_row && temp <= (this->board)[row + 1][col] && this->good_path(row + 1, col)) {
        return true;
    }

    // Cell to the left
    if (col > 0 && temp <= (this->board)[row][col - 1] && this->good_path(row, col - 1)) {
        return true;
    }

    // Cell to the right
    if (col < this->last_col && temp <= (this->board)[row][col + 1] && this->good_path(row, col + 1)) {
        return true;
    }

    return false;
}

int Path::get_lr() {
    return this->lr;
}

int Path::get_lc() {
    return this->lc;
}

int Path::get_hr() {
    return this->hr;
}

int Path::get_hc() {
    return this->hc;
}

void Path::display_board(){
    for (unsigned int row = 0; row <= this->last_row; row++) {
        for (unsigned int col = 0; col <= this->last_col; col++){
            std::cout << (this->board)[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[]) {
    std::string f_name(argv[1]);

    Path p(f_name, std::stoi(argv[2]), std::stoi(argv[3]));

    int lr = p.get_lr(),
        lc = p.get_lc(),
        hr = p.get_hr(),
        hc = p.get_hc();

    std::cout << lr << ' ' << lc << ' ' << hr << ' ' << hc << ' ';

    if (p.good_path(lr - 1, lc - 1)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    // p.display_board();
}