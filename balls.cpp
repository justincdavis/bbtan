#include "balls.h"
#include "graphics.h"
using namespace mssm;

Ball::Ball(Graphics& g)
{
    x = (g.width())/2;
    y = (g.height()) - 70;
    height = 50;
    width = 50;
    c= WHITE;
    xv = 0;
    yv = -10;
}

void Ball::draw(Graphics& g)
{
    g.ellipse(x,y,width,height,c,c);
}

void Ball::update(Graphics& g, int rx, int ry)
{
    x = x+xv;
    y = y+yv;


    if (y>g.height()-50)
    {
        yv=(yv)*-0;
        xv=(xv)*-0;
        if(x!=rx)
        {
            if (x>rx)
            {
                x=x-50;
            }
            if (x<rx)
            {
                x=x+50;
            }
        }
    }

    if (y<0)
    {
        yv=(yv)*-1;
    }

    if (x<0)
    {
        xv=(xv)*-1;
    }

    if (x>g.width())
    {
        xv=(xv)*-1;
    }
}


