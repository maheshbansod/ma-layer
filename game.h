#ifndef GAME_H
#define GAME_H

#include "headers.h"

class Game {
public:
    int width, height;
    std::string title;

    Game(std::string, int width = 800, int height = 600);

    static void framebuffer_size_callback(GLFWwindow*, int, int);

    void processInput(GLFWwindow* w, float dt);

    void draw();
    //void init();
};

#endif // GAME_H
