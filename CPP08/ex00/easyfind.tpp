#include <algorithm>

template <typename T> int easyfind(T &container, int n) {
    if (n < 0 || n > static_cast<int>(container.size()))
        throw std::exception();
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return *it;
}
