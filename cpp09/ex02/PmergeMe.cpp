#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : isSorted(false), _size(0){};
PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
}

PmergeMe::~PmergeMe() {};

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs)
  {
    this->_size = rhs._size;
    this->isSorted = rhs.isSorted;
    this->vector = rhs.vector;
    this->deque = rhs.deque;
    this->vectorTime = rhs.vectorTime;
    this->dequeTime = rhs.dequeTime;
  }
  return (*this);
}

 std::vector<int> PmergeMe::argsToVector(int ac, char **av) {
   std::vector<int> args;
   for (int i = 1; i < ac; ++i) {
     std::string arg = av[i];
     int value = atoi(arg.c_str());
     if (value <= 0) {
       throw InvalidNumberOfArgumentsException();
     }
     args.push_back(value);
   }
   return args;
}

void PmergeMe::printBeforeAndAfter() {
  if (isSorted == false) {
    std::cout << "Before: ";
  } else {
    std::cout << "After: ";
  }
  std::vector<int>::iterator it = vector.begin();
  std::vector<int>::iterator ite = vector.end();
  while (it != ite)
  {
    std::cout << " " << *it;
    ++it;
  }
  std::cout << std::endl;
}

void PmergeMe::printTime(std::string containerType) const {
  double timeDifference;
  if (containerType == "vector"){
    timeDifference = vectorTimeDifference;
  } else if(containerType == "deque") {
    timeDifference = dequeTimeDifference;
  } else {
    throw ContainerTypeException();
  }
  std::cout << "Time to process a range of " << _size
            << " elements with std::" << containerType << ": "
            << std::fixed << std::setprecision(5) << timeDifference << " ms" << std::endl;
}

std::deque<int> PmergeMe::argsToDeque(int ac, char **av) {
  std::deque<int> args;
  for (int i = 1; i < ac; ++i) {
    std::string arg = av[i];
    int value = atoi(arg.c_str());
    if (value <= 0) {
      throw InvalidNumberOfArgumentsException();
    }
    args.push_back(value);
  }
  return args;
}


void PmergeMe::checkDuplicates() {
  std::set<int> set;
  for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
    int number = *it;
    if (set.find(number) != set.end()) {
      throw DuplicatesException();
    }
    set.insert(number);
  }
}


double PmergeMe::getTime(void)
{
  struct timeval	time;

  gettimeofday(&time, NULL);
  return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double PmergeMe::timeDifference(long long time) {
  if (time > 0)
    return (getTime() - time);
  return (0);
}

const char* PmergeMe::InvalidNumberOfArgumentsException::what() const throw() {
  return ("Error: invalid argument");
}

const char* PmergeMe::DuplicatesException::what() const throw(){
  return ("Error: duplicates are forbidden");
}

const char* PmergeMe::ContainerTypeException::what() const throw(){
  return ("Error: container chosen to print is not vector or deque");
}


double	PmergeMe::getVectorTimeDifference() const{
  return (this->vectorTimeDifference);
}
double	PmergeMe::getDequeTimeDifference() const{
  return (this->dequeTimeDifference);
}

template <typename T>
void PmergeMe::insertionSort(T & arr, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key,
    // to one position ahead of their current position
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

template <typename T>
void PmergeMe::fordJohnsonSort(T & arr, int left, int right) {
  if (left < right) {
    // Find the middle point to divide the array into two halves
    int mid = left + (right - left) / 2;

    // Recursively sort the first half
    fordJohnsonSort(arr, left, mid);

    // Recursively sort the second half
    fordJohnsonSort(arr, mid + 1, right);

    // Merge the sorted halves
    insertionSort(arr, left, right);
  }
}

PmergeMe::PmergeMe(int ac, char **av) : isSorted(false), _size(0) {
  vector = argsToVector(ac, av);
  _size = vector.size();
  checkDuplicates();
  deque = argsToDeque(ac, av);
  _size = deque.size();
  checkDuplicates();

  printBeforeAndAfter();

  double startTime = getTime();
  fordJohnsonSort(vector, 0, _size - 1);

  vectorTime = getTime();
  vectorTimeDifference = timeDifference(startTime);

  startTime = getTime();
  fordJohnsonSort(deque, 0, _size - 1);
  dequeTime = getTime();
  dequeTimeDifference = timeDifference(startTime);

  isSorted = true;
  printBeforeAndAfter();

  printTime("vector");
  printTime("deque");
}

std::ostream &	operator<<(std::ostream & os, PmergeMe const & i) {
  os << "Deque delta time: " << i.getDequeTimeDifference() << std::endl
     << "Vector delta time: " << i.getVectorTimeDifference();
  return os;
}