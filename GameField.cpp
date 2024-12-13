#include "GameField.h"
#include <iostream>

GameField::GameField(int width, int height)
    : width(width), height(height), field(height, std::vector<CellStatus>(width, CellStatus::Unknown)), shipManager(10, { 3, 4, 2, 1 }) {}

void GameField::placeShip(Ship& ship, int x, int y) {
    shipManager.placeShip(ship, x, y);
    // Обновление статуса клеток на поле
}

bool GameField::attackCell(int x, int y) {
    if (field[y][x] == CellStatus::Ship) {
        for (Ship& ship : shipManager.getShips()) {
            for (int i = 0; i < ship.getLength(); ++i) {
                // Проверяем, был ли поражен сегмент корабля
                if (!ship.isSegmentDamaged(i)) {
                    ship.damageSegment(i);
                    return true;
                }
            }
        }
    }
    return false;
}

void GameField::printField() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            switch (field[y][x]) {
            case CellStatus::Unknown:
                std::cout << "U ";
                break;
            case CellStatus::Empty:
                std::cout << "E ";
                break;
            case CellStatus::Ship:
                std::cout << "S ";
                break;
            }
        }
        std::cout << std::endl;
    }
}
