#include "config_parser.h"
#include <iostream>

int main()
{
    std::string file_path = "../../examples/config.ini";
    CONFIG_PARSER config_parser(file_path);

    std::string section1 = "Section1";
    std::string section2 = "Section2";

    std::string s1_config2 = "example2";
    std::string s1_config5 = "example5";

    std::string s2_config1 = "example1";
    std::string s2_config2 = "example2";

    if (config_parser.contain_config(section1, s1_config2))
    {
        int example2 = config_parser.get_config<int>(section1, s1_config2);
        std::cout << example2 << "\n";
    }
    if (config_parser.contain_config(section1, s1_config2, 1))
    {
        int example2 = config_parser.get_config<int>(section1, s1_config2);
        std::cout << example2 << "\n";
    }
    else
    {
        std::cout << "don't contain s1_c2_1\n";
    }

    if (config_parser.contain_config(section2, s2_config1))
    {
        std::vector<int> example4 = config_parser.get_config_vec<int>(section2, s2_config1);
        for (int i = 0; i < example4.size(); ++i)
        {
            std::cout << example4[i] << " ";
        }
        std::cout << "\n";
    }

    if (config_parser.contain_config(section2, s2_config2))
    {
        std::vector<double> example4 = config_parser.get_config_vec<double>(section2, s2_config2);
        for (int i = 0; i < example4.size(); ++i)
        {
            std::cout << example4[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}