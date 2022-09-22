#include "Game.h"
#include <algorithm>
#include <iostream>

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

	/*Card card, card1, card2, card3, card4;
	Hand testHand;

	if (player_id == 0) {

		card = { Suit::Club, Rank::Seven };
		card1 = { Suit::Club, Rank::Eight };
		card2 = { Suit::Diamond, Rank::Jack };
		card3 = { Suit::Spade, Rank::Seven };
		card4 = { Suit::Heart, Rank::Ten };
		testHand = { card, card1, card2, card3, card4 };

		players.at(player_id).drawHand(testHand);
	}

	if (player_id == 1) {

		card = { Suit::Club, Rank::Seven };
		card1 = { Suit::Diamond, Rank::Seven };
		card2 = { Suit::Diamond, Rank::Jack };
		card3 = { Suit::Spade, Rank::Seven };
		card4 = { Suit::Heart, Rank::Ten };
		testHand = { card, card1, card2, card3, card4 };

		players.at(player_id).drawHand(testHand);
	}*/


}

void Game::print_hand(int player_id) {
	players.at(player_id).print_hand();
}

void Game::shuffle() {
	deck.shuffle();
}

void Game::compare_hands() {
	HandRank human_handrank;
	HandRank ai_handrank;
	std::vector<HandRank> ai_players_handrank;

	human_handrank = players.at(0).getHandRank();

	for (auto i = players.begin() + 1; i != players.end(); ++i) {
		ai_players_handrank.push_back(i->getHandRank());
	}

	ai_handrank = *(std::min_element(ai_players_handrank.begin(),ai_players_handrank.end()));

	if (human_handrank < ai_handrank) {
		std::cout << "You won" << std::endl;
	}
	if (human_handrank > ai_handrank) {
		std::cout << "Ai won" << std::endl;
	}
	if (human_handrank == ai_handrank) {
		std::cout << "Draw" << std::endl;
	}
}

void Game::main_loop() {
	Player human_player, ai1, ai2, ai3;
	std::vector<Player> players;
	players.push_back(human_player);
	players.push_back(ai1);
	players.push_back(ai2);
	players.push_back(ai3);

	Game game(players);
	game.shuffle();

	for (int i = 0; i < players.size(); ++i) {
		game.draw_hand(i);
	}

	std::cout << "Your ";

	game.print_hand(0);

	std::cout << "1 - Exchange, 2 - Keep" << std::endl;

	game.player_action();

	std::cout << std::endl;

	game.print_hand(1);

	std::cout << std::endl;

	game.print_hand(2);

	std::cout << std::endl;

	game.print_hand(3);

	std::cout << std::endl;

	game.compare_hands();
}

void Game::exchange_cards(int player_id, std::string choosen_cards) {
	std::string cut_choice = choosen_cards.substr(0, 5);

	for (auto i : cut_choice) {
		int num = i - '0';

		if (0 < num && num < 6) {
			players.at(0).exchange(num, deck.draw_a_card());
		}
	}
}

Action Game::player_action() {
	//char action = getchar();
	std::string action;
	std::cin >> action;

	if (action == "1") {
		std::string choice;

		std::cout << "Which cards: " << std::endl;

		std::cin >> choice;

		exchange_cards(0, choice);

		std::cout << "New ";

		print_hand(0);

		std::cout << std::endl;

		return Action::Exchange;
	}
	else if (action == "2") {
		return Action::Keep;
	}
	else {
		return Action::Keep;
	}

}