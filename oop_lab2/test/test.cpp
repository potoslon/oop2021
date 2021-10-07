#include <iostream>
#include <gtest/gtest.h>
#include <kardioida.h>

TEST(constructors, default_constructor){
    kardioida k;
    float a = k.get_a(), x = k.get_x(), y = k.get_y();
    ASSERT_FLOAT_EQ(a, 0);
    ASSERT_FLOAT_EQ(x, 0);
    ASSERT_FLOAT_EQ(y, 0);
}

TEST(constructors, initial_constructor_1){
    kardioida k(3);
    float a = k.get_a();
    ASSERT_FLOAT_EQ(a, 3);
}

TEST(constructors, default_constructor_1_wrong_input){
    ASSERT_THROW(kardioida k(-4), std::runtime_error);
}

TEST(constructors, initial_constructor_2){
    kardioida k(3, 4, 5);
    float a = k.get_a(), x = k.get_x(), y = k.get_y();
    ASSERT_FLOAT_EQ(a, 3);
    ASSERT_FLOAT_EQ(x, 4);
    ASSERT_FLOAT_EQ(y, 5);
}

TEST(constructors, default_constructor_2_wrong_input){
    ASSERT_THROW(kardioida k(-4, 3, 4), std::runtime_error);
}

TEST(constructors, copy_constructor){
    kardioida c(3, 4, 5);
    kardioida k(c);
    float a = k.get_a(), x = k.get_x(), y = k.get_y();
    ASSERT_FLOAT_EQ(a, 3);
    ASSERT_FLOAT_EQ(x, 4);
    ASSERT_FLOAT_EQ(y, 5);
}

TEST(setters, set_a){
    kardioida k;
    k.set_a(5);
    float a = k.get_a();
    ASSERT_FLOAT_EQ(a, 5);
}

TEST(setters, set_a_wrong){
    kardioida k;
    ASSERT_THROW(k.set_a(-5), std::runtime_error);
}

TEST(setters, set_x){
    kardioida k;
    k.set_x(5);
    float x = k.get_x();
    ASSERT_FLOAT_EQ(x, 5);
}

TEST(setters, set_y){
    kardioida k;
    k.set_y(5);
    float y = k.get_y();
    ASSERT_FLOAT_EQ(y, 5);
}

TEST(funcs, radius){
    kardioida k(2);
    float rad = k.radius(5);
    ASSERT_NEAR(rad, 2.86535, 0.001);
}

TEST(funcs, farthest){
    kardioida k(3);
    float* coords = k.farthest();
    ASSERT_NEAR(coords[0], -12, 0.001);
    ASSERT_NEAR(coords[1], 0, 0.001);
    delete[] coords;
}

TEST(funcs, rad_vec){
    kardioida k(3);
    float* exp = new float[4];
    exp[0] = 0;
    exp[1] = 5.65686;
    exp[2] = 8;
    exp[3] = 5.65686;
    float* res = k.rad_vec();
    for(int i = 0; i < 4; i++){
        ASSERT_NEAR(exp[i], res[i], 0.001);
    }
    delete[] exp;
    delete[] res;
}

TEST(funcs, S){
    kardioida k(3);
    float exp = 169.646;
    ASSERT_NEAR(exp, k.square(), 0.001);
}

TEST(funcs, L){
    kardioida k(3);
    float exp = 48;
    ASSERT_NEAR(exp, k.lengths(), 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
