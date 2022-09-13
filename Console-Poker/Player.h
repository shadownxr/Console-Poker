#pragma once

#include "Card.h"
#include <array>

using Hand = std::array<Card, 5>;
using CardCount = std::array<int, 13>;

enum HandRank {
	RoyalFlush = 1,
	StraightFlush,
	FourOfAKind,
	FullHouse,
	Flush,
	Straight,
	ThreeOfAKind,
	TwoPair,
	Pair,
	HighCard
};

class Player {
	Hand hand;

	bool isSameSuit();
	CardCount countCards();
	bool isRoyalFlush(CardCount cardCount);
	bool isStraightFlush(CardCount cardCount);
	bool isFourOfAKind(CardCount cardCount);
	bool isFullHouse(CardCount cardCount);
	bool isFlush(CardCount cardCount);
	bool isStraight(CardCount cardCount);
	bool isThreeOfAKind(CardCount cardCount);
	bool isTwoPair(CardCount cardCount);
	bool isPair(CardCount cardCount);

public:
	void print_hand();
	void draw_hand(std::array<Card, 5> cards);
	void check_hand();
};