
#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>

class Span {
private:
  unsigned int _n;
  std::vector<int> vector;
  Span(void);
public:
  Span(unsigned int n);
  Span(Span const & other);
  ~Span();

  Span & operator=(Span const &rhs);

  int shortestSpan();
  int longestSpan();
  void addNumber(int number);
  void addNumbers(std::vector<int>::const_iterator iter, std::vector<int>::const_iterator it);
};

#endif
