
#include "config_parser.h"

CONFIG_PARSER::CONFIG_PARSER(const std::string &config_path)
{
    _config_path = config_path;

    std::ifstream config_file;
    config_file.open(_config_path);

    if (!config_file.is_open())
    {
        return;
    }

    std::string section_name;
    std::string config_name;

    std::string line;

    int line_number = 0;
    while (getline(config_file, line))
    {

        if (line.empty())
        {
            ++line_number;
            continue;
        }
    }
}

CONFIG_PARSER::~CONFIG_PARSER()
{
}

bool CONFIG_PARSER::contain_config(const std::string &section, const std::string &name, size_t pos)
{
    return true;
}

void CONFIG_PARSER::erase_string(std::string &line)
{
    std::string temp_line = line;
    const int line_size = line.size();
    int valid_number = 0;

    for(int i = 0; i < line_size; ++i)
    {
        char temp_ch = line[i];
        if (temp_ch == ' ')
        {
            continue;
        }
        temp_line[valid_number] = temp_ch;
        ++valid_number;
    }
    
    return;
}
