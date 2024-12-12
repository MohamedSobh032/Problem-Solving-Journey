#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct person {
    int id;
    person* left;
    person* right;
    person(int id = 0, person* left = nullptr, person* right = nullptr): id(id), left(left), right(right) {}
};

struct department {
    int id;
    person* persons;
    department* left;
    department* right;
    department(int id = 0, department* left = nullptr, department* right = nullptr)
        : id(id), left(left), right(right), persons(nullptr) {}
};

person* insert_person(person* root, const int& per_id) {
    
    if (!root) {
        root = new person(per_id);
        return root;
    }
    
    if (root->id > per_id)
        root->left = insert_person(root->left, per_id);
    else
        root->right = insert_person(root->right, per_id);
    return root;
}

department* insert_dep(department* root, const int& dep_id, const int& per_id) {
    
    if (!root) {
        root = new department(dep_id);
        root->persons = insert_person(root->persons, per_id);
        return root;
    }
    
    if (root->id == dep_id) {
        root->persons = insert_person(root->persons, per_id);
        return root;
    }
    
    if (root->id > dep_id)
        root->left = insert_dep(root->left, dep_id, per_id);
    else
        root->right = insert_dep(root->right, dep_id, per_id);
    
    return root;
}


std::pair<int, bool> find_person(person* root, const int& per_id) {
    
    if (!root)
        return std::make_pair(0, false);

    if (root->id == per_id)
        return std::make_pair(1, true);
    
    if (root->id < per_id) {
        std::pair<int, bool> p = find_person(root->right, per_id);
        return std::make_pair(p.first + 1, p.second);
    } else {
        std::pair<int, bool> p = find_person(root->left, per_id);
        return std::make_pair(p.first + 1, p.second);
    }
}

std::pair<int, bool> find_dep(department* root, const int& dep_id, const int& per_id) {
    
    if (!root)
        return std::make_pair(0, false);
    
    if (root->id == dep_id) {
        std::pair<int, bool> p = find_person(root->persons, per_id);
        return std::make_pair(p.first + 1, p.second);
    }
    
    if (dep_id > root->id) {
        std::pair<int, bool> p = find_dep(root->right, dep_id, per_id);
        return std::make_pair(p.first + 1, p.second);
    } else {
        std::pair<int, bool> p = find_dep(root->left, dep_id, per_id);
        return std::make_pair(p.first + 1, p.second);
    }
}


int main() {
    
    int N, Q; std::cin >> N >> Q;
    
    int dep_id, per_id;
    std::cin >> dep_id >> per_id;
    department* root_dep = nullptr;
    root_dep = insert_dep(root_dep, dep_id, per_id);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> dep_id >> per_id;
        insert_dep(root_dep, dep_id, per_id);
    }
    
    for (int i = 0; i < Q; i++) {
        std::cin >> dep_id >> per_id;
        std::pair<int, bool> p = find_dep(root_dep, dep_id, per_id);
        cout << p.first << ' ' << p.second << '\n';
    }
}