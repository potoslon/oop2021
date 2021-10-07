#ifndef OOP_LAB2_KARDIOIDA_H
#define OOP_LAB2_KARDIOIDA_H


#include <stdexcept>
#include <iostream>
#include <math.h>

using namespace std;

const float pi = 3.141592654;

class kardioida {
private:
    float a;
    float x;
    float y;
public:
    kardioida();///empty

    kardioida(float num);///initial1

    kardioida(float num, float x, float y);///initial2

    kardioida(const kardioida& from);///copy

    float get_a() const { return a; }

    float get_x() const{ return x; }

    float get_y() const{ return y; }

    void set_a(float num);

    void set_x(float num){ x = num; }

    void set_y(float num){ y = num; }

    ~kardioida() = default;

    float radius(const float fi) const{ return 2 * a * (1 - cos(fi)); }

    float* farthest() const;

    float* rad_vec() const;

    float square(){ return 6 * pi * a * a; }

    float lengths(){ return 16 * a; }
};


#endif //OOP_LAB2_KARDIOIDA_H
