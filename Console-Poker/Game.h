#pragma once

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

enum class Action {
	Exchange,
	Keep
};

class Game {
	std::vector<Player> players;
	Deck deck;

	Game(std::vector<Player> players);

	void print_deck();
	void draw_hand(int player_id);
	void print_hand(int player_id);
	void shuffle();
	void compare_hands();
	void exchange_cards(int player_id, std::string choosen_cards);
	Action player_action();

public:
	static void main_loop();
};