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
            if (str.back() == '0') str.pop_back();
            else if (str.back() == '.')
            {
                str.pop_back();
                break;
            }
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
    merge_ = false;
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
    if (index == 4)
    {
        if (length_) return;
        if (core_.get_num_size())
        {
            core_.push_operator(core_.operators[operator_]);
            formula_ += " " + core_.operators[operator_];
        }
        operator_ = 4;
        braket_++;
        merge_ = false;
        buffer_ = zero;
        dot_ = false;
        const_ = false;
        length_ = 0;
        return;
    }
    if (index == 5)
    {
        if ((length_ < 1 && !merge_) || braket_ < 1) return;
        if (!merge_) formula_ += " " + buffer_;
        formula_ += " )";
        const auto p = core_.braket(atof(buffer_.c_str()));
        operator_ = -1;
        buffer_ = trim(p);
        dot_ = false;
        const_ = false;
        length_ = 0;
        braket_--;
        merge_ = true;
        return;
    }
	if (operator_ < 0)
	{
		core_.push_num(atof(buffer_.c_str()));
        if (!merge_) formula_ += " " + buffer_;
        merge_ = false;
		buffer_ = zero;
		dot_ = false;
        const_ = false;
        length_ = 0;
	}
    merge_ = false;
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

void shell_cpp::push_const(const string & c)
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

void shell_cpp::set_buffer(const string & num)
{
    buffer_ = num;
}

bool shell_cpp::check() const
{
    return error_;
}

string shell_cpp::calculate()
{
    if (!merge_) formula_ += " " + buffer_;
    while (braket_)
    {
        formula_ += " )";
        push_operator(5);
    }
    double ans = core_.zero;
    try {
        core_.push_num(atof(buffer_.c_str()));
        ans = core_.calculate();
    } catch (exception e) {
        error_ = true;
    }
    if (!core_.equal_to(ans, core_.zero)) formula_ += " =";
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
