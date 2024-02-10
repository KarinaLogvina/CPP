#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <class T>
class Array {
  private:
    T * _arr;
    unsigned int _size;

  public:
    Array() : _arr(0), _size(0) {};
    ~Array() {
        delete []_arr;
    };
    Array(unsigned int _size) : _size(_size) {
        this->_arr = new T[_size];
    }
    Array(Array<T> const & other): _size(other._size) {
      _arr = new T[_size];
      for (unsigned int i = 0; i < _size; ++i) {
        _arr[i] = other[i];
      }
    }

    Array<T> & operator=(Array<T> const &rhs) {
      T* tmp = new T[rhs._size];
      for (unsigned int i = 0; i < rhs._size; ++i) {
        tmp[i] = rhs[i];
      }
      delete []_arr;
      _size = rhs._size;
      _arr = tmp;
    }
    const T & operator[](unsigned int index) const {
      if (index >= _size) {
        throw std::exception ();
      }
        return _arr[index];
    }
    T & operator[](unsigned int index) {
      if (index >= _size) {
        throw std::runtime_error("Index out of bounds!");
      }
      return _arr[index];
    }

    unsigned int size() const {
      return this->_size;
    }


};

#endif