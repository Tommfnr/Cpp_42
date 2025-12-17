#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: " << av[0] << " <file> <s1> <s2>\n";
        return 1;
    }

    std::ifstream file_in(av[1]);
    if (!file_in)
    {
        std::cout << "Error: cannot open the file\n";
        return 1;
    }

    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty\n";
        return 1;
    }

    std::string out_name = std::string(av[1]) + ".replace";
    std::ofstream file_out(out_name.c_str());
    if (!file_out)
    {
        std::cout << "Error: cannot create output file\n";
        return 1;
    }

    std::string line;
    while (std::getline(file_in, line))
    {
        std::string buffer;
        size_t i = 0;

        while (i < line.length())
        {
            size_t pos = line.find(s1, i);
            if (pos == i)
            {
                buffer.insert(buffer.length(), s2); 
                i += s1.length(); 
            }
            else
            {
                buffer += line[i];
                i++;
            }
        }
        file_out << buffer << '\n';
    }
    return 0;
}
