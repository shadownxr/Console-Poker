#include "Player.h"
#include <iostream>
#include <set>
#include <algorithm>

void Player::print_hand() {
	for (auto h : hand) {
		std::cout << "Hand: " << suit_smap.find(h.suit)->second << rank_smap.find(h.rank)->second << std::endl;
	}
}

void Player::draw_hand(std::array<Card, 5> cards) {
	hand = std::move(cards);
}

bool Player::isSameSuit() {
	std::set<Suit> suit_types;
	for (auto h : hand) {
		suit_types.insert(h.suit);
	}
	return suit_types.size() == 1;
}

CardCount Player::countCards() {
	CardCount cardCount;
	cardCount.fill(0);

	for (auto h : hand) {
		++(cardCount.at(rank_imap.find(h.rank)->second));
	}

	return cardCount;
}

bool Player::isRoyalFlush(CardCount cardCount) {
	const std::array<int, 13> royalFlushCount = {0,0,0,0,0,0,0,0,1,1,1,1,1};

	if (isSameSuit()) {

		if (cardCount == royalFlushCount) {
			return true;
		}
	}
	return false;
}

bool Player::isStraightFlush(CardCount cardCount) {
	const std::array<int, 5> straitFlushCount = {1,1,1,1,1};

	if (isSameSuit()) {
		if (std::search(cardCount.begin(), cardCount.end(), straitFlushCount.begin(), straitFlushCount.end()) != cardCount.end()) {
			std::cout << "StraitFlush" << std::endl;
			return true;
		}
	}
	return false;
}

bool Player::isFourOfAKind(CardCount cardCount) {
	const int fourOfAKind = 4;

	if (std::find(cardCount.begin(), cardCount.end(), fourOfAKind) != cardCount.end()) {
		std::cout << "FourOfKind" << std::endl;
		return true;
	}

	return false;
}

bool Player::isFullHouse(CardCount cardCount) {
	if (std::find(cardCount.begin(), cardCount.end(), 3) != cardCount.end()) {
		if (std::find(cardCount.begin(), cardCount.end(), 2) != cardCount.end()) {
			std::cout << "FullHouse" << std::endl;
			return true;
		}
	}

	return false;
}

bool Player::isFlush(CardCount cardCount) {
	if (isSameSuit()) {
		std::cout << "Flush" << std::endl;
		return true;
	}

	return false;
}

bool Player::isStraight(CardCount cardCount) {
	const std::array<int, 5> straitCount = { 1,1,1,1,1 };

	if (std::search(cardCount.begin(), cardCount.end(), straitCount.begin(), straitCount.end()) != cardCount.end()) {
		std::cout << "Strait" << std::endl;
		return true;
	}

	return false;
}

bool Player::isThreeOfAKind(CardCount cardCount) {
	if (std::find(cardCount.begin(), cardCount.end(), 3) != cardCount.end()) {
		std::cout << "ThreeOfAKind" << std::endl;
		return true;
	}

	return false;
}

bool Player::isTwoPair(CardCount cardCount) {
	auto firstTwo = std::find(cardCount.begin(), cardCount.end(), 2);

	if (firstTwo != cardCount.end()) {
		if (std::find(++firstTwo, cardCount.end(), 2) != cardCount.end()) {
			std::cout << "TwoPair" << std::endl;
			return true;
		}
	}

	return false;
}

bool Player::isPair(CardCount cardCount) {
	if (std::find(cardCount.begin(), cardCount.end(), 2) != cardCount.end()) {
		std::cout << "Pair" << std::endl;
		return true;
	}

	return false;
}

void Player::check_hand() {
	CardCount cardCount = countCards();
	isRoyalFlush(cardCount);
	isStraightFlush(cardCount);
	isFourOfAKind(cardCount);
	isFullHouse(cardCount);
	isFlush(cardCount);
	isStraight(cardCount);
	isThreeOfAKind(cardCount);
	isTwoPair(cardCount);
	isPair(cardCount);
}