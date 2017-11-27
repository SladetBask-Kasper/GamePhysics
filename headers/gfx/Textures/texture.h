#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <iostream>
#include <string>
#include <vector>

#define NO_TEXTURE "!ROOT!/headers/gfx/Textures/std/untextured.jpg"

typedef class texture {
private:
    std::string text;
public:
    texture(std::string texture_ = NO_TEXTURE) { text = texture_; }
    texture operator=(std::string texture_) { text = texture_; }
    texture get() { return text; }
    void update(std::string texture_) {
        std::string str = texture_;
        text = str; 
    }
    virtual ~texture() {}
} texture;

#endif // TEXTURE_H
