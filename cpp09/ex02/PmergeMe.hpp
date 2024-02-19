#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <set>
# include <iomanip>
# include <sstream>
# include <sys/time.h>



class PmergeMe {
  private:
    bool isSorted;
    int _size;
    double vectorTime;
    double dequeTime;
    std::vector<int> vector;
    std::deque<int> deque;
    double dequeTimeDifference;
    double vectorTimeDifference;
    void printBeforeAndAfter();
    void printTime(std::string containerType) const;
    void checkDuplicates();
    double getTime();
    double timeDifference(long long time);
    std::vector<int> argsToVector(int ac, char **av);
    std::deque<int> argsToDeque(int ac, char **av);

    template <typename T>
    void insertionSort(T & arr, int left, int right);

    template <typename T>
    void fordJohnsonSort(T & arr, int left, int right);

    PmergeMe();

  public:
    PmergeMe(int ac, char **av);
    ~PmergeMe();
    PmergeMe(PmergeMe const &other);

    PmergeMe & operator=(PmergeMe const & rhs);

  double	getVectorTimeDifference() const;
  double	getDequeTimeDifference() const;

  class InvalidNumberOfArgumentsException : public std::exception {
    public:
      const char* what() const throw();
  };

  class DuplicatesException : public std::exception {
    public:
      const char* what() const throw();
  };
  class ContainerTypeException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &	operator<<(std::ostream & os, PmergeMe const & i);

#endif
