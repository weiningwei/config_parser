
#ifndef _CONFIG_PARSER_H
#define _CONFIG_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>

#define CONFIG_PARTSER_API __declspec(dllexport)

typedef std::unordered_map<std::string, std::vector<std::string>> CONFIG_MAP;

class CONFIG_PARTSER_API CONFIG_PARSER
{
public:
    CONFIG_PARSER(const std::string &config_path);
    ~CONFIG_PARSER();

    template <typename T>
    T get_config(const std::string &section, const std::string &name, size_t pos = 0);

    template <typename T>
    std::vector<T> get_config_vec(const std::string &section, const std::string &name);

    void erase_string(std::string &line);

    bool contain_config(const std::string &section, const std::string &name, size_t pos = 0);

private:
    std::string _config_path;
    CONFIG_MAP _config_map;
};

template <>
bool CONFIG_PARSER::get_config(const std::string &section, const std::string &name, size_t pos);

template <typename T>
T CONFIG_PARSER::get_config(const std::string &section, const std::string &name, size_t pos)
{
    T temp;
    std::string section_config = section + "-" + name;
    std::string config_content = _config_map[section_config][pos];

    std::istringstream ss(config_content);
    if (std::string::npos != config_content.find("0x"))
    {
        ss >> std::hex >> temp;
    }
    else
    {
        ss >> std::dec >> temp;
    }

    return temp;
}

template <>
std::vector<bool> CONFIG_PARSER::get_config_vec(const std::string &section, const std::string &name);

template <typename T>
std::vector<T> CONFIG_PARSER::get_config_vec(const std::string &section, const std::string &name)
{
    std::string section_config = section + "-" + name;
    std::vector<std::string> config = _config_map[section_config];
    std::cout << config.size() << "\n";

    std::vector<T> temp(config.size());
    for (int i = 0; i < config.size(); ++i)
    {
        std::istringstream iss(config[i]);

        if (std::string::npos != config[i].find("0x"))
            iss >> std::hex >> temp[i];
        else
            iss >> std::dec >> temp[i];
    }
    return temp;
}
#endif
