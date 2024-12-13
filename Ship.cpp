#include "Ship.h"
#include <iostream>

Ship::Ship(int length, bool isVertical)
    : length(length), vertical(isVertical), segments(length, SegmentStatus::Intact) {}

int Ship::getLength() const {
    return length;
}

bool Ship::isVertical() const {
    return vertical;
}

void Ship::damageSegment(int segmentIndex) {
    if (segmentIndex >= 0 && segmentIndex < length) {
        if (segments[segmentIndex] == SegmentStatus::Intact) {
            segments[segmentIndex] = SegmentStatus::Damaged;
        }
        else if (segments[segmentIndex] == SegmentStatus::Damaged) {
            segments[segmentIndex] = SegmentStatus::Destroyed;
        }
    }
}

bool Ship::isSegmentDamaged(int segmentIndex) const {
    return segmentIndex >= 0 && segmentIndex < length && segments[segmentIndex] != SegmentStatus::Intact;
}

void Ship::printStatus() const {
    for (int i = 0; i < length; ++i) {
        std::cout << "Segment " << i + 1 << ": ";
        switch (segments[i]) {
        case SegmentStatus::Intact:
            std::cout << "Intact\n";
            break;
        case SegmentStatus::Damaged:
            std::cout << "Damaged\n";
            break;
        case SegmentStatus::Destroyed:
            std::cout << "Destroyed\n";
            break;
        }
    }
}
