#pragma once

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
  private:
    PmergeMe();
    std::vector<int> _dataVector;
    std::deque<int>  _dataDeque;

    std::vector<int>                  _jacobsthalSequence(int n);
    std::vector<std::vector<size_t> > _determineInsertionGroups(size_t n);
    void                              _mergeInsertSort(std::vector<int> &data);
    void                              _mergeInsertSort(std::deque<int> &data);
    void                              _parseInput(char **argv);
    template <typename T> void        _printData(const std::string &prefix, const T &data) const;
    void _printTime(const std::string &containerName, double duration) const;
    void _insertUsingGroups(std::vector<int> &mainChain, const std::vector<int> &pendingValues,
                            const std::vector<std::vector<size_t> > &groups);
    void _insertUsingGroups(std::deque<int> &mainChain, const std::vector<int> &pendingValues,
                            const std::vector<std::vector<size_t> > &groups);

  public:
    explicit PmergeMe(char **argv);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortAndDisplay();
};
