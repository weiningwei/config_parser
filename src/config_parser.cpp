
#include "config_parser.h"

CONFIG_PARSER::CONFIG_PARSER(const std::string &config_path)
{
    _config_path = config_path;

    std::ifstream config_file;
    config_file.open(_config_path);

    if (!config_file.is_open())
    {
        std::cout << "file open error: " << _config_path << "\n";
        return;
    }

    std::string section_name;
    std::string config_name;
    std::string raw_config_content;
    std::vector<std::string> config_contents;
    std::string line;

    int line_number = 0;
    while (getline(config_file, line))
    {
        erase_string(line);
        std::cout << line << "\n";
        if (line.empty())
        {
            ++line_number;
            continue;
        }
        if (';' == line[0])
        {
            ++line_number;
            continue;
        }
        if ('[' == line[0] && ']' == line[line.length() - 1])
        {
            section_name = line.substr(1, line.length() - 2);
            continue;
        }

        std::string::size_type equal_pos = line.find('=');
        if (std::string::npos == equal_pos)
        {
            ++line_number;
            continue;
        }
        config_name = line.substr(0, equal_pos);
        raw_config_content = line.substr(equal_pos + 1, line.length() - 1);

        // string split
        std::stringstream ss(raw_config_content);
        std::string temp_content;
        while (ss.good())
        {
            getline(ss, temp_content, ',');
            config_contents.push_back(temp_content);
        }
        std::string section_config = section_name + "-" + config_name;
        // _config_map.insert(std::make_pair(section_config, config_contents));
        _config_map[section_config] = config_contents;
        config_contents.clear();
        ++line_number;
    }
    config_file.close();

    return;
}

CONFIG_PARSER::~CONFIG_PARSER()
{
}

void CONFIG_PARSER::erase_string(std::string &line)
{
    std::string temp_line = line;
    const int line_size = line.size();
    int valid_number = 0;

    for (int i = 0; i < line_size; ++i)
    {
        char temp_ch = line[i];
        if (' ' == temp_ch)
        {
            continue;
        }
        temp_line[valid_number] = temp_ch;
        ++valid_number;
    }
    line = temp_line.substr(0, valid_number);

    return;
}

bool CONFIG_PARSER::contain_config(const std::string &section, const std::string &name, size_t pos)
{
    bool status = false;
    std::string section_congig = section + "-" + name;

    CONFIG_MAP::iterator config_iter = _config_map.find(section_congig);
    if (_config_map.end() == config_iter)
    {
        return status;
    }
    std::vector<std::string> config_vec = _config_map[section_congig];
    size_t config_size = config_vec.size();

    if (pos >= config_size)
    {
        return status;
    }
    status = true;

    return status;
}

template <>
bool CONFIG_PARSER::get_config(const std::string &section, const std::string &name, size_t pos)
{
    bool temp = false;
    std::string section_config = section + "-" + name;
    std::string config_content = _config_map[section_config][pos];

    if ("true" == config_content ||
        "TRUE" == config_content ||
        "1" == config_content)
    {
        return true;
    }

    else if ("false" == config_content ||
             "FALSE" == config_content ||
             "0" == config_content)
    {
        return false;
    }
    else
    {
        return false;
    }

    return temp;
}

template <>
std::vector<bool> CONFIG_PARSER::get_config_vec(const std::string &section, const std::string &name)
{
    std::string section_config = section + "-" + name;
    std::vector<std::string> config = _config_map[section_config];

    std::vector<bool> temp(config.size(), false);
    for (unsigned i = 0; i < config.size(); ++i)
    {
        std::string temp_str = config[i];
        if ("true" == temp_str ||
            "TRUE" == temp_str ||
            "1" == temp_str)
        {
            temp[i] = true;
        }

        else if ("false" == temp_str ||
                 "FALSE" == temp_str ||
                 "0" == temp_str)
        {
            temp[i] = false;
        }
        else
        {
            temp[i] = false;
        }
    }
    return temp;
}