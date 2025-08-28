#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>

typedef unsigned long long ull;
typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n, m, a;
    std::cin >> n >> m >> a;

    ull width = n / a;
    if(width * a != n) {
        width++;
    }

    ull height = m / a;
    if(height * a != m) {
        height++;
    }

    std::cout << (width * height) << std::endl;
    return 0;
}
