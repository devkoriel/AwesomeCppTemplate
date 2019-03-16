#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>

namespace fs = boost::filesystem;

int main(int argc, char *argv[]) {
    fs::path p(argc>1? argv[1] : ".");

    if(fs::is_directory(p)) {
        std::cout << p << " is a directory containing:\n";

        for(auto& entry : boost::make_iterator_range(fs::directory_iterator(p), {}))
            std::cout << entry.path().string() << "\n";
    }
}
