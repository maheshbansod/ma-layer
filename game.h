#ifndef GAME_H
#define GAME_H

#include "headers.h"
#include <vector>
#include <map>

class Drawable;

class Game {
public:
    int width, height; //window height and width
    std::string title;

    unsigned int VAO;

    Shader *shader;

    std::map<std::string,Sprite*> sprites;

    std::vector<Drawable*> drawables;

    Drawable *me;

    void loadSprites();
    void loadDrawables();
    void insertSprite(std::string, Sprite *s);

    Game(std::string, int width = 800, int height = 600);

    static void framebuffer_size_callback(GLFWwindow*, int, int);

    void processInput(GLFWwindow* w, float dt);

    void draw();
    void init();
};

#endif // GAME_H
