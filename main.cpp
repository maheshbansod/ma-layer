#include "headers.h"

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Game game("Space invaders");

    GLFWwindow * window = glfwCreateWindow(game.width, game.height,game.title.c_str(), NULL, NULL);
    if(window == NULL) {
        std::cout << ("COuldn't create window\n") << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, game.framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glClearColor(0,0,0,1);

    float old_t = 0,dt;
    while(!glfwWindowShouldClose(window)) {
        dt = old_t - glfwGetTime();
        game.processInput(window, dt);

        glClear(GL_COLOR_BUFFER_BIT);

        game.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
