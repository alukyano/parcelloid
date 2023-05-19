#include <boost/program_options.hpp>
#include <string>
#include <iostream>
namespace po = boost::program_options;
int main(int argc, char** argv) {
    // Arguments will be stored here
    double value;
    // Configure options here
    po::options_description desc ("Allowed options");
    desc.add_options ()
        ("help,h", "print usage message")
        ("value,v", po::value(&value), "The value");
    // Parse command line arguments
    po::variables_map vm;
    po::store (po::command_line_parser (argc, argv).options (desc).run (), vm);
    po::notify (vm);
    // Check if there are enough args or if --help is given
    if (vm.count ("help") || !vm.count ("value")) {
        std::cerr << desc << "\n";
        return 1;
    }
    // Your code goes here!
    std::cout << value << std::endl;
}
