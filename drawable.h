#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include "game.h"

class Drawable {
public:
    bool todraw=true;
    int x, y, width, height;
    float angle; /**degrees*/
    Sprite *sprite;

    Drawable(Sprite *s, int x = 0, int y = 0);
    void draw(Game *game);

    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setSprite(Sprite *s);
};

#endif // DRAWABLE_H_INCLUDED
