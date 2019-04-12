#include "headers.h"

Game::Game(std::string title, int width, int height) {
    this->width = width;
    this->height = height;
    this->title = title;
}

void Game::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0,0,width, height);
}

void Game::processInput(GLFWwindow* window, float dt) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
