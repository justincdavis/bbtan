#include "grid.h"

Grid::Grid()
{
    cols = 10;
    rows = 10;
    margin_bottom = 10;
    margin_left = 10;
    margin_right = 10;
    margin_top = 10;
}

int Grid::cellLeftPos(Graphics& g, int col)
{
    colWidth = ((double)(g.width() - margin_left - margin_right))/cols;
    return margin_left + col * colWidth;
}

int Grid::cellTopPos(Graphics& g, int row)
{
    rowHeight = ((double)(g.height() - margin_top - margin_bottom))/rows;
    return margin_top + row * rowHeight;
}

void Grid::draw(Graphics& g)
{
    int leftEdge = cellLeftPos(g, 0);
    int rightEdge = cellLeftPos(g, cols);
    int topEdge = cellTopPos(g, 0);
    int bottomEdge = cellTopPos(g, rows);
    g.polygon({{leftEdge, topEdge}, {rightEdge, topEdge}, {rightEdge, bottomEdge}, {leftEdge, bottomEdge}}, BLACK, GREEN);
}

void Grid::fillCell(Graphics& g, int row, int col, Color c, double fillAmount)
{
    int leftEdge   = cellLeftPos(g, col)+1;
    int rightEdge  = cellLeftPos(g, col+1)-1;
    int topEdge    = cellTopPos(g, row)+1;
    int bottomEdge = cellTopPos(g, row+1)-1;

    int centerX = (leftEdge + rightEdge) / 2;
    int centerY = (topEdge + bottomEdge) / 2;

    leftEdge = (leftEdge - centerX)*fillAmount + centerX;
    rightEdge = (rightEdge - centerX)*fillAmount + centerX;

    topEdge = (topEdge - centerY)*fillAmount + centerY;
    bottomEdge = (bottomEdge - centerY)*fillAmount + centerY;

    g.polygon({{leftEdge, topEdge}, {rightEdge, topEdge}, {rightEdge, bottomEdge}, {leftEdge, bottomEdge}}, c, c);
}

int Grid::getRow(Graphics& g, int mouseY){

    double height = g.height() - margin_top - margin_bottom;
    double slope = rows/height;

    double b = -1 * slope * margin_left;

    int row = mouseY*slope + b;
    return row;
}

int Grid::getCol(Graphics& g, int mouseX){

    double width = g.width() - margin_left - margin_right;
    double slope = cols/width;

    double b = -1 * slope * margin_left;

    int col = mouseX*slope + b;
    return col;
}

bool Grid::validRowAndCol(int row, int col){

    bool validRow = true;
    if(row < 0 || row > rows-1){
        validRow = false;
    }

    bool validCol = true;
    if(col < 0 || col > cols-1){
        validCol = false;
    }

    if(validCol == false || validRow == false){
        return false;
    }

    return true;
}
