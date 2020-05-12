#pragma once

#include "../../general.hpp"
#include "../graph.h"
#include "../../recursive_function.hpp"

template <class Edge>
void centroidDecomposition(Graph<Edge> &graph, const function<void(int, const vector<bool> &, const vi &)> &callback) {
  int n = graph.vertexCount;
  vector<bool> forb(n, false);
  vector<int> size(n);
  RecursiveFunction doWork = [&](const auto &workSelf, int workVertex) -> void {
    vi part;
    RecursiveFunction dfs = [&](const auto &self, int vert, int last) -> void {
      size[vert] = 1;
      part.push_back(vert);
      for (auto *e : graph[vert]) {
        int next = e->to;
        if (next == last || forb[next]) {
          continue;
        }
        self(next, vert);
        size[vert] += size[next];
      }
    };
    dfs(workVertex, -1);
    int end = -1;
    for (int i : part) {
      if (2 * size[i] >= part.size()) {
        bool good = true;
        for (auto *e : graph[i]) {
          int to = e->to;
          if (!forb[to] && size[to] * 2 > part.size() && size[to] < size[i]) {
            good = false;
            break;
          }
        }
        if (good) {
          end = i;
          break;
        }
      }
    }
    
    callback(end, forb, part);
    
    forb[end] = true;
    for (auto *e : graph[end]) {
      int to = e->to;
      if (!forb[to]) {
        workSelf(to);
      }
    }
  };
  doWork(0);
}

