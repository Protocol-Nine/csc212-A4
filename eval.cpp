#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

int main(int argc, char * argv[]) {
    std::stringstream input_stream(argv[1]);
    std::vector<int> stack;
    std::string input_token;
    int result;

    while (input_stream >> input_token) {
        // if operator
            // pop two numbers (operands) from the stack, evaluate the operator on those numbers and push the result back to the stack
        if (input_token == "+") {
            // Add two values from stack
            result = stack[stack.size() - 2] + stack[stack.size() - 1];
            // Pop the used values, push new result
            stack.pop_back();
            stack.pop_back();
            // Push the result onto the stack
            stack.push_back(result);
        } else if (input_token == "-") {
            // Subtract two values from stack
            result = stack[stack.size() - 2] - stack[stack.size() - 1];
            // Pop the used values, push new result
            stack.pop_back();
            stack.pop_back();
            // Push the result onto the stack
            stack.push_back(result);
        } else if (input_token == "*") {
            // Multiply two values from stack
            result = stack[stack.size() - 2] * stack[stack.size() - 1];
            // Pop the used values, push new result
            stack.pop_back();
            stack.pop_back();
            // Push the result onto the stack
            stack.push_back(result);
        } else if (input_token == "/") {
            // Interger divide two values from stack
            result = stack[stack.size() - 2] / stack[stack.size() - 1];
            // Pop the used values, push new result
            stack.pop_back();
            stack.pop_back();
            // Push the result onto the stack
            stack.push_back(result);
        } else if (input_token == "^") {
            // Add two values from stack
            result =  pow(stack[stack.size() - 2], stack[stack.size() - 1]);
            // Pop the used values, push new result
            stack.pop_back();
            stack.pop_back();
            // Push the result onto the stack
            stack.push_back(result);
        } else {
            // Otherwise, push numbers onto the stack
            stack.push_back(std::stoi(input_token));
        }
    }

    std::cout << stack[0] << std::endl;
}