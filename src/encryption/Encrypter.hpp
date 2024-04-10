#ifndef ENCRYPTER_HPP
#define ENCRYPTER_HPP

#include <string>

class Encrypter
{
private:
    std::string name;

public:
    Encrypter(){}

    Encrypter(std::string name)
    {
        this->name = name;
    }

    virtual ~Encrypter() {}

    std::string getName() const
    {
        return name;
    }

    virtual std::string encrypt(std::string input)
    {
        return "";
    }

    virtual std::string decrypt(std::string input)
    {
        return "";
    }
};

#endif