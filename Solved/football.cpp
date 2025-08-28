#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::getline(std::cin, line);
    int count = 0;
    int current = line[0];
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == current) {
            count++;
            if(count >= 7) {
                std::cout << "YES\n";
                return 0;
            }
        }
        else {
            count = 1;
            current = line[i];
        }
    }
    std::cout << "NO\n";
}
