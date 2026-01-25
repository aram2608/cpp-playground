#include <string>
#include <print>
#include <numeric>
#include <vector>
#include <map>

void iter_map() {
    std::map<int, int> imap{
        {1, 1}, 
        {2, 2}, 
        {3, 3}
    };

    // Iterator based
    for (auto it = imap.begin(); it != imap.end(); ++it) {
        std::println("Key: {}, Value: {}", it->first, it->second);
        if (it->first == 1) {
            std::println("{}", it->second);
        }
    }

    // Range based for a ref
    for (const auto& pair : imap) {
        std::println("Key: {}, Value: {}", pair.first, pair.second);
    }

    // Structure based for a ref
    for (const auto& [key, value] : imap) {
        std::println("Key: {}, Value: {}", key, value);
    }
}

void iter_string() {
    std::string istring{"I\nam\nawesome\nYEAH!"};
    // Iterator
    for (auto it = istring.begin(); it != istring.end(); ++it) {
        std::println("{}", *it);
    }

    // Range based
    for (char& c: istring) {
        std::println("{}", c);
    }

    // Insertion without crashing, this is very dumb
    for (auto it = istring.begin(); it != istring.end(); ) {
        if (*it == '\n') {
            it = istring.insert(it, '!');
            it += 2;
        } else {
            ++it;
        }
    }
    std::println("{}", istring);
}

void iter_vect() {
    std::vector<int> ivect(5);
    std::iota(ivect.begin(), ivect.end(), 10);
    // Range
    for (const auto& num: ivect) {
        std::println("{}", num);
    }

    // Iterator
    for (auto it = ivect.begin(); it != ivect.end(); ++it) {
        std::println("{}", *it);
    }

    // Range we can modify
    for (auto& num: ivect) {
        num *= 4;
        std::println("{}", num);
    }

    for (auto it = ivect.begin(); it != ivect.end();) {
        if (*it == 40) {
            std::println("{}: {}", "Deleting", *it);
            it = ivect.erase(it);
        } else {
            std::println("{}", *it);
            ++it;
        }
    }
}

int main() {
    iter_map();
    iter_string();
    iter_vect();
    return 0;
}