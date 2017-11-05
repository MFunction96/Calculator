#include "corecpp.hpp"

bool core_cpp::equal_to(const double & n1, const double & n2) const
{
	return n1 - n2 > eps && n2 - n1 > eps;
}

void core_cpp::calculate(const string & operation)
{
	const auto num = num_.top();
	num_.pop();
	op_.pop();
    try
    {
        if (operation == operators[0]) num_.push(num + buffer_);
        else if (operation == operators[1]) num_.push(num - buffer_);
        else if (operation == operators[2]) num_.push(num * buffer_);
        else num_.push(num / buffer_);
    }
	catch (exception e)
    {
        throw exception();
    }
	buffer_ = zero;
}

core_cpp::core_cpp()
{
    buffer_ = zero;
}

core_cpp::~core_cpp()
{

}

void core_cpp::push_num(const double num)
{
	buffer_ = num;
}

void core_cpp::push_operator(const string & operation)
{
	if (operation == operators[4])
	{
		op_.push(operation);
		return;
	}
	if (operation == operators[5])
	{
		for (auto op = op_.top(); op == operators[4]; op = op_.top())
		{
			op_.pop();
			calculate(op);
			buffer_ = num_.top();
			num_.pop();
		}
		op_.pop();
		return;
	}
	if (op_.size() == 0 || op_.top() == operators[4] || 
		((operation == operators[2] || operation == operators[3]) && 
		(op_.top() == operators[0] || op_.top() == operators[1])))
	{
		num_.push(buffer_);
		op_.push(operation);
		buffer_ = zero;
		return;
	}
	calculate(op_.top());
	op_.push(operation);
}

double core_cpp::calculate()
{
	while (op_.size())
	{
		for (auto op = op_.top(); op_.size(); op = op_.top())
		{
			op_.pop();
			calculate(op);
			buffer_ = num_.top();
			num_.pop();
		}
	}
	return num_.top();
}

void core_cpp::clear()
{
	while (op_.size()) op_.pop();
	while (num_.size()) num_.pop();
	buffer_ = zero;
}
