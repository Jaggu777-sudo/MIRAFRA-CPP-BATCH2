#include <iostream>
#include <memory>
#include <queue>
#include <string>
// BST
struct Module {
    std::string name;
    bool status = false;   // false = OFF, true = ON
};

struct Node {
    Module module;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(const std::string& name)
        : module{ name, false } {}
};

// BFS traversal will activate module
void activateModules(const std::unique_ptr<Node>& root)
{
    if (!root) return;

    std::queue<Node*> q;   // non-owning raw pointers
    q.push(root.get());

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

    
        current->module.status = true;

        std::cout << "Activating Module: "
                  << current->module.name
                  << " | Status: "
                  << (current->module.status ? "ON" : "OFF")
                  << std::endl;

        if (current->left)
            q.push(current->left.get());

        if (current->right)
            q.push(current->right.get());
    }
}

int main()
{
    // ECU root
    auto root = std::make_unique<Node>("ECU");

    // Level 1
    root->left = std::make_unique<Node>("Safety");
    root->right = std::make_unique<Node>("Dashboard");

    // Level 2
    root->left->left = std::make_unique<Node>("Airbag");
    root->left->right = std::make_unique<Node>("ABS");

    root->right->left = std::make_unique<Node>("Speed");
    root->right->right = std::make_unique<Node>("Fuel");

    std::cout << "ECU Startup Sequence (Level Order):\n\n";

    activateModules(root);

    return 0;
}
