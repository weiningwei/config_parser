
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

    bool contain_config(const std::string &section, const std::string &name, size_t pos = 0);

    void erase_string(std::string &line);

private:
    std::string _config_path;
    CONFIG_MAP _config_map;
};

template <typename T>
T CONFIG_PARSER::get_config(const std::string &section, const std::string &name,                       size_t pos)
{
    T temp;
    
}

#endif
