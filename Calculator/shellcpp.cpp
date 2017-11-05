#include "shellcpp.hpp"

shell_cpp::shell_cpp()
{
	clear();
}

shell_cpp::~shell_cpp()
{

}

void shell_cpp::backspace()
{
	if (length_)
	{
		if (buffer_.back() == '.') dot_ = false;
		else length_--;
		if (length_) buffer_.pop_back();
		else buffer_ = zero;
	}
}

void shell_cpp::clear()
{
	buffer_ = zero;
	dot_ = false;
	operator_ = -1;
	length_ = 0;
	core_.clear();
    formula_ = "";
}

void shell_cpp::m_add(const string & num)
{
	memory_.add(atof(num.c_str()));
}

void shell_cpp::m_minus(const string & num)
{
	memory_.minus(atof(num.c_str()));
}

void shell_cpp::m_clear()
{
	memory_.clear();
}

void shell_cpp::push_num(const string & n)
{
	if (operator_ >= 0)
	{
        core_.push_operator(core_.operators[operator_]);
        formula_ += " " + operators[operator_];
		operator_ = -1;
	}
	if (length_ > 14) return;
	if (length_) buffer_ += n;
    else if (n == "0") return;
	else buffer_ = string(n);
	length_++;
}

void shell_cpp::push_operator(const int index)
{
	if (operator_ < 0)
	{
		core_.push_num(atof(buffer_.c_str()));
        formula_ += " " + buffer_;
		buffer_ = zero;
		dot_ = false;
        length_ = 0;
	}
	operator_ = index;
}

void shell_cpp::push_dot()
{
	if (!dot_)
	{
		dot_ = true;
		buffer_ += ".";
	}
}

double shell_cpp::get_num() const
{
	return stod(buffer_);
}

double shell_cpp::calculate()
{
	const auto ans = core_.calculate();
	clear();
	return ans;
}

string shell_cpp::m_record() const
{
	return to_string(memory_.record());
}

string shell_cpp::get_buffer() const
{
	return buffer_;
}

string shell_cpp::get_formula() const
{
    return formula_;
}
