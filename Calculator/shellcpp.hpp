#pragma once
#include "corecpp.hpp"
#include "buffercpp.hpp"
#include <cmath>
using namespace std;

class shell_cpp
{
	bool dot_;
	int operator_;
	int length_;
	string buffer_;
	core_cpp core_;
	buffer_cpp memory_;
    string formula_;
public:
    const string operators[6] = {"+","-","x","/","(",")"};
    const string pi = to_string(acos(-1));
    const string zero = "0";
	shell_cpp();
	~shell_cpp();
	void backspace();
	void clear();
	void m_add(const string & num);
	void m_minus(const string & num);
	void m_clear();
	void push_num(const string & n);
	void push_operator(const int index);
	void push_dot();
	double get_num() const;
	double calculate();
	string m_record() const;
	string get_buffer() const;
    string get_formula() const;
};
