#pragma warning (disable:4996)
#include "inf_int.h"
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

inf_int::inf_int()
{
	this->digits = new char[2];
	this->digits[0] = '0';
	this->digits[1] = '\0';
	this->length = 1;
	this->thesign = true;
}

inf_int::inf_int(int bongbong)
{
	vector<char> temp;
	this->thesign = (bongbong >= 0) ? true : false;
	if (bongbong < 0) bongbong = -bongbong;
	while (bongbong) {
		temp.push_back(char((bongbong%10)+'0'));
		bongbong /= 10;
	}
	this->length = temp.size();
	this->digits = new char[length + 1];
	copy(temp.begin(), temp.end(), this->digits);
	this->digits[this->length] = '\0';
}

inf_int::inf_int(const char* bongbong)
{
	vector<char> temp;
	if (bongbong[0] == '-') {
		this->length = strlen(bongbong) - 1;
		this->thesign = false;
		for (unsigned int i = 1; i < (this->length) + 1; i++) temp.push_back(bongbong[i]);
	}
	else {
		this->length = strlen(bongbong);
		this->thesign = true;
		for (unsigned int i = 0; i < this->length; i++) temp.push_back(bongbong[i]);
	}
	this->digits = new char[(this->length) + 1];
	copy(temp.rbegin(), temp.rend(), this->digits);
	this->digits[this->length] = '\0';
}

inf_int::inf_int(const inf_int& bongbong)
{
	this->digits = new char[bongbong.length + 1];
	strcpy(this->digits, bongbong.digits);
	this->length = bongbong.length;
	this->thesign = bongbong.thesign;
}

inf_int::~inf_int()
{
	delete[] this->digits;
}

inf_int& inf_int::operator=(const inf_int& bongbong)
{
	if (this->digits) delete this->digits;
	this->digits = new char[bongbong.length + 1];
	strcpy(this->digits, bongbong.digits);
	this->length = bongbong.length;
	this->thesign = bongbong.thesign;
	return *this;
}

bool operator==(const inf_int& bong1, const inf_int& bong2)
{
	if ((!strcmp(bong1.digits, bong2.digits)) && bong1.thesign == bong2.thesign) return true;
	return false;
}

bool operator!=(const inf_int& bong1, const inf_int& bong2)
{
	return !operator==(bong1, bong2);
}

bool operator>(const inf_int& bong1, const inf_int& bong2)
{
	if (bong1.thesign != bong2.thesign) return bong1.thesign;
	else {
		if (bong1.thesign) {
			if (bong1.length == bong2.length) {
				for (unsigned int i = bong1.length; i >= 0; i--) {
					if (bong1.digits[i] == bong2.digits[i]) continue;
					else return bong1.digits[i] > bong2.digits[i];
				}
				return false;
			}
			else return bong1.length > bong2.length;
		}
		else {
			if (bong1.length == bong2.length) {
				for (unsigned int i = bong1.length; i >= 0; i--) {
					if (bong1.digits[i] == bong2.digits[i]) continue;
					else return bong1.digits[i] < bong2.digits[i];
				}
				return false;
			}
			else return bong1.length < bong2.length;
		}
	}
}

bool operator<(const inf_int& bong1, const inf_int& bong2)
{
	if (operator>(bong1, bong2) || operator==(bong1, bong2)) return false;
	else return true;
}

inf_int operator+(const inf_int& bong1, const inf_int& bong2)
{
	if (bong1.thesign == bong2.thesign) {
		vector<char> sum;
		bool carry = false, l = (bong1.length > bong2.length);
		for (int i = 0; i < (l ? bong2.length : bong1.length); i++) {
			int bongbong = (int)(bong1.digits[i] - '0') + (int)(bong2.digits[i] - '0');
			if (carry) bongbong++;
			carry = (bongbong / 10 > 0) ? true : false;
			sum.push_back((char)((bongbong % 10) + '0'));
		}
		if (l) {
			for (int i = bong2.length; i < bong1.length; i++) {
				if (carry) {
					int bongbong = (int)(bong1.digits[i] - '0') + 1;
					if (bongbong / 10 > 0) carry = true;
					else carry = false;
					sum.push_back(((char)(bongbong % 10)) + '0');
				}
				else sum.push_back(bong1.digits[i]);
			}
		}
		else {
			for (int i = bong1.length; i < bong2.length; i++) {
				if (carry) {
					int bongbong = (int)(bong2.digits[i] - '0') + 1;
					if (bongbong / 10 > 0) carry = true;
					else carry = false;
					sum.push_back(((char)(bongbong % 10)) + '0');
				}
				else sum.push_back(bong2.digits[i]);
			}
		}
		if (carry) sum.push_back('1');
		inf_int temp;
		delete[] temp.digits;
		temp.length = sum.size();
		temp.thesign = bong1.thesign;
		temp.digits = new char[temp.length + 1];
		copy(sum.begin(), sum.end(), temp.digits);
		temp.digits[temp.length] = '\0';
		return temp;
	}
	else {
		inf_int ba, bb;
		if (!bong1.thesign) {
			ba = bong2;
			bb = bong1;
			bb.thesign = true;
			return bong2 - bb;
		}
		else {
			ba = bong1;
			bb = bong2;
			bb.thesign = true;
			return bong1 - bb;
		}
	}
}

inf_int operator-(const inf_int& bong1, const inf_int& bong2)
{
	if (bong1 == bong2) {
		inf_int temp;
		return temp;
	}
	else {
		if (bong1.thesign == bong2.thesign) {
			vector<char> sub, a(bong1.digits, bong1.digits + bong1.length), b(bong2.digits, bong2.digits + bong2.length);
			if (bong1.length > bong2.length || (bong1.length==bong2.length && (bong1.thesign?(bong1>bong2):(bong1<bong2)))) {
				for (int i = 0; i < b.size(); i++) {
					int bongbong = (int)(a[i] - '0') - (int)(b[i] - '0');
					if (bongbong < 0) {
						bongbong += 10;
						for (unsigned int j = i + 1; j < a.size(); j++) {
							if (a[j] == '0') a[j] = '9';
							else {
								a[j] = a[j] - (char)1;
								break;
							}
						}
					}
					sub.push_back(((char)bongbong) + '0');
				}
				int end = a.size() - 1;
				for (int j = a.size() - 1; j >= b.size(); j--) {
					if (a[j] == '0') continue;
					else {
						end = j;
						break;
					}
				}
				for (int i = b.size(); i <= end; i++) sub.push_back(a[i]);
			}
			else {
				for (int i = 0; i < a.size(); i++) {
					int bongbong = (int)(b[i] - '0') - (int)(a[i] - '0');
					if (bongbong < 0) {
						bongbong += 10;
						for (unsigned int j = i + 1; j < b.size(); j++) {
							if (b[j] == '0') b[j] = '9';
							else {
								b[j] = b[j] - (char)1;
								break;
							}
						}
					}
					sub.push_back(((char)bongbong) + '0');
				}
				int end = b.size() - 1;
				for (int j = b.size() - 1; j >= a.size(); j--) {
					if (b[j] == '0') continue;
					else {
						end = j;
						break;
					}
				}
				for (int i = a.size(); i <= end; i++) sub.push_back(b[i]);
			}
			inf_int temp;
			delete[] temp.digits;
			temp.length = sub.size();
			temp.thesign = bong1 > bong2;
			temp.digits = new char[temp.length + 1];
			copy(sub.begin(), sub.end(), temp.digits);
			temp.digits[temp.length] = '\0';
			return temp;
		}
		else {
			inf_int min(bong2);
			min.thesign = !min.thesign;
			return bong1 + min;
		}
	}
}

inf_int operator*(const inf_int& bong1, const inf_int& bong2)
{
	if ((!strcmp(bong1.digits, "0")) || (!strcmp(bong1.digits, "0"))) {
		inf_int temp;
		return temp;
	}
	else {
		inf_int mul;
		for (int i = 0; i < bong2.length; i++) {
			if (bong2.digits[i] == '0') continue;
			else {
				inf_int sum(bong1);
				for (int j = 1; j < (int)(bong2.digits[i]-'0'); j++) sum = sum + bong1;
				vector<char> temp(sum.digits, sum.digits + sum.length);
				for (int j = 0; j < i; j++) temp.insert(temp.begin(), '0');
				sum.length = temp.size();
				sum.thesign = true;
				delete[] sum.digits;
				sum.digits = new char[sum.length + 1];
				copy(temp.begin(), temp.end(), sum.digits);
				sum.digits[sum.length] = '\0';
				mul = mul + sum;
			}
		}
		mul.thesign = (bong1.thesign == bong2.thesign);
		return mul;
	}
	
}

ostream& operator<<(ostream& out, const inf_int& bongbong)
{
	if (!bongbong.thesign) out << '-';
	for (int i = bongbong.length - 1; i >= 0; i--) out << bongbong.digits[i];
	return out;
}

istream& operator>>(istream& in, inf_int& bongbong)
{
	string temp;
	delete[] bongbong.digits;
	cin >> temp;
	int i;
	if (temp[0] == '-') {
		for (i = 1; i < temp.length(); i++) {
			if (temp[i] != '0') break;
			if (i == temp.length() - 1 && temp[i] == '0') {
				inf_int zero;
				bongbong = zero;
				return in;
			}
		}
		bongbong.thesign = false;
		bongbong.length = temp.length() - i;
		bongbong.digits = new char[bongbong.length + 1];
		copy(temp.rbegin(), temp.rend() - i, bongbong.digits);
	}
	else {
		for (i = 0; i < temp.length(); i++) {
			if (temp[i] != '0') break;
			if (i == temp.length() - 1 && temp[i] == '0') {
				inf_int zero;
				bongbong = zero;
				return in;
			}
		}
		bongbong.thesign = true;
		bongbong.length = temp.length() - i;
		bongbong.digits = new char[bongbong.length + 1];
		copy(temp.rbegin(), temp.rend() - i, bongbong.digits);
	}
	bongbong.digits[bongbong.length] = '\0';
	return in;
}