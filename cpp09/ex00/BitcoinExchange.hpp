#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>


class BitcoinExchange {
  private:
    BitcoinExchange();
    std::map<std::string, float> _rateMap;
    bool _isValid(std::string const & date) const;

  public:
    BitcoinExchange(std::string const & dbFile);
    BitcoinExchange(BitcoinExchange const &other);
    ~BitcoinExchange();

    BitcoinExchange & operator=(BitcoinExchange const &rhs);
    float getExchange(std::string const & date, float value) const;

};

std::ostream & operator<<(std::ostream & os, BitcoinExchange const & i);

#endif
