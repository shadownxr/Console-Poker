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

const std::map <Suit, std::string> suit_smap = {
	{ Suit::Diamond, "D" },
	{ Suit::Club, "C" },
	{ Suit::Heart, "H" },
	{ Suit::Spade, "S" }
};

const std::map <Rank, std::string> rank_smap = {
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

const std::map <Suit, int> suit_imap = {
	{ Suit::Diamond, 1 },
	{ Suit::Club, 2 },
	{ Suit::Heart, 3 },
	{ Suit::Spade, 4 }
};

const std::map <Rank, int> rank_imap = {
	{ Rank::Ace, 12 },
	{ Rank::King, 11 },
	{ Rank::Queen, 10 },
	{ Rank::Jack, 9 },
	{ Rank::Ten, 8 },
	{ Rank::Nine, 7 },
	{ Rank::Eight, 6 },
	{ Rank::Seven, 5 },
	{ Rank::Six, 4 },
	{ Rank::Five, 3 },
	{ Rank::Four, 2 },
	{ Rank::Three, 1 },
	{ Rank::Two, 0 }
};

struct Card {
	Suit suit;
	Rank rank;
};