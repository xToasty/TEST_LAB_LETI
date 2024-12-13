#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "ShipManager.h"
#include <vector>

enum class CellStatus {
    Unknown,
    Empty,
    Ship
};

class GameField {
public:
    GameField(int width, int height);
    void placeShip(Ship& ship, int x, int y);
    bool attackCell(int x, int y);

    void printField() const;

private:
    int width;
    int height;
    std::vector<std::vector<CellStatus>> field;
    ShipManager shipManager;
};

#endif // GAME_FIELD_H
