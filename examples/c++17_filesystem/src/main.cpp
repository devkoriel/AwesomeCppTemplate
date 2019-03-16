#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    fs::path p(argc>1? argv[1] : ".");

    if(fs::is_directory(p))
    {
        std::cout << p << " is a directory containing:\n";
        
        for (const auto & entry : fs::directory_iterator(p))
            std::cout << entry.path().string() << std::endl;
    }
}