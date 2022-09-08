#include "Player.h"
#include <iostream>

void Player::print_hand() {
	for (auto h : hand) {
		std::cout << "Hand: " << suit_map.find(h.suit)->second << rank_map.find(h.rank)->second << std::endl;
	}
}

void Player::draw_hand(std::array<Card, 5> cards) {
	hand = std::move(cards);
}