#include "balls.h"
#include "graphics.h"
using namespace mssm;

Ball::Ball(Graphics& g)
{
    x = 100;
    y = g.randomDouble(0,g.height());
    height = 50;
    width = 50;
    c= WHITE;
    xv = g.randomDouble(10,15);
    yv = g.randomDouble(10,15);
}

void Ball::draw(Graphics& g)
{
    g.ellipse(x,y,width,height,c,c);
}

void Ball::update(Graphics& g)
{
    x = x+xv;
    y = y+yv;


    if (y>g.height())
    {
        yv=(yv)*-1;
    }
    if (y<0)
    {
        yv=(yv)*-1;
    }
}


