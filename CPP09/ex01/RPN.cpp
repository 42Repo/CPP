#include "RPN.hpp"
#include <sstream>
#include <stack>

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}
RPN::~RPN() {}

static bool isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

static int stringToInt(const std::string &str) {
    std::istringstream iss(str);
    int                num = 0;
    iss >> num;
    if (iss.fail()) {
        throw std::runtime_error("Error");
    }
    if (num < -9 || num >= 10)
        throw std::runtime_error("Error");
    return num;
}

int RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::stack<int>    stack;
    std::string        token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(num1 + num2);
            else if (token == "-")
                stack.push(num1 - num2);
            else if (token == "*")
                stack.push(num1 * num2);
            else if (token == "/") {
                if (num2 == 0)
                    throw std::runtime_error("Error");
                stack.push(num1 / num2);
            }
        } else {
            stack.push(stringToInt(token));
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}
