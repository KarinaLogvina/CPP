#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::~BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs){
    this->_rateMap = rhs._rateMap;
  }
  return *this;
}

BitcoinExchange::BitcoinExchange(std::string const & dbFile)
{
  std::ifstream file(dbFile.c_str());
  if (!file.is_open())
    throw std::runtime_error("Error: could not open database file.");
  std::string line;
  while (getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    float price;
    if (getline(ss, date, ',') && ss >> price)
      _rateMap[date] = price;
  }
}

bool BitcoinExchange::_isValid(std::string const & date) const {
  int year, month, day;
  char separator;
  std::istringstream ss(date);
  ss >> year >> separator >> month >> separator >> day;
  if ((month == 4 || month == 6 ||  month == 9 || month == 11) && day > 30)
    return false;
  if (month == 2) {
    if  (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      if (day > 29)
        return false;
    } else {
      if (day > 28)
        return false;
    }
  }
  if (year <= 0 || month <= 0 || month > 12 || day > 31 || day <= 0) {
    return false;
  }
  return true;
}

float BitcoinExchange::getExchange(const std::string &date, float value) const {
  if (value < 0) {
    throw std::runtime_error("Error: not a positive number.");
  }
  if (value > 1000) {
    throw std::runtime_error("Error: too large a number.");
  }
  if (!_isValid(date)) {
    throw std::runtime_error("Error: wrong date.");
  }
  std::map<std::string, float>::const_iterator iter = _rateMap.find(date);
  if (iter == _rateMap.end()) {
    iter = _rateMap.upper_bound(date);
    if (iter == _rateMap.begin()){
      throw std::runtime_error("Error: no exchange rate found for given date.");
    }
    --iter;
  }
  return (iter->second);
}