//
// Created by Karina Logvina on 13.02.24.
//

#include "Span.hpp"

Span::Span() : _n(0) {};

Span::Span(unsigned int n) : _n(n) {};

Span::~Span() {};

Span::Span(const Span &other) {
  *this = other;
}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    this->_n = rhs._n;
    this->vector = rhs.vector;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (vector.size() >= _n) {
    throw std::range_error("Span is full!");
  }
  vector.push_back(number);
}

int Span::longestSpan() {
  if (vector.size() < 2) {
    throw std::logic_error("Cannot find longest span with less than two numbers.");
  }
  std::vector<int>::iterator max_element;
  std::vector<int>::iterator min_element;
  return *std::max_element(vector.begin(), vector.end()) - *std::min_element(vector.begin(), vector.end());
}

int Span::shortestSpan() {
  if (vector.size() < 2) {
    throw std::range_error("Cannot find shortest span with less than two numbers.");
  }
  std::sort(vector.begin(), vector.end());
  int shortest = vector[1] - vector[0];
  for (size_t i = 2; i < vector.size(); ++i) {
    int span = vector[i] - vector[i - 1];
    if (span < shortest) {
      shortest = span;
    }
  }
  return shortest;
}

void Span::addNumbers(std::vector<int>::const_iterator iter, std::vector<int>::const_iterator it) {
  vector.insert(vector.end(), iter, it);
  if (vector.size() > _n) {
    std::range_error("Span is full");
  }
}
