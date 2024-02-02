//
// Created by Karina Logvina on 28.01.24.
//

#ifndef CPP06_SCALARCONVERTER_HPP
#define CPP06_SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <sstream>
# include <limits>
# include <iomanip>

# define PLUS_INF	(1.0f/0.0f)
# define MINUS_INF	(-1.0f/0.0f)
# define NANF		(0.0f/0.0f)

class ScalarConverter {
  private:
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const & other);
    ScalarConverter & operator=(ScalarConverter const & rhs);
    ~ScalarConverter(void);
  public:
    static void convert(std::string const & literal);
};


#endif
