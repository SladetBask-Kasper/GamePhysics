#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <iostream>
#include <string>
#include <vector>

// Empty texture.
#define NO_TEXTURE "!ROOT!/headers/gfx/Textures/std/untextured.jpg"

// Type def, texture is now a valid variable type
typedef class texture {
private:
    std::string text;
public:
    texture(std::string texture_ = NO_TEXTURE) { text = texture_; } // sets texture
    texture operator=(std::string texture_) { text = texture_; } // ----- "" -----
    texture get() { return text; } // Gets texture path
    void update(std::string texture_ = NO_TEXTURE) { // update the texture
        std::string str = texture_;
        text = str;// Why Does it not just use texture_ and just not bother creating a new variable?
    }
    virtual ~texture() {}
} texture;

#endif // TEXTURE_H
