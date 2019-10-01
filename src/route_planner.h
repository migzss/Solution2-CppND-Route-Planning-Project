#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    // Add public variables or methods declarations here.
    float GetDistance() { return distance; }
    void AStarSearch(void);
    float CalculateHValue(const RouteModel::Node *node);
    void AddNeighbors(RouteModel::Node *current_node);
    std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *current_node);
    RouteModel::Node *NextNode();

  private:
    // Add private variables or methods declarations here.
    RouteModel &m_Model;
    RouteModel::Node *start_node, *end_node;
    float distance;
    std::vector<RouteModel::Node*> open_list;

    
};

#endif