#include "graphics.h"

using namespace std;
using namespace mssm;

void graphicsMain(Graphics& g)
{
    Image img("comp.png");
    Sound pew("ShortLaser.wav");

    g.setBackground(GREY);

    int skullX = 0;
    int skullY = 0;

    while (g.draw())
    {
        g.clear();

        g.image(skullX, skullY, img);

        for (const Event& e : g.events()) {

            g.out << e << endl;

            switch (e.evtType) {
            case EvtType::KeyPress:
                g.play(pew);
                break;
            case EvtType::KeyRelease:
                break;
            case EvtType::MouseMove:
                skullX = e.x;
                skullY = e.y;
                break;
            case EvtType::MousePress:
                break;
            case EvtType::MouseRelease:
                break;
            default:
                break;
            }
        }
    }
}

int main()
{
    Graphics g("Game", 1000, 700, graphicsMain);
}
