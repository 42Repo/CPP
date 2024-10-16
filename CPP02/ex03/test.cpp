// test_ex03.cpp
#include "Point.h"
#include <gtest/gtest.h>

// Helper function to print test case information (optional)
void printTestCase(const Point& a, const Point& b, const Point& c, const Point& point, bool expected) {
    std::cout << "Triangle vertices: A(" << a.getX() << ", " << a.getY() << "), "
              << "B(" << b.getX() << ", " << b.getY() << "), "
              << "C(" << c.getX() << ", " << c.getY() << ")\n"
              << "Point: (" << point.getX() << ", " << point.getY() << ")\n"
              << "Expected: " << (expected ? "Inside" : "Outside or On Edge") << "\n\n";
}

// Test point clearly inside the triangle
TEST(BSPTest, PointClearlyInside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point point(1.0f, 1.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test point near the centroid
TEST(BSPTest, PointNearCentroid) {
    Point a(0.0f, 0.0f);
    Point b(6.0f, 0.0f);
    Point c(0.0f, 6.0f);
    Point point(2.0f, 2.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test point very close to edge but inside
TEST(BSPTest, PointNearEdgeInside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    Point point(2.5f, 0.0001f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test point exactly on edge
TEST(BSPTest, PointOnEdge) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    Point point(2.5f, 0.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test point exactly at vertex
TEST(BSPTest, PointAtVertex) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    EXPECT_FALSE(bsp(a, b, c, a));
    EXPECT_FALSE(bsp(a, b, c, b));
    EXPECT_FALSE(bsp(a, b, c, c));
}

// Test point outside but near edge
TEST(BSPTest, PointNearEdgeOutside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    Point point(2.5f, -0.0001f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test point far outside
TEST(BSPTest, PointFarOutside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point point(10.0f, 10.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test degenerate triangle (zero area)
TEST(BSPTest, DegenerateTriangleZeroArea) {
    Point a(1.0f, 1.0f);
    Point b(1.0f, 1.0f);
    Point c(1.0f, 1.0f);
    Point point(1.0f, 1.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test degenerate triangle (line segment)
TEST(BSPTest, DegenerateTriangleLineSegment) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 5.0f);
    Point c(10.0f, 10.0f);
    Point point(5.0f, 5.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test colinear points
TEST(BSPTest, ColinearPoints) {
    Point a(0.0f, 0.0f);
    Point b(2.0f, 2.0f);
    Point c(4.0f, 4.0f);
    Point point(1.0f, 1.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test negative coordinates (inside)
TEST(BSPTest, NegativeCoordinatesInside) {
    Point a(-5.0f, -5.0f);
    Point b(-10.0f, -5.0f);
    Point c(-5.0f, -10.0f);
    Point point(-6.0f, -6.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test negative coordinates (outside)
TEST(BSPTest, NegativeCoordinatesOutside) {
    Point a(-5.0f, -5.0f);
    Point b(-10.0f, -5.0f);
    Point c(-5.0f, -10.0f);
    Point point(-11.0f, -11.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test floating-point precision (outside)
TEST(BSPTest, FloatingPointPrecisionOutside) {
    Point a(0.0f, 0.0f);
    Point b(0.0001f, 0.0f);
    Point c(0.0f, 0.0001f);
    Point point(0.00015f, 0.00015f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test equilateral triangle
TEST(BSPTest, EquilateralTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 4.330127f); // Height of equilateral triangle with side length 5
    Point point(2.5f, 1.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test isoceles triangle
TEST(BSPTest, IsocelesTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    Point point(2.5f, 2.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test scalene triangle
TEST(BSPTest, ScaleneTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(6.0f, 0.0f);
    Point c(2.0f, 5.0f);
    Point point(3.0f, 2.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test right-angled triangle
TEST(BSPTest, RightAngledTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 3.0f);
    Point point(1.0f, 1.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test point on hypotenuse of right-angled triangle
TEST(BSPTest, PointOnHypotenuse) {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 3.0f);
    Point point(2.0f, 1.5f); // Lies on the hypotenuse
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with random points (inside)
TEST(BSPTest, RandomPointsInside) {
    Point a(1.0f, 1.0f);
    Point b(4.0f, 2.0f);
    Point c(2.0f, 5.0f);
    Point point(2.5f, 2.5f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test with random points (outside)
TEST(BSPTest, RandomPointsOutside) {
    Point a(1.0f, 1.0f);
    Point b(4.0f, 2.0f);
    Point c(2.0f, 5.0f);
    Point point(3.5f, 4.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with swapped triangle vertices (inside)
TEST(BSPTest, SwappedVerticesInside) {
    Point a(2.0f, 5.0f);
    Point b(4.0f, 2.0f);
    Point c(1.0f, 1.0f);
    Point point(2.5f, 2.5f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test with swapped triangle vertices (outside)
TEST(BSPTest, SwappedVerticesOutside) {
    Point a(2.0f, 5.0f);
    Point b(4.0f, 2.0f);
    Point c(1.0f, 1.0f);
    Point point(3.5f, 4.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test when point coincides with one of the triangle sides extended
TEST(BSPTest, PointOnExtendedSide) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point point(6.0f, 0.0f); // Lies on the line extended from side AB
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test when triangle has negative area (due to vertex order)
TEST(BSPTest, NegativeAreaTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(0.0f, 5.0f);
    Point c(5.0f, 0.0f); // Reversing order
    Point point(1.0f, 1.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test when point is exactly at the centroid
TEST(BSPTest, PointAtCentroid) {
    Point a(0.0f, 0.0f);
    Point b(6.0f, 0.0f);
    Point c(0.0f, 6.0f);
    float centroidX = (a.getX().toFloat() + b.getX().toFloat() + c.getX().toFloat()) / 3.0f;
    float centroidY = (a.getY().toFloat() + b.getY().toFloat() + c.getY().toFloat()) / 3.0f;
    Point point(centroidX, centroidY);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test when point is very close to vertex but not exactly at vertex
TEST(BSPTest, PointNearVertex) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point point(0.0001f, 0.0001f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test when triangle is very small and point is outside
TEST(BSPTest, VerySmallTriangleOutside) {
    Point a(0.0f, 0.0f);
    Point b(0.001f, 0.0f);
    Point c(0.0f, 0.001f);
    Point point(0.002f, 0.002f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with non-integer coordinates
TEST(BSPTest, NonIntegerCoordinatesInside) {
    Point a(0.5f, 0.5f);
    Point b(2.5f, 0.5f);
    Point c(1.5f, 2.5f);
    Point point(1.5f, 1.5f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test with non-integer coordinates (outside)
TEST(BSPTest, NonIntegerCoordinatesOutside) {
    Point a(0.5f, 0.5f);
    Point b(2.5f, 0.5f);
    Point c(1.5f, 2.5f);
    Point point(2.0f, 2.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with points forming a flat triangle (area zero)
TEST(BSPTest, FlatTriangle) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(10.0f, 0.0f);
    Point point(5.0f, 0.0f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with extremely large coordinates
TEST(BSPTest, ExtremelyLargeCoordinatesInside) {
    float large = 1e9f;
    Point a(0.0f, 0.0f);
    Point b(large, 0.0f);
    Point c(0.0f, large);
    Point point(large / 2.0f, large / 2.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}


// Test with overlapping points
TEST(BSPTest, OverlappingPoints) {
    Point a(1.0f, 1.0f);
    Point b(1.0f, 1.0f);
    Point c(2.0f, 2.0f);
    Point point(1.5f, 1.5f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with triangle where one side is a point
TEST(BSPTest, OneSideIsPoint) {
    Point a(1.0f, 1.0f);
    Point b(1.0f, 1.0f);
    Point c(1.0f, 2.0f);
    Point point(1.0f, 1.5f);
    EXPECT_FALSE(bsp(a, b, c, point));
}

// Test with acute triangle
TEST(BSPTest, AcuteTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);
    Point point(2.0f, 1.0f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

// Test with obtuse triangle
TEST(BSPTest, ObtuseTriangleInside) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(1.0f, 2.0f);
    Point point(2.0f, 0.5f);
    EXPECT_TRUE(bsp(a, b, c, point));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
