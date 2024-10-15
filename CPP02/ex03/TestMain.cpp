// CPP02/ex03/test_main.cpp

#include "Point.h"
#include <gtest/gtest.h>

// Helper function to create points and test bsp
void testBsp(float ax, float ay, float bx, float by, float cx, float cy, float px, float py,
             bool expected) {
    Point a(ax, ay);
    Point b(bx, by);
    Point c(cx, cy);
    Point point(px, py);
    EXPECT_EQ(bsp(a, b, c, point), expected);
}

TEST(BspTests, PointInsideTriangle) {
    testBsp(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 10.0f, 2.0f, 2.0f, true);
}

TEST(BspTests, PointOutsideTriangle) {
    testBsp(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 10.0f, -2.0f, 2.0f, false);
}

TEST(BspTests, PointVeryCloseToEdge) {
    testBsp(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 10.0f, 5.0f, 0.0001f, true);
}


TEST(BspTests, PointOnEdgeOfTriangle) {
    testBsp(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 10.0f, 5.0f, 0.0f, false);
}

TEST(BspTests, PointAtVertexOfTriangle) {
    testBsp(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f, false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
