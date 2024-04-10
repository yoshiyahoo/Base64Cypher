#include <iostream>
#include <functional>
#include <vector>
#include <utility>
std::string prompt(std::string message, std::function<std::string(std::string)> validator)
{
    std::cout << "\x1b[36m> " << message << ": \x1b[0m" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::string error = validator(input);
    if (error != "")
    {
        std::cout << "\x1b[31m" << error << "\x1b[0m" << std::endl;
        return prompt(message, validator);
    }
    return input;
}

std::pair<unsigned int, std::string> promptChoice(std::string prompt, std::vector<std::string> choices)
{
    std::cout << "\x1b[36m> " << prompt << " (type a number)\n\x1b[0m";
    for (unsigned int i = 0; i < choices.size(); i++)
    {
        std::cout << "  " << i + 1 << ". " << choices[i] << std::endl;
    }

    unsigned int choice = -1;
    std::string line;
    while (!(choice >= 1 && choice <= choices.size()))
    {
        std::getline(std::cin, line);
        try
        {
            choice = std::stoi(line);
        }
        catch (std::invalid_argument e)
        {
            choice = -1;
        }

        if (!(choice >= 1 && choice <= choices.size()))
        {
            std::cout << "\x1b[31mInvalid choice\x1b[0m" << std::endl;
        }
    }
    return std::make_pair(choice - 1, choices[choice - 1]);
}
