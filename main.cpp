//
// Created by studio25 on 10.06.2021.
//
#include <iostream>
#include <vector>

#define DISPLAY(x) for(auto i:x) std::cout<<i;

using size_t = long long unsigned int;

struct Coord {
    Coord(size_t x, size_t y) : x(x), y(y) {};
    size_t x;
    size_t y;

    friend std::ostream &operator<<(std::ostream &out, const Coord &me) {
        out << me.x << "\t" << me.y << "\n";
        return out;
    }
};

struct linear_function {
    linear_function() {
        a = 0;
        b = 0;
    }

    linear_function(double a, double b) : a(a), b(b) {}

    linear_function(Coord A, Coord B) {
        a = (B.y - A.y) / (B.x - A.x);
        b = A.y - a * A.x;
    }

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

    friend std::ostream &operator<<(std::ostream &out, const linear_function &me) {
        out << "y = " << me.a << "x + " << me.b << "\n";
        return out;
    }

    double a;
    double b;

};

enum side {
    upper = true,
    lower = false
};

struct triangle {

    triangle(Coord A, Coord B, Coord C) : f(A, B), g(B, C), h(C, A) {

        if (f > C) for_f = upper;
        else for_f = lower;
        if (g > A) for_g = upper;
        else for_g = lower;
        if (h > B) for_h = upper;
        else for_h = lower;
    }

    bool check_insidness(Coord P) {
        if (for_f == upper) {
            if (f < P)return false;
        } else if (f > P)return false;


        if (for_g == upper) {
            if (g < P)return false;
        } else if (g > P)return false;

        if (for_h == upper) {
            if (h < P)return false;
        } else if (h > P)return false;

        return true;
    }

    friend std::ostream &operator<<(std::ostream &out, const triangle &me) {
        out << me.f;

        if (me.for_f) out << "/\\";
        else out << "\\/";
        out << "\n";

        out << me.g;

        if (me.for_g) out << "/\\";
        else out << "\\/";
        out << "\n";

        out << me.h;

        if (me.for_h) out << "/\\";
        else out << "\\/";
        out << "\n";
        return out;

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
    DISPLAY(big_points);
    std::cout<<"\n";
    DISPLAY(small_points);


    return 1;
}