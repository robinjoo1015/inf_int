#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>

class inf_int
{
private:
	char* digits;
	unsigned int length;
	bool thesign;

public:
	inf_int();
	inf_int(int);
	inf_int(const char*);
	inf_int(const inf_int&);
	~inf_int();

	inf_int& operator=(const inf_int&);

	friend bool operator==(const inf_int&, const inf_int&);
	friend bool operator!=(const inf_int&, const inf_int&);
	friend bool operator>(const inf_int&, const inf_int&);
	friend bool operator<(const inf_int&, const inf_int&);

	friend inf_int operator+(const inf_int&, const inf_int&);
	friend inf_int operator-(const inf_int&, const inf_int&);
	friend inf_int operator*(const inf_int&, const inf_int&);
	// friend inf_int operator/(const inf_int& , const inf_int&); // not required 

	friend std::ostream& operator<<(std::ostream&, const inf_int&);
	friend std::istream& operator>>(std::istream& , inf_int&);    // not required -> but i made it lol

};

#endif