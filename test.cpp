#include <gtest/gtest.h>
#include "Trapezoid.hpp"
#include "Rombus.hpp"
#include "Pentagon.hpp"
#include "array.hpp"

TEST(Trap,c_default) {
    Trapezoid<double> tr;
    EXPECT_DOUBLE_EQ(tr.area(), 0.0);
    EXPECT_EQ(tr.center(), std::pair(0.0,0.0));
}

TEST(Romb,c_default) {
    Rombus<double> rb;
    EXPECT_DOUBLE_EQ(rb.area(), 0.0);
    EXPECT_EQ(rb.center(), std::pair(0.0,0.0));
}

TEST(Penta,c_default) {
    Pentagon<double> pt;
    EXPECT_DOUBLE_EQ(pt.area(), 0.0);
    EXPECT_EQ(pt.center(), std::pair(0.0,0.0));
}

TEST(Array,Size_c) {
    array<std::shared_ptr<Figure<double>>> arr(3);
    EXPECT_EQ(arr.get_size(), 3);
}

TEST(Trap,OK) {
    std::vector<std::pair<double,double>> cd = {{0.0,0.0},{1.0,2.0},{3.0,2.0}, {4.0,0.0}};
    Trapezoid<double> tr(cd);
    EXPECT_EQ(tr.area(), 6);
    EXPECT_EQ(tr.center(), std::pair(2.0, 1.0));
}

TEST(Romb,OK) {
    std::vector<std::pair<double,double>> cd = {{1.0,2.0},{2.0,4.0},{3.0,2.0}, {2.0,0.0}};

    Rombus<double> rb(cd);
    EXPECT_EQ(rb.area(), 4);
    EXPECT_EQ(rb.center(), std::pair(2.0, 2.0));
}

TEST(Penta,OK) {
    std::vector<std::pair<double,double>> cd = {{0.0,0.0},{1.0,2.0},{3.0,2.0}, {4.0,0.0},{2.0,-2.0}};

    Pentagon<double> pt(cd);
    EXPECT_EQ(pt.area(), 8.6023870029448357);
    EXPECT_EQ(pt.center(), std::pair(2.0, 0.4));
}

TEST(Trap, assi) {
    std::vector<std::pair<double,double>> cd = {{0.0,0.0},{1.0,2.0},{3.0,2.0}, {4.0,0.0}};
    Trapezoid<double> tr1(cd);
    Trapezoid<double> tr2;
    tr2 = tr1;
    EXPECT_EQ(tr1.area(), tr2.area());
    EXPECT_EQ(tr1.center(), tr2.center());
}

TEST(Romb, assi) {
    std::vector<std::pair<double,double>> cd = {{1.0,2.0},{2.0,4.0},{3.0,0.0}, {2.0,0.0}};
    Rombus<double> r1(cd);
    Rombus<double> r2;
    r2 = r1;
    EXPECT_EQ(r1.area(), r2.area());
    EXPECT_EQ(r1.center(), r2.center());
}

TEST(Penta, assi) {
    std::vector<std::pair<double,double>> cd = {{0.0,0.0},{1.0,2.0},{3.0,2.0}, {4.0,0.0},{2.0,-2.0}};
    Pentagon<double> t1(cd);
    Pentagon<double> t2;
    t2 = t1;
    EXPECT_EQ(t1.area(), t2.area());
    EXPECT_EQ(t1.center(), t2.center());
}