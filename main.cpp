#include "./src/encryption/PlainText.hpp"
#include "./src/utils/cli.hpp"
#include <algorithm>

int main()
{
    std::vector<Encrypter*> encrypters;
    encrypters.push_back(new PlainText());

    int selectedEncrypter = -1;
    std::string input;

    //map encrypters to choices
    std::vector<std::string> choices;
    std::transform(encrypters.begin(), encrypters.end(), std::back_inserter(choices), [](Encrypter* encrypter) { return encrypter->getName(); });

    auto modeChoice = promptChoice("Select a mode", {"Encrypt", "Decrypt"});
    bool isEncryptMode = modeChoice.first == 0;

    auto encrypterChoice = promptChoice((
        isEncryptMode ? "Select an encrypter" : "Select a decrypter"
    ), choices);
    
    unsigned int selectedEncrypterIndex = encrypterChoice.first;

    Encrypter* selected = encrypters[selectedEncrypterIndex];

    input = prompt((
        isEncryptMode ? "Enter text to encrypt" : "Enter text to decrypt"
    ), [](std::string input)
                   {
        if(input.length() == 0) {
            return "Text cannot be empty";
        }
        return ""; });

    std::string output = (isEncryptMode ? selected->encrypt(input) : selected->decrypt(input));

    std::cout << (isEncryptMode ? "Encrypted" : "Decrypted") << " text: " << output << std::endl;
}
