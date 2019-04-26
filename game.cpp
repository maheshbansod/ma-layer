#include "headers.h"
#include <vector>
#include <map>
#include <iterator>

void Game::insertSprite(std::string name, Sprite *s) {
    sprites.insert(std::pair<std::string,Sprite*>(name, s));
}

void Game::loadSprites() {
    insertSprite("meship", new Sprite("meship.png"));
}

void Game::loadDrawables() {
    me = new Drawable(sprites["meship"]);
    drawables.push_back(me);
}

void Game::init() {

    shader = new Shader("imgshader.vs","imgshader.fs");

    float vertices[] = {
		 1,  1, 0,  1,0,0,  1,1,
		 1, -1, 0,  0,1,0,  1,0,
		-1, -1, 0,  0,1,0,  0,0,
		-1,  1, 0,  0,0,1,  0,1
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned int VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2,2,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

    loadSprites();
    loadDrawables();

    me->x = 50;
    me->y = 500;
}

Game::Game(std::string title, int width, int height) {
    this->width = width;
    this->height = height;
    this->title = title;

}

void Game::draw() {
    shader->use();

    glBindVertexArray(VAO);

    for(std::vector<Drawable*>::iterator it = drawables.begin();it != drawables.end();it++) {
        if((*it)->todraw) {
            (*it)->draw(this);
        }
    }
}

void Game::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0,0,width, height);
}

void Game::processInput(GLFWwindow* window, float dt) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
