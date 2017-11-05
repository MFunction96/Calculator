#include "buffercpp.hpp"

buffer_cpp::buffer_cpp()
{
	buffer_ = zero_;
}

buffer_cpp::~buffer_cpp()
{

}

void buffer_cpp::add(const double num)
{
	buffer_ += num;
}

void buffer_cpp::minus(const double num)
{
	buffer_ -= num;
}

void buffer_cpp::clear()
{
	buffer_ = zero_;
}

double buffer_cpp::record() const
{
	return buffer_;
}
