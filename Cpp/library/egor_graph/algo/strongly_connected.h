#pragma once

#include "../../general.hpp"
#include "../graph.h"
#include "../../range/rev_range.hpp"
#include "../edges/base_edge.h"
#include "../../recursive_function.hpp"

pair<vector<int>, Graph<BaseEdge>> stronglyConnectedComponents(Graph<BaseEdge> &graph) {
  int n = graph.vertexCount;
  vi order;
  vector<bool> visited(n, false);
  vector<int> condensed(n);
  order.reserve(n);
  RecursiveFunction firstDFS = [&](const auto &self, int vert) -> void {
    if (visited[vert]) {
      return;
    }
    visited[vert] = true;
    for (auto *e : graph[vert]) {
      self(e->to);
    }
    order.push_back(vert);
  };
  for (int i : range(n)) {
    if (!visited[i]) {
      firstDFS(i);
    }
  }
  fill(all(visited), false);
  Graph<BaseEdge> result(0);
  int index = 0;
  vector<int> next(n, -1);
  vi queue;
  int key;
  Graph<BaseEdge> gt(n);
  for (int i : range(n)) {
    for (auto *e : graph[i]) {
      gt.addEdge(e->to, i);
    }
  }
  RecursiveFunction secondDFS = [&](const auto &self, int vert) -> void {
    if (visited[vert]) {
      if (condensed[vert] != index) {
        if (next[condensed[vert]] != key) {
          next[condensed[vert]] = key;
          queue.push_back(condensed[vert]);
        }
      }
      return;
    }
    condensed[vert] = index;
    visited[vert] = true;
    for (auto *e : gt[vert]) {
      self(e->to);
    }
  };
  for (int i : RevRange(n)) {
    if (!visited[order[i]]) {
      key = i;
      queue.clear();
      secondDFS(order[i]);
      result.addVertices(1);
      for (int j : queue) {
        result.addEdge(j, index);
      }
      index++;
    }
  }
  return {condensed, graph};
}
