#include <iostream>
#include <vector>

int main()
{
    std::vector<std::pair<int,int>> sparse;

    // Insert non-zero elements
    sparse.push_back({3, 5});
    sparse.push_back({6, 3});

    // Print sparse data
    for (const auto& [index, value] : sparse)
    {
        std::cout << "Index: "
                  << index
                  << " Value: "
                  << value << "\n";
    }

    return 0;
}

