#ifndef GRID_H
#define GRID_H

#include "graphics.h"
#include "vec2d.h"
#include <vector>
#include "balls.h"
#include "celltype.h"

using namespace mssm;
using namespace std;

class Grid
{
public:
    int rows;
    int cols;
    int margin_left;
    int margin_right;
    int margin_top;
    int margin_bottom;
    int colWidth;
    int rowHeight;
public:
    Grid();
    void draw(Graphics& g);
    void fillCell(Graphics& g, int row, int col, Color c, double fillAmount);
    int cellLeftPos(Graphics& g, int col);
    int cellTopPos(Graphics& g, int row);
    int getRow(Graphics& g, int mouseY);
    int getCol(Graphics& g, int mouseX);
    bool validRowAndCol(int row, int col);
    vector<Celltype> generateRow(Graphics& g, vector<Ball> balls, vector<vector<Celltype>> cells);
};

#endif // GRID_H
