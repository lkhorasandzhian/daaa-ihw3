#include <queue>
#include <set>
#include "searching_algorithms.h"

int64_t searchDijkstraPq(int destination, const std::vector<std::vector<std::pair<int, int64_t>>> &g) {
    int n = destination;

    std::vector<int> p(n);

    std::vector<int64_t> d(n, INT64_MAX);
    d[0] = 0;

    std::priority_queue<std::pair<int64_t, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        int v = q.top().second;
        int64_t cur_d = -q.top().first;
        q.pop();

        if (cur_d > d[v]) {
            continue;
        }

        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.emplace(-d[to], to);
            }
        }
    }

    return d[destination];
}



int64_t searchDijkstraSet(int destination, const std::vector<std::vector<std::pair<int, int64_t>>> &g) {
    int n = destination;

    std::vector<int> p(n);

    std::vector<int64_t> d(n, INT64_MAX);
    d[0] = 0;

    std::set<std::pair<int64_t, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase(std::make_pair(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.emplace(d[to], to);
            }
        }
    }

    return d[destination];
}



std::vector<bool> checkUsed(const std::vector<int64_t> &d, const std::vector<Edge> &edges) {
    std::vector<bool> used(static_cast<int>(d.size()), false);

    for (const auto &edge : edges) {
        if ((d[edge.from] != INT64_MAX && d[edge.to] > d[edge.from] + edge.cost) || used[edge.from]) {
            used[edge.to] = true;
        }
    }

    return used;
}

int64_t searchBellmanFord(int destination, const std::vector<Edge> &edges) {
    int n = destination;
    int m = static_cast<int>(edges.size());

    std::vector<int64_t> d(n, INT64_MAX);
    d[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].from] != INT64_MAX) {
                if (d[edges[j].to] > d[edges[j].from] + edges[j].cost) {
                    d[edges[j].to] = std::max(INT64_MIN, d[edges[j].from] + edges[j].cost);
                }
            }
        }
    }

    auto used = checkUsed(d, edges);

    return d[destination];
}



int64_t searchFloydWarshall(int destination, std::vector<std::vector<int64_t>> d) {
    int n = destination;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] != INT64_MAX && d[k][j] != INT64_MAX) {
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    return d[0][destination];
}
