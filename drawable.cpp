#include "headers.h"

#include <glm/gtx/string_cast.hpp>

Drawable::Drawable(Sprite *s, int x, int y) {
    todraw = true;
    sprite = s;
    this->x = x;
    this->y = y;
    width = s->width;
    height = s->height;
}

void Drawable::draw(Game *game) {
    /**TODO: create MVP and assign as uniforms*/
    /** Set uniform texture */
    glm::mat4 model = glm::mat4(1.0);
    glm::mat4 view = glm::mat4(1.0);
    glm::mat4 projection = glm::mat4(1.0);

    view = glm::translate(view, glm::vec3(-1,-1,0));
    view = glm::scale(view, glm::vec3(1/(float)game->width, 1/(float)game->height,1));

    //model = glm::translate(model, glm::vec3(x/(float)game->width,y/(float)game->height, 0));
    model = glm::translate(model, glm::vec3(x,y,0));
    model = glm::scale(model, glm::vec3(width, height, 1));
    //model = glm::scale(model, glm::vec3(width/(float)game->width,height/(float)game->height,1));


    //std::cout << glm::to_string(model) << std::endl;


    game->shader->setMat4("model",model);
    game->shader->setMat4("view", view);
    game->shader->setMat4("projection", projection);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite->ID);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Drawable::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Drawable::setSprite(Sprite *s) {
    sprite = s;
}

void Drawable::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}
