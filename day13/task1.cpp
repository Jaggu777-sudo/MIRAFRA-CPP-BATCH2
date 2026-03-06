#include <iostream>
#include <memory>
using namespace std;

class BST {
public:
    struct Tree {
        string car_name;
        double rating;
        unique_ptr<Tree> left;
        unique_ptr<Tree> right;

        Tree(string cr, double r)
            : car_name(cr), rating(r) {}
    };

    unique_ptr<Tree> root = nullptr;

    void insert(string s, double r) {
        insert_implementation(root, s, r);
    }

    void inorder() const {
        inorder_imp(root.get());
    }

    bool search(string s) const {
        return search_impl(root.get(), s);
    }

private:

    bool search_impl(Tree* node, string s) const {
        if (!node)
            return false;

        if (node->car_name == s)
            return true;

        if (s < node->car_name)
            return search_impl(node->left.get(), s);
        else
            return search_impl(node->right.get(), s);
    }
    void inorder_imp(Tree* node) const {
        if (!node)
            return;

        inorder_imp(node->left.get());
        cout << "car_name: " << node->car_name
             << " car_rating: " << node->rating << endl;
        inorder_imp(node->right.get());
    }

    void insert_implementation(unique_ptr<Tree>& node,
                               string s, double r) {
        if (!node) {
            node = make_unique<Tree>(s, r);
            return;
        }

        if (s < node->car_name)
            insert_implementation(node->left, s, r);
        else
            insert_implementation(node->right, s, r);
    }
};

int main() {
    BST obj;

    obj.insert("Fortuner", 5);
    obj.insert("BMW", 4.5);
    obj.insert("Rolls Royce", 4);
    obj.insert("Mercedies", 3.75);

    cout << boolalpha << obj.search("Mercedies") << endl;

    obj.inorder();
}

