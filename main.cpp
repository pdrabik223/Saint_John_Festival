//
// Created by studio25 on 10.06.2021.
//
#include <iostream>
#include <vector>

using size_t = long long unsigned int;

struct Coord {
    Coord(size_t x, size_t y) : x(x), y(y) {};
    size_t x;
    size_t y;

};

struct linear_function {
    linear_function(){
        a = 0;
        b = 0;
    }
    linear_function(double a, double b) : a(a), b(b) {}

    double operator()(size_t x) {
        return a * x + b;
    }

    bool operator==(Coord position) const {
        return a * position.x + b == position.y;
    }

    bool operator!=(Coord position) const {
        return a * position.x + b != position.y;
    }

    bool operator<(Coord position) const {
        return position.y < a * position.x + b;
    }

    bool operator>(Coord position) const {
        return position.y > a * position.x + b;
    }

    bool operator<=(Coord position) const {
        return position.y <= a * position.x + b;
    }

    bool operator>=(Coord position) const {
        return position.y >= a * position.x + b;
    }

    double a;
    double b;

};

enum side{
    upper = true,
    lower = false
};
struct triangle{

    triangle(Coord A, Coord B, Coord C) {


    }

    linear_function f;
    side for_f;
    linear_function g;
    side for_g;
    linear_function h;
    side for_h;
};

int main() {

    /// so my plan is
    /// calculate functions for every line between points in triangle

    /// let's jus say tht A-B will be called f(x)
    ///                   B-C g(x)
    ///                   C-A h(x)

    /// and for every function we calculate " side "
    /// and for every point in array we check if he is on the correct side of the function
    unsigned L;
    std::cin >> L;
    std::vector<Coord> big_points;
    big_points.reserve(L);
    size_t x, y;
    for (int i = 0; i < L; ++i) {
        std::cin >> x >> y;
        big_points.emplace_back(x, y);
    }
    unsigned S;
    std::cin >> S;
    std::vector<Coord> small_points;
    small_points.reserve(S);

    for (int i = 0; i < S; ++i) {
        std::cin >> x >> y;
        small_points.emplace_back(x, y);
    }



    return 1;
}