#pragma once

#include "Card.h"
#include <array>

using Hand = std::array<Card, 5>;

class Player {
	Hand hand;
public:
	void print_hand();
	void draw_hand(std::array<Card, 5> cards);
};