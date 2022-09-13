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

	Card card, card1, card2, card3, card4;
	card = { Suit::Club, Rank::Seven };
	card1 = { Suit::Club, Rank::Eight };
	card2 = { Suit::Diamond, Rank::Jack };
	card3 = { Suit::Spade, Rank::Seven };
	card4 = { Suit::Heart, Rank::Ten };
	Hand testHand = { card, card1, card2, card3, card4 };

	players.at(player_id).draw_hand(testHand);
}

void Game::print_hand(int player_id) {
	players.at(player_id).print_hand();
}

void Game::shuffle() {
	deck.shuffle();
}

void Game::check_hand(int player_id) {
	players.at(player_id).check_hand();
}