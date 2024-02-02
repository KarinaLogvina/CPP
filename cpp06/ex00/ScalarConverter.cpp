#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

static void printChar(char const & charResult, int const & flag) {
  std::cout << "char: ";
  if (flag) {
    std::cout << "impossible" << std::endl;
  } else if(std::isprint(charResult)) {
    std::cout << charResult << std::endl;
  } else {
    std::cout << "Non displayable" << std::endl;
  }
}

static void printInt(char const & intResult, int const & flag) {
  std::cout << "int: ";
  if (flag) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << intResult << std::endl;
  }
}

static void printFloat(char const & floatResult, int const & precision) {
  std::cout << "float: ";
  if (precision)
    std::cout << std::fixed << std::setprecision(precision) << floatResult << "f" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
}

static void printDouble(double const & doubleResult, int precision) {
  std::cout << "double: ";
  if (precision)
    std::cout << std::fixed << std::setprecision(precision) << doubleResult << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << doubleResult << std::endl;
}

static void printError(void) {
  std::cerr << "Invalid literal. Conversion is impossible." << std::endl;
}

static int precisionCheck(std::string const & literal) {
  int posFirst = literal.find('.');
  int posLast = literal.find('f');
  std::string subStr = "";
  if (posFirst > 0 && posLast > 0)
    subStr = literal.substr(posFirst + 1, posLast - posFirst - 1);
  else if (posFirst > 0)
    subStr = literal.substr(posFirst + 1);
  return (subStr.length());
}

void ScalarConverter::convert(std::string const & literal) {
  char charResult;
  int intResult = 0;
  float floatResult = 0;
  double doubleResult = 0;
  int flag = 0;
  int precision = precisionCheck(literal);

  //if it is a char
  if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
    charResult = literal[0];
    intResult = static_cast<int>(charResult);
    floatResult = static_cast<float>(charResult);
    doubleResult = static_cast<double>(charResult);
  } else {
    std::istringstream iss(literal);
    if (iss >> intResult) {
      charResult = static_cast<char>(intResult);
      floatResult = static_cast<float>(intResult);
      doubleResult = static_cast<double>(intResult);
    } else if (iss >> floatResult) {
      charResult = static_cast<char>(floatResult);
      floatResult = static_cast<float>(floatResult);
      doubleResult = static_cast<double>(floatResult);
    } else if (iss >> doubleResult) {
      charResult = static_cast<char>(doubleResult);
      floatResult = static_cast<float>(doubleResult);
      doubleResult = static_cast<double>(doubleResult);
    } else if (literal == "nan" || literal == "nanf") {
      flag = 1;
      charResult = 'i';
      intResult = 0;
      floatResult = NANF;
      doubleResult = NAN;
    } else if (literal == "+inf" || literal == "+inff") {
      flag = 1;
      charResult = 'i';
      intResult = 0;
      floatResult = PLUS_INF;
      doubleResult = PLUS_INF;
    } else if (literal == "-inf" || literal == "-inff") {
      flag = 1;
      charResult = 'i';
      intResult = 0;
      floatResult = MINUS_INF;
      doubleResult = MINUS_INF;
    } else {
      printError();
      return;
    }
  }
  printChar(charResult, flag);
  printInt(intResult, flag);
  printFloat(floatResult, precision);
  printDouble(doubleResult, precision);
}
