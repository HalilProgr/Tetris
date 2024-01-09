#pragma once

struct ConfigModel {
	ConfigModel(const int* map, int width, int hight) : ptr_map(map), width(width), hight(hight) {};
	const int* ptr_map;
	int width;
	int hight;
};

