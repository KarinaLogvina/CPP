#ifndef CPP06_SERIALIZATION_HPP
#define CPP06_SERIALIZATION_HPP


class Serialization {
  private:
    Serialization(void);
    ~Serialization(void);
    Serialization(Serialization const & other);

    Serialization & operator=(Serialization const & rhs);
  public:
    static uintptr_t serialize(Data * ptr);
    static Data * deserialize(uintptr_t raw);
};


#endif
