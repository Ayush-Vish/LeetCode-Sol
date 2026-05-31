#include<bits/stdc++.h>
using namespace std;


/**
 * 
 * 
 * Flyweight Design Pattern
 * Used to minimize memory usage by sharing as much data as possible with similar objects.
 * We have Shared (intrinsic) state and Unshared (extrinsic) state.
 * 
 */

class TreeType {
    string name;
    string color;

public:
    TreeType(string name, string color) : name(name), color(color) {}

    void draw(int x, int y) {
        cout << "Drawing " << name << " tree of color "
             << color << " at (" << x << "," << y << ")\n";
    }
};


class TreeFactory {
    unordered_map<string, TreeType*> cache;

public:
    TreeType* getTreeType(string name, string color) {
        string key = name + "_" + color;

        if (cache.find(key) == cache.end()) {
            cache[key] = new TreeType(name, color);
        }
        return cache[key];
    }

    ~TreeFactory() {
        for (auto& p : cache)
            delete p.second;
    }
};
class Tree {
    int x, y;                 // extrinsic state
    TreeType* type;           // shared flyweight

public:
    Tree(int x, int y, TreeType* type)
        : x(x), y(y), type(type) {}

    void draw() {
        type->draw(x, y);
    }
};
int main() {
    TreeFactory factory;

    vector<Tree> forest;

    forest.push_back(Tree(1, 2, factory.getTreeType("Oak", "Green")));
    forest.push_back(Tree(3, 4, factory.getTreeType("Oak", "Green")));
    forest.push_back(Tree(5, 6, factory.getTreeType("Pine", "Dark Green")));

    for (auto& tree : forest)
        tree.draw();
}
