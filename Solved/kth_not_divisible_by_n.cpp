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

    int t;
    std::cin >> t;

    while(t--) {
        ull n,k;
        std::cin >> n >> k;

        ull a = k / (n-1);
        ull b = a * (n-1);
        ull c = a * n;
        if(b == k) {
            std::cout << (c-1) << std::endl;
            continue;
        }
        ull d = c + (k - b);
        std::cout << d << std::endl;

        //n-1,N,n-1,N,n-1,...
        // 7, 97
        // 97 / (7-1) = 16
        // 16 * (7-1) = 96
        // 16 * 7 = 112
        // 112 + (97 - 96) = 113

        // 6, 30 | special case where n and (n-1) are factors of k
        // 30 / 5 = 6
        // 6 * (6-1) = 30
        // 6 * 6 = 36
        // 36 + (30 - 30) [X]
        // just do 6 * 6 - 1 instead
    }

    return 0;
}
