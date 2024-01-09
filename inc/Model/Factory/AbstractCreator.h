#pragma once
template <class Base>
class AbstractCreator
{
public:
	AbstractCreator() {}
	virtual ~AbstractCreator() {}
	virtual Base* create() const = 0;
};

template <class C, class Base>
class Creator : public AbstractCreator<Base>
{
public:
	Creator() { }
	virtual ~Creator() {}
	Base* create() const { return new C(); }
};