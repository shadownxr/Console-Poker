#pragma once

#include <vector>
#include "Card.h"

class Deck {
	std::vector<Card> deck;

public:
	Deck();
	void shuffle();
	void print_deck();
	const Card draw_a_card();
	void put_back(Card card_to_put_back);
};