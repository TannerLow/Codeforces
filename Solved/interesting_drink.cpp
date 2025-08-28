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

    int n;
    std::cin >> n;
    std::vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    int q;
    std::cin >> q;

    std::sort(prices.begin(), prices.end());
    while(q--) {
        int m;
        std::cin >> m;
        // 1,2,3,4,5,5,6
        auto it = std::upper_bound(prices.begin(), prices.end(), m);
        std::cout << (it - prices.begin()) << std::endl;
    }

    return 0;
}
