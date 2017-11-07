#pragma once
#include <stack>
#include <string>
using namespace std;

class core_cpp
{
	double buffer_;
	stack<double> num_;
	stack<string> op_;
	void calculate(const string & operation);
public:
	const string operators[6] = { "+","-","*","/","(",")" };
	const double eps = 1e-6;
	const double zero = 0.0;
	const int inf = 0x7fffffff;
	core_cpp();
	~core_cpp();
    void clear();
	void push_num(const double num);
	void push_operator(const string & operation);
    bool equal_to(const double & n1, const double & n2) const;
    string get_op_top() const;
    unsigned long get_num_size() const;
	double calculate();
    double braket(const double num);
};
