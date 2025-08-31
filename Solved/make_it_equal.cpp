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

        int n, k;
        std::cin >> n >> k;
        std::map<int, int> s;
        std::map<int, int> t;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            s[x % k]++;
            //std::cout << "s: " << (x % k) << "->" << s[(x % k)] << std::endl;
        }
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            t[x % k]++;
            //std::cout << "t: " << (x % k) << "->" << t[(x % k)] << std::endl;
        }

        // remove like elements
        auto sit = s.begin();
        for(; sit != s.end();) {
            auto tit = t.find(sit->first);
            if(tit != t.end()) {
                //std::cout << "found " << sit->first << " in both" << std::endl;
                int shared = std::min(sit->second, tit->second);
                sit->second -= shared;
                tit->second -= shared;
            
                if(tit->second == 0) {
                    t.erase(tit);
                }
                if(sit->second == 0) {
                    sit = s.erase(sit);
                    continue;
                }
            }
            sit++;
        }

        // remove compliments
        sit = s.begin();
        for(; sit != s.end();) {
            auto tit = t.find(abs(k - sit->first));
            if(tit != t.end()) {
                //std::cout << "found " << sit->first << " in s and its compliment in t" << std::endl;
                int shared = std::min(sit->second, tit->second);
                //std::cout << "shared count of " << shared << std::endl;
                sit->second -= shared;
                tit->second -= shared;
            
                if(tit->second == 0) {
                    t.erase(tit);
                }
                if(sit->second == 0) {
                    sit = s.erase(sit);
                    continue;
                }
            }
            sit++;
        }

        if(s.size() > 0 or t.size() > 0) {
            std::cout << "NO\n";
        }
        else {
            std::cout << "YES\n";
        }
    }
    
    return 0;
}


// operations
// |x-k| cycles between x and its compliment, and compliment + c*k
// x+k -> x+c*k

// what we can get
// compliment y
// y
// x + c*k | c >= 1
// y + c*k | c >= 1

// idea: simplify nums in T and S to remove multiples of k
// ex. k=5, 19 -> 19 - (3*k) -> 4
// equivalent to 19 % 5 = 4
// then it just becomes a matter of equal to or equal to compliment

// k=5
// 6 2 9  -> 1 2 4 -> 1 2 4
// 8 4 11 -> 3 4 1 -> 1 3 4
// 1=1, 2 is compliment to 3, 4=4
// YES

// k=7
// 2 8 -> 2 1
// 2 9 -> 2 2
// 2=2, 1 is not compliment to 2
// NO