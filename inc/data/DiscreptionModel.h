#pragma once

#include <span>

struct Size
{
	Size(unsigned int width = 0, unsigned int hight = 0) : width(width), hight(hight) {};
	unsigned int width;
	unsigned int hight;
};

struct DiscreptionModel
{
	DiscreptionModel(std::span<int> map, Size size) :
		map(map), size(size) {};
	std::span<int> map;
	Size size;
};

