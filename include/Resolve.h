/**
 * @file Resolve.h
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief Resolve
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once

#include <functional>

#include "Graph.h"
#include "Model.h"
#include "PriorityQueue.h"
#include "Utility.h"

using namespace std;

namespace Road {
class Resolve {
 public:
  Resolve() = default;
  ~Resolve() = default;
  // Set
  void set_size(const int width, const int height) {
    _graph.init(width, height);
  }
  void set_walls(const vector<GridLocation> walls) {
    for (auto wall : walls) {
      _graph.set_wall(wall);
    }
  }
  void set_start(const GridLocation start) { _start = start; }
  void set_goal(const GridLocation goal) { _goal = goal; }
  // Work flow///
  void run();
  // Get
  GridLocation get_start() const { return _start; }
  GridLocation get_goal() const { return _goal; }
  // Reconstruct path
  vector<GridLocation> reconstruct_path(
      GridLocation start, GridLocation goal,
      unordered_map<GridLocation, GridLocation> came_from);
  // Draw
  void draw(const Graph& graph, int field_width,
            unordered_map<GridLocation, int>* distances,
            unordered_map<GridLocation, GridLocation>* point_to,
            vector<GridLocation>* path);

 private:
  GridLocation _start;
  GridLocation _goal;
  Graph _graph;
};
}  // namespace Road