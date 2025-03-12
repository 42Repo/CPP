#include "PmergeMe.hpp"
#include <limits>
#include <sstream>

inline int stoi(const std::string &str) {
    std::istringstream iss(str);
    long long          num = 0;
    iss >> num;
    if (iss.fail() || !iss.eof() || num < 0 || num > std::numeric_limits<int>::max()) {
        throw std::runtime_error("Error: Invalid input or overflow");
    }
    return static_cast<int>(num);
}

void PmergeMe::_parseInput(char **argv) {
    std::vector<int> data;
    for (int i = 1; argv[i] != NULL; i++) {
        std::string str(argv[i]);
        if (str.empty())
            continue;
        if (str.find_first_not_of("0123456789") != std::string::npos) {
            throw std::runtime_error("Error: invalid input");
        }
        data.push_back(::stoi(str));
    }
    if (data.empty()) {
        throw std::runtime_error("Error: no data to sort");
    }
    _dataVector = data;
    _dataDeque = std::deque<int>(data.begin(), data.end());
}

template <typename T> void PmergeMe::_printData(const std::string &prefix, const T &data) const {
    std::cout << prefix;
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i];
        if (i < data.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_printTime(const std::string &containerName, double duration) const {
    std::cout << "Time to process a range of "
              << (containerName == "std::vector" ? _dataVector.size() : _dataDeque.size())
              << " elements with " << containerName << " : " << duration << " us" << std::endl;
}

std::vector<int> PmergeMe::_jacobsthalSequence(int n) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    if (n <= 1) {
        return sequence;
    }

    int i = 2;
    while (true) {
        int next = sequence[i - 1] + (2 * sequence[i - 2]);
        if (next > n) {
            break;
        }
        sequence.push_back(next);
        i++;
    }
    return sequence;
}

std::vector<std::vector<size_t> > PmergeMe::_determineInsertionGroups(size_t n) {
    std::vector<std::vector<size_t> > groups;
    if (n == 0) {
        return groups;
    }

    std::vector<int> jacob = _jacobsthalSequence(static_cast<int>(n));

    std::vector<int> insertionOrder;
    for (size_t i = jacob.size() - 1; i >= 2; --i) {
        int current = jacob[i];
        int prev = (i > 2) ? jacob[i - 1] : -1;

        if (current <= static_cast<int>(n)) {
            for (int j = current; j > prev; j--) {
                if (j > 0 && j <= static_cast<int>(n))
                    insertionOrder.push_back(j - 1);
            }
        }
    }

    if (insertionOrder.empty() && n > 0) {
        insertionOrder.push_back(0);
    }

    for (size_t k = 0; k < insertionOrder.size(); ++k) {
        size_t index = insertionOrder[k];
        groups.push_back(std::vector<size_t>(1, index));
    }

    return groups;
}

void PmergeMe::_insertUsingGroups(std::vector<int>                       &mainChain,
                                  const std::vector<int>                 &pendingValues,
                                  const std::vector<std::vector<size_t> > &groups) {
    for (size_t i = 0; i < groups.size(); ++i) {
        const std::vector<size_t> &group = groups[i];
        for (size_t j = 0; j < group.size(); ++j) {
            size_t                     index = group[j];
            std::vector<int>::iterator it =
                std::lower_bound(mainChain.begin(), mainChain.end(), pendingValues[index]);
            mainChain.insert(it, pendingValues[index]);
        }
    }
}

void PmergeMe::_insertUsingGroups(std::deque<int> &mainChain, const std::vector<int> &pendingValues,
                                  const std::vector<std::vector<size_t> > &groups) {
    for (size_t i = 0; i < groups.size(); ++i) {
        const std::vector<size_t> &group = groups[i];
        for (size_t j = 0; j < group.size(); ++j) {
            size_t index = group[j];
            int    valueToInsert = pendingValues[index];

            size_t low = 0;
            size_t high = mainChain.size();
            while (low < high) {
                size_t mid = low + ((high - low) / 2);
                if (mainChain[mid] < valueToInsert) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            mainChain.insert(mainChain.begin() + low, valueToInsert);
        }
    }
}

void PmergeMe::_mergeInsertSort(std::vector<int> &data) {
    if (data.size() <= 1) {
        return;
    }

    std::vector<int> pending;
    if (data.size() % 2 != 0) {
        pending.push_back(data.back());
        data.pop_back();
    }

    for (size_t i = 0; i < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            std::swap(data[i], data[i + 1]);
        }
    }

    std::vector<int> mainChain;
    std::vector<int> pendingValues;
    for (size_t i = 0; i < data.size(); i += 2) {
        mainChain.push_back(data[i + 1]);
        pendingValues.push_back(data[i]);
    }

    _mergeInsertSort(mainChain);

    std::vector<std::vector<size_t> > groups = _determineInsertionGroups(pendingValues.size());
    _insertUsingGroups(mainChain, pendingValues, groups);

    if (!pending.empty()) {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pending[0]);
        mainChain.insert(it, pending[0]);
    }

    data = mainChain;
}

void PmergeMe::_mergeInsertSort(std::deque<int> &data) {
    if (data.size() <= 1) {
        return;
    }

    std::vector<int> pending;
    if (data.size() % 2 != 0) {
        pending.push_back(data.back());
        data.pop_back();
    }

    for (size_t i = 0; i < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            std::swap(data[i], data[i + 1]);
        }
    }

    std::deque<int>  mainChain;
    std::vector<int> pendingValues;
    for (size_t i = 0; i < data.size(); i += 2) {
        mainChain.push_back(data[i + 1]);
        pendingValues.push_back(data[i]);
    }

    _mergeInsertSort(mainChain);

    std::vector<std::vector<size_t> > groups = _determineInsertionGroups(pendingValues.size());
    _insertUsingGroups(mainChain, pendingValues, groups);

    if (!pending.empty()) {
        size_t low = 0;
        size_t high = mainChain.size();
        int    valueToInsert = pending[0];
        while (low < high) {
            size_t mid = low + ((high - low) / 2);
            if (mainChain[mid] < valueToInsert) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        mainChain.insert(mainChain.begin() + low, valueToInsert);
    }

    data = mainChain;
}

void PmergeMe::sortAndDisplay() {
    _printData("Before: ", _dataVector);

    clock_t          start_vector = clock();
    std::vector<int> sorted_vector = _dataVector;
    _mergeInsertSort(sorted_vector);
    clock_t end_vector = clock();
    double  duration_vector =
        static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000.0;
    _printData("After: ", sorted_vector);
    _printTime("std::vector", duration_vector);

    clock_t         start_deque = clock();
    std::deque<int> sorted_deque = _dataDeque;
    _mergeInsertSort(sorted_deque);
    clock_t end_deque = clock();
    double  duration_deque =
        static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000.0;
    _printTime("std::deque", duration_deque);
}

PmergeMe::PmergeMe(char **argv) : _dataVector(), _dataDeque() { _parseInput(argv); }

PmergeMe::PmergeMe(const PmergeMe &other)
    : _dataVector(other._dataVector),
      _dataDeque(other._dataDeque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this == &other) {
        _dataDeque = other._dataDeque;
        _dataVector = other._dataVector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}
