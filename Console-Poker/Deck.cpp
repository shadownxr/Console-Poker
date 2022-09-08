#include "Deck.h"
#include <random>
#include <algorithm>

#include <iostream>

const int Shuffle_Number = 1000;

Deck::Deck() {
	for (auto suit : suit_map) {
		for (auto rank : rank_map) {
			deck.push_back({ suit.first, rank.first });
		}
	}
}

void Deck::shuffle() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, deck.size() - 1);

	for (int i = 0; i < Shuffle_Number; ++i) {
		std::swap(deck.at(dist(rng)), deck.at(dist(rng)));
	}
}

void Deck::print_deck() {
	for (auto d : deck) {
		std::cout << suit_map.find(d.suit)->second << rank_map.find(d.rank)->second << std::endl;
	}
}

const Card Deck::draw_a_card() {
	const Card card = deck.back();
	deck.pop_back();
	return card;
}

void Deck::put_back(const Card card_to_put_back) {
	deck.push_back(card_to_put_back);
}
