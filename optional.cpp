#include <iostream>
#include <optional>
#include <variant>
#include <string>

/// Overload pattern
template<class... Ts> 
struct overloaded : Ts... { 
    using Ts::operator()...; 
};
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
    // Declaration of Optional type
    std::optional<std::variant<int, std::string>> optional_variant;

    // Initialization in an empty state
    optional_variant = std::nullopt;

    // Initialization (With a value - using in_place for efficiency)
    optional_variant.emplace(std::in_place_type<int>, 42);

    // Checking for a value
   if (optional_variant.has_value()) {
    std::visit(overloaded {
        [](int arg) { 
            std::cout << "Value is an int: " << arg << std::endl; 
        },
        [](const std::string& arg) { 
            std::cout << "Value is a string: " << arg << std::endl; 
        }
    }, *optional_variant);
    } else {
        std::cout << "Optional is empty." << std::endl;
    }

    // Get_if check, not throwing
    optional_variant.emplace(std::in_place_type<int>, 100);
    if (auto int_ptr = std::get_if<int>(&*optional_variant)) {
        std::cout << "Got int via get_if: " << *int_ptr << std::endl;
    }

    return 0;
}
