#include "kardioida.h"

kardioida::kardioida() {///initial2
    a = 0;
    x = 0;
    y = 0;
}

kardioida::kardioida(float num){///initial1
    if(num < 0){
        throw std::runtime_error("radius cant be < 0");
    }
    a = num;
    x = 0;
    y = 0;
}

kardioida::kardioida(float num, float x, float y){///initial2
    if(num < 0){
        throw std::runtime_error("radius cant be < 0");
    }
    a = num;
    this->x = x;
    this->y = y;
}

kardioida::kardioida(const kardioida& from){///copy
    a = from.a;
    this->x = from.x;
    this->y = from.y;
}

void kardioida::set_a(float num){
    if(num < 0){
        throw std::runtime_error("radius cant be < 0");
    }
    a = num;
}

float* kardioida::farthest() const{
    float* res = new float[2];
    res[1] = y;
    res[0] = x - 4 * a;
    return res;
}

float* kardioida::rad_vec() const{
    float* res = new float[4];
    res[0] = 8.0 / 3.0 * a * sin(0);
    res[1] = 8.0 / 3.0 * a * sin(pi / 4);
    res[2] = 8.0 / 3.0 * a * sin(pi / 2);
    res[3] = 8.0 / 3.0 * a * sin(pi * 3 / 4);
    return res;
}