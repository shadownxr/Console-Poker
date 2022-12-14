#include "Hand.h"

#include <set>
#include <iostream>
#include <algorithm>

void Hand::print_hand() {
	std::cout << "Hand: ";

	for (auto h : hand) {
		std::cout << suit_smap.find(h.suit)->second << rank_smap.find(h.rank)->second << " ";
	}

	std::cout << std::endl;
}

void Hand::draw_hand(std::array<Card, 5> cards) {
	hand = std::move(cards);
}

void Hand::exchange(int card_number, Card new_card) {
	if (card_number > 0 && card_number < 6) {
		hand.at(card_number - 1) = new_card;
	}
}

bool Hand::isSameSuit() {
	std::set<Suit> suit_types;
	for (auto h : hand) {
		suit_types.insert(h.suit);
	}
	return suit_types.size() == 1;
}

CardCount Hand::countCards() {
	CardCount cardCount;
	cardCount.fill(0);

	for (auto h : hand) {
		++(cardCount.at(rank_imap.find(h.rank)->second));
	}

	return cardCount;
}

bool Hand::isRoyalFlush(CardCount cardCount) {
	const std::array<int, 13> royalFlushCount = { 0,0,0,0,0,0,0,0,1,1,1,1,1 };

	if (isSameSuit()) {

		if (cardCount == royalFlushCount) {
			return true;
		}
	}
	return false;
}

bool Hand::isStraightFlush(CardCount cardCount) {
	const std::array<int, 5> straitFlushCount = { 1,1,1,1,1 };

	if (isSameSuit()) {
		if (std::search(cardCount.begin(), cardCount.end(), straitFlushCount.begin(), straitFlushCount.end()) != cardCount.end()) {
			std::cout << "StraitFlush" << std::endl;
			return true;
		}
	}
	return false;
}

bool Hand::isFourOfAKind(CardCount cardCount) {
	const int fourOfAKind = 4;

	if (std::find(cardCount.begin(), cardCount.end(), fourOfAKind) != cardCount.end()) {
		std::cout << "FourOfKind" << std::endl;
		return true;
	}

	return false;
}

bool Hand::isFullHouse(CardCount cardCount) {
	if (std::find(cardCount.begin(), cardCount.end(), 3) != cardCount.end()) {
		if (std::find(cardCount.begin(), cardCount.end(), 2) != cardCount.end()) {
			std::cout << "FullHouse" << std::endl;
			return true;
		}
	}

	return false;
}

bool Hand::isFlush(CardCount cardCount) {
	if (isSameSuit()) {
		std::cout << "Flush" << std::endl;
		return true;
	}

	return false;
}

bool Hand::isStraight(CardCount cardCount) {
	const std::array<int, 5> straitCount = { 1,1,1,1,1 };

	if (std::search(cardCount.begin(), cardCount.end(), straitCount.begin(), straitCount.end()) != cardCount.end()) {
		std::cout << "Strait" << std::endl;
		return true;
	}

	return false;
}

bool Hand::isThreeOfAKind(CardCount cardCount) {
	if (std::find(cardCount.begin(), cardCount.end(), 3) != cardCount.end()) {
		std::cout << "ThreeOfAKind" << std::endl;
		return true;
	}

	return false;
}

bool Hand::isTwoPair(CardCount cardCount) {
	auto firstTwo = std::find(cardCount.begin(), cardCount.end(), 2);

	if (firstTwo != cardCount.end()) {
		if (std::find(++firstTwo, cardCount.end(), 2) != cardCount.end()) {
			std::cout << "TwoPair" << std::endl;
			return true;
		}
	}

	return false;
}

bool Hand::isPair(CardCount cardCount) {
	if (std::find(cardCount.begin(), cardCount.end(), 2) != cardCount.end()) {
		std::cout << "Pair" << std::endl;
		return true;
	}

	return false;
}

HandRank Hand::getHandRank() {
	CardCount cardCount = countCards();
	if (isRoyalFlush(cardCount)) {
		return HandRank::RoyalFlush;
	}
	else if (isStraightFlush(cardCount)) {
		return HandRank::StraightFlush;
	}
	else if (isFourOfAKind(cardCount)) {
		return HandRank::FourOfAKind;
	}
	else if (isFullHouse(cardCount)) {
		return HandRank::FullHouse;
	}
	else if (isFlush(cardCount)) {
		return HandRank::Flush;
	}
	else if (isStraight(cardCount)) {
		return HandRank::Straight;
	}
	else if (isThreeOfAKind(cardCount)) {
		return HandRank::ThreeOfAKind;
	}
	else if (isTwoPair(cardCount)) {
		return HandRank::TwoPair;
	}
	else if (isPair(cardCount)) {
		return HandRank::Pair;
	}
	else {
		return HandRank::HighCard;
	}

}
