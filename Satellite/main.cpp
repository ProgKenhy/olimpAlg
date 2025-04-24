#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

struct hash_pair {
    size_t operator()(const std::pair<int, int>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

struct Photo {
    int x_ld, y_ld, x_ru, y_ru;
};

int main() {
    int W, H;
    std::cin >> W >> H;
    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    std::vector<Photo> photos(N);
    for (int i = 0; i < N; i++) {
        std::cin >> photos[i].x_ld >> photos[i].y_ld >> photos[i].x_ru >> photos[i].y_ru;
        if (photos[i].x_ld > photos[i].x_ru || photos[i].y_ld > photos[i].y_ru) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    using Position = std::pair<int, int>;
    using PositionSet = std::unordered_set<Position, hash_pair>;

    PositionSet current_reachable;
    for (int x = photos[0].x_ld; x <= photos[0].x_ru; x++) {
        for (int y = photos[0].y_ld; y <= photos[0].y_ru; y++) {
            current_reachable.insert({ x, y });
        }
    }

    for (int i = 1; i < N; i++) {
        PositionSet next_reachable;
        for (const auto& pos : current_reachable) {
            int x = pos.first, y = pos.second;
            std::vector<Position> neighbors = { {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1} };
            for (const auto& neighbor : neighbors) {
                int nx = neighbor.first, ny = neighbor.second;
                if (nx >= photos[i].x_ld && nx <= photos[i].x_ru && ny >= photos[i].y_ld && ny <= photos[i].y_ru) {
                    next_reachable.insert(neighbor);
                }
            }
        }
        if (next_reachable.empty()) {
            std::cout << "No" << std::endl;
            return 0;
        }
        current_reachable = std::move(next_reachable);
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
