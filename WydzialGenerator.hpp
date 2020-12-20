//
// Created by jgalecki on 13.11.2020.
//

#ifndef P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
#define P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomIntGenerator {
	static std::mt19937 prng;
};

std::mt19937 RandomIntGenerator::prng = std::mt19937{ std::random_device{}() };

constexpr std::array first_names{
	"MEiL",
	"MiNI",
	"EiTI",
	"SiMR",
};

constexpr std::array last_names{
	" ",

};

std::string get_wydzial() {
	std::uniform_int_distribution<std::size_t> fnd{ 0, first_names.size() - 1 };
	std::uniform_int_distribution<std::size_t> lnd{ 0, last_names.size() - 1 };
	std::stringstream name;
	name << first_names[fnd(RandomIntGenerator::prng)] << ' ' <<
		last_names[lnd(RandomIntGenerator::prng)];
	return name.str();
}

#endif //P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP