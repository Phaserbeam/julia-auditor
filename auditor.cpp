#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum Chars
{
    EQUAL_SIGN = '=',
    SPACE = ' ',
    NEW_LINE = '\n',
    HASH = '#',
    ESCAPE = '|',
};

bool exitSignal(std::ifstream &text_file, const std::string &exit_code)
{
    int cursor = text_file.tellg();

    for (int i = 0; i < exit_code.length(); i++)
    {
        char exit_numeral = text_file.get();
        if ((exit_numeral != exit_code[i]))
        {
            return false;
        }
    }
    return true;
}
int readfile(std::vector<std::string> &data, std::ifstream &text_file, std::string filename, const std::string &exit_code)
{
    int line_index = 0;
    int max = 0;
    while (text_file.good())
    {
        char current_char = text_file.get();
        char next_char = text_file.get();
        char future_char = text_file.get();
        text_file.seekg(int(text_file.tellg()) - 2);

        if (current_char == SPACE && next_char == EQUAL_SIGN && future_char == SPACE)
        {
            // Go to beginning of line, get letters up to = sign and then chop all the
            // whitespace
            text_file.seekg(line_index);
            std::string str;
            std::getline(text_file, str, '=');
            str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

            data.push_back(str);
            std::cout << "\033[1;32mADDED\033[0m: " << str << "\n";
            if (str.length() > max)
                max = str.length();
        }
        else if (current_char == NEW_LINE)
        {
            line_index = text_file.tellg();
        }
        else if (current_char == HASH)
        {
            if (exitSignal(text_file, exit_code))
            {
                std ::filesystem::resize_file(filename, line_index);
                std::cout << "\033[1;34mNOTE\033[0m: Detected exit signal"
                             "; exiting......\n ";
                text_file.close();
            }
            else
            {
                // Go to end of file due to this being a comment
                // TODO: (Never gonna do this) enable support for multi-line comments
                std::string str;
                std::getline(text_file, str);
                line_index = text_file.tellg();
            }
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Did not input the correct amount of arguments: 1) the filename\n";
        return -1;
    }

    std::string filename(argv[1]);

    std::ifstream text_file(filename);
    if (!text_file.good())
    {
        std::cerr << "\033[1;31mERROR\033[0m: File failed to open\n";
        return -1;
    }
    std::vector<std::string> data;
    const std::string exit_code = "ΔΔΔ";

    // Adds eligible strings to data and return the max length of these strings
    int max = readfile(data, text_file, filename, exit_code);

    std::ofstream file(filename, std::ios::app);
    file << "    #" << exit_code << '\n';

    for (std::string r : data)
    {
        std::string blanks(max - r.length(), ' ');
        std::string r_name = r;
        // UNCOMMENT THIS LINE IF YOU WANT TO AUTO-CAPITALISE FIRST LETTERS
        // r_name[0] = toupper(r[0]);
        file << "    println(\"\\t" << r_name << ": " << blanks << "\", " << r << ")\n";
    }
    file << "end";

    file.close();
    return 0;
}
