#include <algorithm>
#include <stdexcept>

template <typename T> int easyfind(T &container, int n) {
    typename T::iterator itr = std::find(container.begin(), container.end(), n);
    if (itr == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return *itr;
}
