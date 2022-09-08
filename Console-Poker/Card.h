#pragma once
#include <string>
#include <map>

enum class Suit {
	Diamond,
	Club,
	Heart,
	Spade
};

enum class Rank {
	Ace,
	King,
	Queen,
	Jack,
	Ten,
	Nine,
	Eight,
	Seven,
	Six,
	Five,
	Four,
	Three,
	Two
};

const std::map <Suit, std::string> suit_map = {
	{ Suit::Diamond, "D" },
	{ Suit::Club, "C" },
	{ Suit::Heart, "H" },
	{ Suit::Spade, "S" }
};

const std::map <Rank, std::string> rank_map = {
	{ Rank::Ace, "A" },
	{ Rank::King, "K" },
	{ Rank::Queen, "Q" },
	{ Rank::Jack, "J" },
	{ Rank::Ten, "10" },
	{ Rank::Nine, "9" },
	{ Rank::Eight, "8" },
	{ Rank::Seven, "7" },
	{ Rank::Six, "6" },
	{ Rank::Five, "5" },
	{ Rank::Four, "4" },
	{ Rank::Three, "3" },
	{ Rank::Two, "2" }
};

struct Card {
	Suit suit;
	Rank rank;
};