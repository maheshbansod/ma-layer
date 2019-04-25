#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

class Sprite {
public:
    unsigned int ID;
    int width, height, nrChannels;

    Sprite(std::string fname);
};

#endif // SPRITE_H_INCLUDED
