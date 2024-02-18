#pragma once

class IView
{
public:
	virtual ~IView() {};
	void virtual Update() = 0;
};

