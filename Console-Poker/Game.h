#pragma once

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>


class Game {
	std::vector<Player> players;
	Deck deck;

public:
	Game(std::vector<Player> players);

	void print_deck();
	void draw_hand(int player_id);
	void print_hand(int player_id);
	void shuffle();
	void check_hand(int player_id);
};