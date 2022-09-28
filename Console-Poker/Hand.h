#pragma once

#include <array>
#include "Card.h"

using CardCount = std::array<int, 13>;

enum class HandRank : char {
	RoyalFlush = 1,
	StraightFlush = 2,
	FourOfAKind = 3,
	FullHouse = 4,
	Flush = 5,
	Straight = 6,
	ThreeOfAKind = 7,
	TwoPair = 8,
	Pair = 9,
	HighCard = 10
};

class Hand {
	std::array<Card, 5> hand;

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
	void exchange(int card_number, Card new_card);

	HandRank getHandRank();
};