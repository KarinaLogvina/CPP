#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: pass your file as second parameter." << std::endl;
    return (1);
  }
  std::ifstream inputFile(av[1]);
  if (!inputFile.is_open()) {
    std::cerr << "Error: couldn't open input file" << std::endl;
    return (1);
  }
  BitcoinExchange exchange("data.csv");
  std::string line;
  getline(inputFile, line);
  while (getline(inputFile, line)) {
    std::stringstream ss(line);
    std::string date;
    float value;
    if (getline(ss, date, '|') && ss >> value) {
      date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
      date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
      try {
        float exchangeRate = exchange.getExchange(date, value);
        float result = value * exchangeRate;
        std::cout << date << " => " << value << " = " << result << std::endl;
      }
      catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
      }
    }
    else {
      std::cerr << "Error: bad input => " << line << std::endl;
    }
  }
  return (0);
}
