#include <iostream>
#include <string>

// Functor class
class OptionAdder {
  public:
    // We overload the function call () operator
    OptionAdder& operator()(const std::string& names, const std::string& help_text) {
        std::cout << "  - Registered Option: '" << names << "' (Help: " << help_text << ")"
                  << std::endl;

        // By returning *this we can change together function calls
        return *this;
    }
};

// Main options class
class Options {
  public:
    // The method that starts the chain
    OptionAdder add_options() {
        // Just creates and returns an instance of the OptionAdder functor.
        std::cout << "Starting option registration chain..." << std::endl;
        return OptionAdder();
    }
};

int main() {
    Options myOptions;

    myOptions.add_options()("help", "Show help message")("file", "Input script path")(
        "v", "Enable verbose output");

    return 0;
}