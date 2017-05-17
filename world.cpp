#include "world.h"
#include <iostream>
#include "balls.h"
#include "robot.h"
#include "celltype.h"
#include "grid.h"

using namespace std;
using namespace mssm;

World::World(Graphics& g)
{
    grid = Grid();

    vector<vector<Celltype>> starter;
    for(int i = 0; i < grid.rows; i++){
        vector<Celltype> cells;
        for(int n = 0; n < grid.cols; n++){
            cells.push_back(Celltype::empty);
        }
        starter.push_back(cells);
    }

    cells = starter;
    bbtan = Robot();
    balls = vector<Ball>{3,Ball(g)};
}

void World::update(Graphics&g, int keyPress){

    for (int b = 0; b<balls.size(); ++b)
    {
        balls[b].update(g, bbtan.x, bbtan.y);
    }
}

void World::draw(Graphics& g, int keyPress){

    grid.draw(g);

    for (int b = 0; b<balls.size(); ++b)
    {
        balls[b].draw(g);
    }
    /*
    for (int r = 0; r < grid.rows; ++r) {
        for (int c = 0; c < grid.cols; ++c) {
            if (cells[r][c] == Celltype::square) {
                grid.fillCell(g, r, c, YELLOW, 1);
            }
            else if (cells[r][c] == Celltype::triangle) {
                grid.fillCell(g, r, c, BLUE, 1);
            }
            else if (cells[r][c] == Celltype::empty) {
                grid.fillCell(g, r, c, GREEN, 1);
            }
        }
    }
    */
}

void World::reset(Graphics &g){

    grid = Grid();

    vector<vector<Celltype>> starter;
    for(int i = 0; i < grid.rows; i++){
        vector<Celltype> cells;
        for(int n = 0; n < grid.cols; n++){
            cells.push_back(Celltype::empty);
        }
        starter.push_back(cells);
    }

    cells = starter;
    bbtan = Robot();
    balls = vector<Ball>{3,Ball(g)};

    g.clear();

}

bool World::hasWon(){

    for(unsigned int i = 0; i < cells.size(); i++){
        for(unsigned int n = 0; n < cells[i].size(); n++){
            if(cells[i][n] != Celltype::square){
                return false;
            }
        }
    }
    return true;
}

void World::winningAnime(Graphics& g){

}
