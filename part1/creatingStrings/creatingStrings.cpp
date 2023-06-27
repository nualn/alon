#include <iostream>
#include <string>
#include <set>


class Permutations {
public:
    Permutations(std::string s) {
        str = s;
    };

    void generate() {
        permutate(0);
    };

    int size() {
        return permutations.size();
    };

    std::string str;
    std::set<std::string> permutations;
private:

    void permutate(int fromIndex) {

        for (int i = fromIndex; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                std::string newStr = str;
                std::swap(newStr[i], newStr[j]);
                Permutations newPermutation = Permutations(newStr);

                newPermutation.permutate(i + 1);

                permutations.merge(newPermutation.permutations);
            }
        }

        permutations.insert(str);
    };
};


int main() {
    std::string str;
    std::cin >> str;

    Permutations permutations = Permutations(str);
    permutations.generate();

    std::cout << permutations.size() << std::endl;

    std::set<std::string> permSet = permutations.permutations;

    for (Permutations p : permSet)
        std::cout << p.str << std::endl;
};
