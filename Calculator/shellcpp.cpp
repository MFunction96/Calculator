#include "shellcpp.hpp"

string shell_cpp::trim(double num) const
{
    auto flag = false;
    string str = to_string(num);
    for (auto i = 0;i < str.length();i++)
    {
        if (str[i] == '.')
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        while (str.length() > 1)
        {
            if (str.back() == '0' || str.back() == '.') str.pop_back();
            else break;
        }
    }
    return str;
}

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
		else
        {
            buffer_ = zero;
            const_ = false;
        }
	}
}

void shell_cpp::clear()
{
	buffer_ = zero;
	dot_ = false;
    const_ = false;
    error_ = false;
	operator_ = -1;
	length_ = 0;
	core_.clear();
    formula_ = "";
    braket_ = 0;
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
    try {
        if (operator_ >= 0)
        {
            core_.push_operator(core_.operators[operator_]);
            formula_ += " " + operators[operator_];
            if (operator_ == 4) braket_++;
            else if (operator_ == 5) braket_--;
            operator_ = -1;
        }
        if (const_) return;
        if (length_ > 14) return;
        if (length_) buffer_ += n;
        else if (n == "0") return;
        else buffer_ = string(n);
        length_++;
    } catch (exception e) {
        error_ = true;
    }
}

void shell_cpp::push_operator(const int index)
{
	if (operator_ < 0)
	{
		core_.push_num(atof(buffer_.c_str()));
        formula_ += " " + buffer_;
		buffer_ = zero;
		dot_ = false;
        const_ = false;
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

void shell_cpp::push_const(string & c)
{
    if (buffer_ == zero)
    {
        if (c == "PI") push_num(pi);
        else push_num(e);
        const_ = true;
    }
}

void shell_cpp::negative()
{
    if (buffer_ == zero) return;
    if (buffer_.front() == '-') buffer_.erase(buffer_.begin());
    else buffer_ = "-" + buffer_;
}

bool shell_cpp::check() const
{
    return error_;
}

string shell_cpp::calculate()
{
    double ans = core_.zero;
    try {
        ans = core_.calculate();
        clear();
    } catch (exception e) {
        error_ = true;
    }
	return trim(ans);
}

string shell_cpp::m_record() const
{
    return trim(memory_.record());
}

string shell_cpp::get_buffer() const
{
	return buffer_;
}

string shell_cpp::get_formula() const
{
    return formula_;
}
