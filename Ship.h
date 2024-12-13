#ifndef SHIP_H
#define SHIP_H

#include <vector>

enum class SegmentStatus {
    Intact,
    Damaged,
    Destroyed
};

class Ship {
public:
    Ship(int length, bool isVertical);

    int getLength() const;
    bool isVertical() const;

    void damageSegment(int segmentIndex);
    bool isSegmentDamaged(int segmentIndex) const;

    void printStatus() const;

private:
    int length;
    bool vertical;
    std::vector<SegmentStatus> segments;
};

#endif // SHIP_H
