#include <iostream>
#include <optional>
#include <string>
#include <vector>
std::optional<int> find_value(const std::vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return i; 
        }
    }
    return std::nullopt; 
}

int main() {
    std::vector<int> data = {10, 20, 30};

    auto result = find_value(data, 20);

    if (result.has_value()) {
        std::cout << "Value found at index: " << *result << std::endl; // Access using operator*
    } else {
        std::cout << "Value not found." << std::endl;
    }
}

