#include "Position.h"
Position Position::zero = Position(0.0f, 0.0f);
Position Position::one = Position(1.f, 1.f);
Position Position::up = Position(0.0f, -1.f);
Position Position::down = Position(0.0f, 1.f);
Position Position::left = Position(-1.f, 0.0f);
Position Position::right = Position(1.f, 0.0f);

void Position::operator*=(const Position& b) {
    x *= b.x;
    y *= b.y;
}

void Position::operator*=(const float& b) {
    x *= b;
    y *= b;
}

Position operator*(const Position& a, const Position& b) {
    return { a.x * b.x, a.y * b.y };
}

Position operator*(const float& a, const Position& b) {
    return { a * b.x, a * b.y };
}

Position operator*(const Position& a, const float& b) {
    return { a.x * b, a.y * b };
}

void Position::operator+=(const Position& b) {
    x += b.x;
    y += b.y;
}

void Position::operator+=(const float& b) {
    x += b;
    y += b;
}

Position operator+(const Position& a, const Position& b) {
    return { a.x + b.x, a.y + b.y };
}

Position operator+(const float& a, const Position& b) {
    return { a + b.x, a + b.y };
}

Position operator+(const Position& a, const float& b) {
    return { a.x + b, a.y + b };
}
