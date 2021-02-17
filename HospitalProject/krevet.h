#pragma once

enum Status
{
	slobodno = 0,
	zauzeto,
	rezervisano
};

class krevet
{
private:
	int broj{};
	Status status;
public:
	void setBroj(int a);
	void setStatus(Status x);
	int getBroj();
	Status getStatus();
	void postaviKrevet(int a, Status x);
	krevet();
	~krevet();
};

