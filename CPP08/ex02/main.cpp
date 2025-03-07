#include "MutantStack.h"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "\nSize of mstack: " << mstack.size() << std::endl;
    std::cout << "Top element of mstack: " << mstack.top() << std::endl;

    std::cout << "\nRemoving top element" << std::endl;
    mstack.pop();

    std::cout << "\nSize of mstack: " << mstack.size() << std::endl << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    MutantStack<int> defaultStack;

    MutantStack<int> copyStack(mstack);

    MutantStack<int> assignedStack;
    assignedStack = mstack;

    std::cout << "\nIs mstack empty? " << std::boolalpha << mstack.empty() << std::endl;

    std::cout << "\nTesting size() function" << std::endl;
    std::cout << "Size of mstack: " << mstack.size() << std::endl;

    std::cout << "\nTesting top() function" << std::endl;
    std::cout << "Top element of mstack: " << mstack.top() << std::endl;

    std::cout << "\nTesting push() and pop()" << std::endl;
    mstack.push(42);
    std::cout << "After push(42), top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "After pop(), top: " << mstack.top() << std::endl;

    std::cout << "\nTesting iterators" << std::endl;
    it = mstack.begin();
    ite = mstack.end();
    std::cout << "Iterating over mstack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nTesting reverse iterators" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Reverse iterating over mstack:" << std::endl;
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\nTesting with different types (if the class is generic)" << std::endl;
    MutantStack<std::string> stringStack;
    stringStack.push("hello");
    stringStack.push("world");
    std::cout << "Top of stringStack: " << stringStack.top() << std::endl;

    std::cout << "\nTesting empty() function on empty and non-empty stacks" << std::endl;
    std::cout << "Is defaultStack empty? " << std::boolalpha << defaultStack.empty() << std::endl;
    std::cout << "Is mstack empty? " << std::boolalpha << mstack.empty() << std::endl;

    std::cout << "\nTesting relational operators (if implemented)" << std::endl;
    if (mstack == copyStack)
        std::cout << "mstack is equal to copyStack" << std::endl;
    if (mstack != defaultStack)
        std::cout << "mstack is different from defaultStack" << std::endl;

    std::cout << "\nTesting swap() function" << std::endl;
    MutantStack<int> swapStack;
    swapStack.push(100);
    swapStack.push(200);
    std::cout << "Before swap, top of mstack: " << mstack.top() << std::endl;
    std::cout << "Before swap, top of swapStack: " << swapStack.top() << std::endl;
    std::swap(mstack, swapStack);
    std::cout << "After swap, top of mstack: " << mstack.top() << std::endl;
    std::cout << "After swap, top of swapStack: " << swapStack.top() << std::endl;

    std::cout << "\nTesting constant iterators" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    std::cout << "Constant iterating over mstack:" << std::endl;
    while (cit != cite) {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "\nTesting constant reverse iterators" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    std::cout << "Constant reverse iterating over mstack:" << std::endl;
    while (crit != crite) {
        std::cout << *crit << std::endl;
        ++crit;
    }

    std::cout << "\nTesting with different types (double, char)" << std::endl;
    MutantStack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.718);
    std::cout << "Top of doubleStack: " << doubleStack.top() << std::endl;

    MutantStack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    std::cout << "Top of charStack: " << charStack.top() << std::endl;

    std::cout << "\nTesting copy and assignment with stacks of different types" << std::endl;
    MutantStack<double> anotherDoubleStack(doubleStack);
    MutantStack<char>   anotherCharStack;
    anotherCharStack = charStack;

    std::cout << "\nVerifying integrity after multiple operations" << std::endl;
    std::cout << "Size of mstack: " << mstack.size() << std::endl;
    std::cout << "Contents of mstack after all operations:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
