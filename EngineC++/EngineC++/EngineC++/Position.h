#pragma once
#ifndef CMD_ENGINE_POSITION_H
#define CMD_ENGINE_POSITION_H


struct Position {
	// Définition de positions prédéfinies qui sont utilisées comme des constantes
    static Position zero;
    static Position one;
    static Position up;
    static Position down;
    static Position left;
    static Position right;
    float x;
    float y;

	// Constructeur par défaut initialisant x et y à 0
    Position() : x(0), y(0) {}// Initialisation de x et y à 0

	// Constructeur prenant deux flottants en argument pour initialiser x et y
    Position(float nx, float ny) : x(nx), y(ny) {}

	// Constructeur de copie qui prend une autre Position en argument
    Position(const Position& np) : x(np.x), y(np.y) {}

	// Surcharges d'opérateurs pour *= et +=
    void operator*=(const Position& b);

    void operator*=(const float& b);

    void operator+=(const Position& b);

    void operator+=(const float& b);

};

// Surcharges d'opérateurs pour * et +
Position operator*(const Position& a, const Position& b);

Position operator*(const float& a, const Position& b);

Position operator*(const Position& a, const float& b);

Position operator+(const Position& a, const Position& b);

Position operator+(const float& a, const Position& b);

Position operator+(const Position& a, const float& b);

#endif