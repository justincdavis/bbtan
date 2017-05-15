#ifndef BALL_H
#define BALL_H
#include "graphics.h"

class Ball
{
public:
    int x;
    int y;
    int width;
    int height;
    int xv;
    int yv;
    mssm::Color c;

public:
    Ball(mssm::Graphics& g);
    void draw(mssm::Graphics& g);
    void update(mssm::Graphics& g);
};

#endif // BALL_H
