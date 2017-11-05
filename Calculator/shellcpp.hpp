#pragma once
#include "corecpp.hpp"
#include "buffercpp.hpp"
#include <cmath>
using namespace std;

class shell_cpp
{
	bool dot_;
    bool const_;
    bool error_;
	int operator_;
	int length_;
    int braket_;
	string buffer_;
	core_cpp core_;
	buffer_cpp memory_;
    string formula_;
    string trim(double num) const;
public:
    const string operators[6] = {"+","-","x","/","(",")"};
    const string pi = to_string(acos(-1));
    const string e = to_string(exp(1));
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
    void push_const(const string & c);
    void negative();
    void set_buffer(const string & num);
    bool check() const;
	string calculate();
	string m_record() const;
	string get_buffer() const;
    string get_formula() const;
};
