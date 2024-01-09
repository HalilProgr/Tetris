#pragma once

#include "ObjectFactory.h"
#include "AbstractShape.h"

enum class IdShape {
	Iblock,
	Tblock,
	Oblock,
	Jblock
};

class ShapeFactory:public ObjectFactory<AbstractShape, IdShape>
{
public:
	AbstractShape* create(IdShape id) {
		return _factory[id]->create();
	}

	int size() const {
		return _factory.size();
	};
};

