#include "graphics.h"
#include "iostream"
#include "world.h"

using namespace std;
using namespace mssm;

void graphicsMain(Graphics& g)
{
    Image img("comp.png");
    Sound pew("ShortLaser.wav");

    g.setBackground(GREY);

    int keyPress = 0;
    int skullX = 0;
    int skullY = 0;
    int skullZ = 0;

    World world(g);

    while (g.draw())
    {
        g.clear();        
        g.image(skullX, skullY, img);
        world.draw(g, keyPress);
        for (const Event& e : g.events()) {

            g.out << e << endl;

            switch (e.evtType) {
            case EvtType::KeyPress:
                g.play(pew);
                cout << "YOur mOm";

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
    Graphics g("Game", 500, 800, graphicsMain);

}
