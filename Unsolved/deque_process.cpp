#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <deque>

typedef unsigned long long ull;
typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {

        int n;
        std::cin >> n;
        std::deque<int> p;
        while(n--) {
            int pi;
            std::cin >> pi;
            p.push_back(pi);
        }

        std::vector<int> q;
        std::string answer;
        bool qIncreasing = false;
        while(not p.empty()) {
            if(qIncreasing) {
                bool popFront = p.front() < p.back();
                if(popFront) {
                    q.push_back(p.front());
                    p.pop_front();
                    answer += 'L';
                }
                else {
                    q.push_back(p.back());
                    p.pop_back();
                    answer += 'R';
                }
            }
            else {
                bool popFront = p.front() < p.back();
                if(popFront) {
                    q.push_back(p.front());
                    p.pop_front();
                    answer += 'L';
                }
                else {
                    q.push_back(p.back());
                    p.pop_back();
                    answer += 'R';
                }
            }

            if(q.size() > 1) {
                qIncreasing = q.back() > q[q.size()-2];
            }
        }

        for(int num : q) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
        std::cout << answer << '\n';

    }
    
    return 0;
}
