#include "HexCell.h"
#include <iostream>


#include <cmath>

HexCell::HexCell(int Q, int R) {
    /**
     * @todo Your code here!
     */
    q = Q;
    r = R; 

    path_dist_from_start = 0; 

    for (int i = 0; i < 6; i++) {
        neighbours[i] = nullptr;
        links[i] = nullptr;
    }
}

void HexCell::link(HexCell* cell) {
    /**
     * @todo Your code here!
     */
    // cell is nullpointer or cell is already linked to this -> return
    if (cell == nullptr || is_linked(cell)) {
        return;
    }

    // if cell is neighbour to this, then add to linked
    // check if it's neighbours using distance
    // get neighbour side
    int dist = distance(cell);

    if (dist == 1) {
        int side = get_neighbour_side(cell);
        if (side == -1) {
            return;
        }
        links[side] = cell;
        // cell->links[cell->get_neighbour_side(this)] = this;
        cell->link(this); // not sure if this works :D
    }
    return;
    // for (int i = 0; i < 6; i++) {
    //     HexCell * curr_cell = new HexCell(neighbours[i].first, neighbours[i].second);
    //     if (curr_cell->q == cell->q && curr_cell->r == cell->r) {
    //         // std::cout << i << std::endl;
    //         links[i] = cell;
    //         // cell->links[cell->get_neighbour_side(this)] = this;
    //         cell->link(this); // not sure if this works :D
    //         return;
    //     }
    // }
}

int HexCell::get_neighbour_side(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
        
    if (cell == nullptr) {
        return -1;
    }
    vector<pair<int,int>> this_neighbours = {
        {q, r - 1}, {q + 1, r - 1}, {q + 1, r},
        {q, r + 1}, {q - 1, r + 1}, {q - 1, r}
    };
    int cell_q = cell->q;
    int cell_r = cell->r;

    for (int i = 0; i < 6; i++) {
        pair<int,int> coord = this_neighbours[i];

        if (coord.first == cell_q && coord.second == cell_r) {
            return i;
        }
    }

    // for (int i = 0; i < 6; i++) {
    //     if (neighbours[i] == cell) {
    //         return i;
    //     }
    // } 
    return -1;
}

bool HexCell::is_linked(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

     if (cell == nullptr) {
        return false;
     }

    for (int i = 0; i < 6; i++) {
        if (links[i] == nullptr) {
            continue;
        }
        if (links[i]->q == cell->q && links[i]->r == cell->r) {
            return true;
        }
    }
    // return links.contains(cell);
    return false;
}

int HexCell::distance(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
     if (cell == nullptr) {
        return -1;
     }
    
    return (abs(q - cell->q) + abs(q - cell->q + r - cell->r) + abs(r - cell->r)) / 2;

}

bool HexCell::is_edge() const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
     for (int i = 0; i < 6; i++) {
        if (neighbours[i] == nullptr) {
            return true;
        }
     }
    return false;
}


