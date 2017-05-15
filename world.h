#ifndef WORLD_H
#define WORLD_H

#include "grid.h"
#include "balls.h"
#include "robot.h"
#include "celltype.h"

using namespace std;

class World
{
public:
    Grid grid;
    Color backgroundColor;
    Color gridColor;
    vector<Ball> balls;
    Robot bbtan;
    vector<vector<Celltype>> cells;
    vector<vector<double>> cellScale;
public:
    World(Graphics& g);
    void draw(Graphics& g, int keyPress);
    void reset(Graphics& g);
    bool hasWon();
    void winningAnime(Graphics& g);
};

#endif // WORLD_H
