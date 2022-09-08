#include "Game.h"

Game::Game(std::vector<Player> players) : players(players) {

}

void Game::print_deck() {
	deck.print_deck();
}

void Game::draw_hand(int player_id) {
	Hand hand;

	for (int i = 0; i < 5; ++i) {
		hand.at(i) = deck.draw_a_card();
	}

	players.at(player_id).draw_hand(hand);
}

void Game::print_hand(int player_id) {
	players.at(player_id).print_hand();
}