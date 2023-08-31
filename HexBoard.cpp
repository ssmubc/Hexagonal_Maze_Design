#include "HexBoard.h"

#include <iostream>

#include "queue.h"
#include "stack.h"

HexBoard::HexBoard(int radius) {
    /**
     * @todo Your code here!
     */
    this->radius = radius;
    longest_path_dist = 0;
    start_coord = {0,0};

    create_board();

    configure_cells();
}

void HexBoard::create_board() {
    /**
     * @todo Your code here!
     */

    // add starting cell 
    HexCell * start = new HexCell(0,0);
    cells[{0,0}] = start;

    int rad = radius; // radius of hexboard

    for (int q = -rad; q < rad; q++) { // q coordinate
        for (int r = -rad; r < rad; r++) { // r coordinate
            HexCell * cell = new HexCell(q, r);
            
            if (cells.find({q,r}) == cells.end() && cell->distance(start) < rad) { // if cell doesn't exist in cells and cell distance is < radius of hexboard
                cells[{q,r}] = cell;                                              // add cell to cells
            } else {
                delete cell;
            }
        }
    }
}

void HexBoard::configure_cells() {
    /**
     * @todo Your code here!
     */

    for (auto kv: cells) {
        int kv_q = kv.first.first;
        int kv_r = kv.first.second;
        HexCell * curr = kv.second;

        vector<pair<int, int>> kv_neighbours = get_neigh_coords(kv.first);

        int i = 0; // index counter

        for (auto & coord: kv_neighbours) {
            auto it = cells.find(coord);

            if (it != cells.end()) {
                curr->neighbours[i] = it->second;
            }
            i++;
        }
        
       
    }

}

void HexBoard::generate_maze(pair<int, int> start_coord, double branch_prob) {
    /**
     * @todo Your code here!
     */
    // Initialize start cell
    HexCell* start_cell = cells[start_coord];
    start_cell->path_dist_from_start = 0;

    // Initialize start coordinate
    this->start_coord = start_coord;

    // Initialize stack
    Stack<HexCell *> cell_stack;
    cell_stack.push(start_cell);

    map<pair<int, int>, bool> visited = {
            {start_coord, true}
    };

    int longest_path = 0;    

    // DFS to generate maze
    while (!cell_stack.isEmpty()) {
        // Peek to top of stack
        HexCell * curr_cell = cell_stack.peek();
        int q_coord = curr_cell->q;
        int r_coord = curr_cell->r;
        pair<int, int> curr_coord = {q_coord, r_coord};

        

        // Choose a neighbour to visit
        HexCell * neigh_cell = chooseNeighbour(curr_cell, visited, branch_prob);

        if (neigh_cell != NULL) {

            curr_cell->link(neigh_cell);
            visited.insert({{neigh_cell->q, neigh_cell->r}, true});

            // Update neighbour's path distance and mark as discovered
            int q = neigh_cell->q;
            int r = neigh_cell->r;
            pair<int, int> neigh_coord = {q, r};
            
            neigh_cell->path_dist_from_start = curr_cell->path_dist_from_start + 1;
            int distance = neigh_cell->path_dist_from_start;

            if (distance > longest_path_dist) {
                longest_path_dist = distance;
                
            }

            if (neigh_cell->is_edge() && distance > longest_path) {
                end_coord = {q, r};
                longest_path = distance;
            }

            cell_stack.push(neigh_cell);  
            } else {
            cell_stack.pop();
        }
    }
}

void HexBoard::solve_maze() {
    /**
     * @todo Your code here!
     */

    map<pair<int,int>, bool> visited;

    //Starting at end
    HexCell * curr_cell = cells[end_coord];
    Stack<HexCell*> path;
    path.push(curr_cell);

    while (!path.isEmpty()) {
        
        curr_cell = path.peek();

        if (curr_cell->q == start_coord.first && curr_cell->r == start_coord.second) {
            break;
        }

        visited[{curr_cell->q, curr_cell->r}] = true;

        int closest_dist = curr_cell->path_dist_from_start;
        HexCell* closest_neigh = nullptr;

        for (HexCell * neigh : curr_cell->neighbours) { // need to be linked !!!
            if (neigh && visited.find({neigh->q, neigh->r}) == visited.end() && curr_cell->is_linked(neigh)) {
                int dist = neigh->path_dist_from_start;
                if (dist < closest_dist) {
                    closest_dist = dist;
                    closest_neigh = neigh;
                }
            }
        }

        if (closest_neigh) {
            path.push(closest_neigh);
        } else {
            path.pop();
        }
    }

    while (!path.isEmpty()) {
            HexCell * cell = path.pop();
            solution.push_back({cell->q, cell->r});
    }
}