#pragma once

class buffer_cpp
{
	const double zero_ = 0.0;
	double buffer_;
public:
	buffer_cpp();
	~buffer_cpp();
	void add(const double num);
	void minus(const double num);
	void clear();
	double record() const;
};
