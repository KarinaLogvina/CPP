#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack(){};
    ~MutantStack(){};
    MutantStack(MutantStack const &other) : std::stack<T>(other) {
      *this = other;
    };

    MutantStack & operator=(MutantStack const &rhs) {
      std::stack<T>::operator=(rhs);
      return *this;
    };

  typedef typename std::stack<T>::container_type::iterator iterator;
  iterator begin() {
    return this ->c.begin();
  };
  iterator end() {
    return this ->c.end();
  };

};


#endif
