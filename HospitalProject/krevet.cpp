#include "krevet.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void krevet::setBroj(int a)
{
	this->broj = a;
}

void krevet::setStatus(Status x)
{
	this->status = x;
}

int krevet::getBroj()
{
	return this->broj;
}

Status krevet::getStatus()
{
	return this->status;
}

void krevet::postaviKrevet(int a, Status x)
{
	this->setBroj(a);
	this->setStatus(x);
}

krevet::krevet()
{
	this->status = slobodno;
}

krevet::~krevet()
{
}
