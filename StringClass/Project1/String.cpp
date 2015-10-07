#include "Header.h"
#include <iostream>
#include <cstring>
#include <cassert>

// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void)
{
	// TODO: is this finished?
	m_data = new char[m_size = 1]{ '\0' };
}

sfw::string::~string()
{
	// TODO: is this finished?
	delete[]m_data;
}

size_t sfw::string::length() const
{
	// TODO: is this finished?
	return strlen(m_data);
}





sfw::string::string(size_t size)
{
	m_data = new char[m_size = size + 1];	// allocate memory for the dyn. array
	m_data[m_size - 1] = '\0';			// set the last available character to null-term
}

sfw::string::string(const char * a, size_t size)
{
	m_size = size;	// record the desired size of the array
	m_data = new char[m_size];

	strncpy_s(m_data, m_size, a, m_size - 1);	// copy the string data from the cstring into ours
}

sfw::string::string(const char * a)
{
	if (a != nullptr) {
	m_size = strlen(a) + 1;
	m_data = new char[m_size];
	m_data[0] = '\0';
	strcpy_s(m_data, m_size, a);
	}


}

sfw::string::string(const string & a)
{
	m_size = a.m_size;
	m_data = new char[m_size];
	m_data[0] = '\0';
	strcpy_s(m_data, m_size, a.m_data);

}

sfw::string::string(string && a)
{
	// TODO:
}

sfw::string & sfw::string::operator=(const string & a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator=(const char * a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(const string & a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(const char * a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(char a)
{
	// TODO:
	return *this;
}

char & sfw::string::operator[](size_t index)
{
	// TODO: Is this finished?
	return this->m_data[index];
}

const char & sfw::string::operator[](size_t index) const
{
	// TODO: Is this finished?
	return this->m_data[index];
}




size_t sfw::string::size() const
{
	// TODO:
	
	return size_t(m_size - 1);
}

void sfw::string::resize(size_t size)
{
	// TODO:
	char* t = new char[size];
	m_size = size;
	if (m_data != nullptr) {
		strncpy_s(t, size, m_data, m_size);
		delete[]m_data;
	}
	m_data = t;
	m_data[m_size - 1] = '\0';

}

void sfw::string::clear()
{
	m_data[0] = '\0';
	// TODO:
}

bool sfw::string::empty() const
{
	// TODO:
	return m_data[0] =='\0';
}

const char * sfw::string::cstring() const
{
	// TODO:
	return m_data;
}

bool sfw::operator<(const string & a, const string & b)
{
	// TODO:
	if(strcmp(a<b) = )
	return true;
}

bool sfw::operator<(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator<(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const char * a, const string & b)
{
	// TODO:
	return false;
}

sfw::string sfw::operator+(const string & a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, const char * b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const char * a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, char b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(char a, const string & b)
{
	// TODO:
	return string();
}

std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	// TODO:
	return os;
}

std::istream & sfw::operator>>(std::istream & is, string & p)
{
	// TODO:
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	// TODO:
	return string();
}