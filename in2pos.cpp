#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char * argv[]) {
    std::stringstream input_stream(argv[1]);
    std::vector<std::string> stack;
    std::string input_token,
                output_string;

    while (input_stream >> input_token) {
        if (input_token == "(") {
            stack.push_back(input_token);
        } else if (input_token == "*" || input_token == "/") {
            // Pop all + or - operators from stack to output
            if (stack.size() != 0) {
                while (stack[stack.size() - 1] != "(" && 
                        (stack[stack.size() - 1] == "*" || stack[stack.size() - 1] == "/")) {
                    output_string.append(stack[stack.size() - 1] + " ");
                    stack.pop_back();
                }
            }
            stack.push_back(input_token);
        } else if (input_token == "+" || input_token == "-") {
            // Pop all +, -, *, or / operators from stack to output
            if (stack.size() != 0) {    
                while (stack[stack.size() - 1] != "(" && 
                        (stack[stack.size() - 1] == "+" || stack[stack.size() - 1] == "-" ||
                        stack[stack.size() - 1] == "*" || stack[stack.size() - 1] == "/")) {
                    output_string.append(stack[stack.size() - 1] + " ");
                    stack.pop_back();
                }
            }
            stack.push_back(input_token);
        } else if (input_token == "^") {
            stack.push_back(input_token);
        } else if (input_token == ")") {
            if (stack.size() != 0) {
                while (stack[stack.size() - 1] != "(") {
                    output_string.append(stack[stack.size() - 1] + " ");
                    stack.pop_back();
                }
            }
            // Discard left parenthesis
            stack.pop_back();
        } else {
            output_string.append(input_token + " ");
        }

        std::cout << output_string << std::endl;
    }

    // Pop any remaining operators from the stack onto the output string
    while (stack.size() != 0) {
        output_string.append(stack[stack.size() - 1] + " ");
        stack.pop_back();
    }


    std::cout << output_string << std::endl;

}