#include "./Encrypter.hpp"

// Example of a child class of Encrypter
class PlainText : public Encrypter
{
public:
    PlainText() : Encrypter("Plain Text"){}

    std::string encrypt(std::string text) override
    {
        return text;
    }

    std::string decrypt(std::string text) override
    {
        return text;
    }
};