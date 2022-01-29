#include <iostream>

int main();

int main() {
    double x{};

    std::cout << "Enter value of x: ";
    std::cin >> x;

    // This local variable should hold the result of stair( x )
    int stair{};

    // TASK: write code that calculates an integer value
    // corresponding to the value of the function stair( x ) here

    //Positive numbers
    int p_loop_variable{1};

    while (x >= p_loop_variable){
        if (x >= p_loop_variable) {
            stair = p_loop_variable;
        }
        p_loop_variable++;
    }

    //Negative numbers
    int n_loop_variable{0};

    while (x < n_loop_variable) {
        if (x < n_loop_variable) {
            stair = n_loop_variable - 1;
        }
        n_loop_variable--;
    }

    std::cout << "The value of stair(x) is: ";
    std::cout << stair;
    std::cout << std::endl;

    return 0;
}
