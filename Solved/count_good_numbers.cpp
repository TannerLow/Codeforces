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

    std::vector<ll> singles{2, 3, 5, 7};
    std::vector<ll> pairs{2*3, 2*5, 2*7, 3*5, 3*7, 5*7};
    std::vector<ll> triplets{2*3*5, 2*3*7, 2*5*7, 3*5*7};
    std::vector<ll> quads{2*3*5*7};
    std::vector<std::vector<ll>> divisorSets{singles, pairs, triplets, quads};

    int t;
    std::cin >> t;
    while(t--) {

        ll l, r;
        std::cin >> l >> r;

        ll count1 = 0;
        ll factor = 1;
        for(auto& set : divisorSets) {
            for(ll num : set) {
                count1 += factor * ((l-1) / num);
            }
            factor *= -1;
        }

        ll count2 = 0;
        factor = 1;
        for(auto& set : divisorSets) {
            for(ll num : set) {
                count2 += factor * (r / num);
            }
            factor *= -1;
        }

        std::cout << ((r-l+1)-(count2-count1)) << '\n';

    }
    
    return 0;
}

// every positive integer has a prime factorization
// any number divisible by 2, 3, 5, 7 is bad
// ex. 2 to 100
// 100 / 2 = 50 bad numbers
// 100 / 3 = 33 bad numbers
// 100 / 5 = 20 bad numbers
// 100 / 7 = 14 bad numbers
// total = 50 + 33 + 20 + 14 = 117 
// then check for where overlap happened
// 100 / (2*3) = 16 overlapped numbers
// 100 / (2*5) = 10 overlapped numbers
// 100 / (2*7) = 7 overlapped numbers
// 100 / (3*5) = 6 overlapped numbers
// 100 / (3*7) = 4 overlapped numbers
// 100 / (5*7) = 2 overlapped numbers
// 100 / (2*3*5) = 3 overlapped numbers
// 100 / (3*5*7) = 0 overlapped number
// 100 / (2*3*5*7) = 0 overlapped
// 98 - (117 - 16 - 10 - 7 - 6 - 4 - 2 - 3 - 0 - 0)

// ex 13 to 37
// 12 / 2 = 6
// 12 / 3 = 4
// 12 / 5 = 2
// 12 / 7 = 1
// total = 13
// 12 / (2*3) = 2
// 12 / (2*5) = 1
// 12 / (2*7) = 0
// 12 / (3*5) = 0
// 12 / (3*7) = 0
// 12 / (5*7) = 0

//subtract an additional 1 for One since its not divisible by anything
// 12 - (13 - 3) - 1 = 1 which is the good number 11

// 37 / 2 = 18
// 37 / 3 = 12
// 37 / 5 = 7
// 37 / 7 = 5
// total = 42
// 37 / (2*3) = 6
// 37 / (2*5) = 3
// 37 / (2*7) = 2
// 37 / (3*5) = 2
// 37 / (3*7) = 1
// 37 / (5*7) = 1

// 42 - (37 - 6 - 3 - 2 - 2 - 1 - 1) - 1 = 19 
// i messed up 
