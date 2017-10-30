#pragma once
#include <stack>
#include <string>
using namespace std;

class core_cpp
{
	const double eps_ = 1e-6;
	const double zero_ = 0.0;
	const int inf_ = 0x7fffffff;
	const string operator_[6] = { "+","-","*","/","(",")"};
	double buffer_;
	stack<double> num_;
	stack<string> op_;
	bool equal_to(const double & n1, const double & n2) const;
	void calculate(const string & operation);
public:
	core_cpp();
	~core_cpp();
	void push_num(const double num);
	void push_operator(const string & operation);
	double calculate();
	void clear();
};
