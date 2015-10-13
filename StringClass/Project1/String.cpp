#include "Header.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <climits>


// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void)
{
	
	m_data = new char[m_size = 1]{ '\0' };
}

sfw::string::~string()
{
	
	delete[]m_data;
}

size_t sfw::string::length() const
{
	
	return strlen(m_data);
}





sfw::string::string(size_t size)
{
	m_data = new char[m_size = size];	// allocate memory for the dyn. array
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
	if (a != nullptr)
	{
		m_size = strlen(a) + 1;
		m_data = new char[m_size];
		m_data[0] = '\0';
		strcpy_s(m_data, m_size, a);
	}

	else
	{
		m_data = new char[m_size = 1]{ '\0' };
	}

}

sfw::string::string(const string & a)
{
	if (a.m_size > 0)
	{
		m_size = a.m_size;
		m_data = new char[m_size];
		m_data[0] = '\0';
		strcpy_s(m_data, m_size, a.m_data);
	}
	else m_data = new char[m_size = 1]{ '\0' }; // ""

}

sfw::string::string(string &&a) // move constructor
{
	m_data = a.m_data;
	m_size = a.m_size;


	a.m_data = new char[a.m_size = 1]{ '\0' };
}

sfw::string & sfw::string::operator=(const string & a) // copy assignment
{
	resize(a.m_size);
	strncpy_s(m_data, a.m_size, a.m_data, _TRUNCATE);
	return *this;
}

sfw::string & sfw::string::operator=(string && a) // move assignment
{
	// swap
	char *t = m_data;
	m_data = a.m_data;
	a.m_data = t;
	
	m_size = a.m_size;

	a.m_data[0] = '\0';
	return *this;
}

sfw::string & sfw::string::operator=(const char * a) // assignment operator (nothing special)
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
	
	return size_t(m_size);
}

void sfw::string::resize(size_t size)
{
	// TODO:
	char* t = new char[size];
	m_size = size;

	if (m_size <= 0) m_size = 1;
	if (m_size > UINT16_MAX) m_size = UINT16_MAX;

	if (m_data != nullptr) {
		strncpy_s(t, size, m_data, _TRUNCATE);
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
	
	return m_data;
}

bool sfw::operator<(const string & a, const string & b)
{
	
	return strcmp(a.cstring(), b.cstring()) < 0;
}

bool sfw::operator<(const string & a, const char * b)
{
	
	return strcmp(a.cstring(), b) < 0;
}

bool sfw::operator<(const char * a, const string & b)
{
	
	return strcmp(a, b.cstring()) < 0;
}

bool sfw::operator<=(const string & a, const string & b)
{
	return a < b || a == b;
}

bool sfw::operator<=(const string & a, const char * b)
{
	
	return strcmp(a.cstring(), b) < 0;
}

bool sfw::operator<=(const char * a, const string & b)
{
	
	return strcmp(a, b.cstring()) < 0;
}

bool sfw::operator>(const string & a, const string & b)
{
	
	return strcmp(a.cstring(),b.cstring()) > 0;
}

bool sfw::operator>(const string & a, const char * b)
{
	
	return strcmp(a.cstring(), b) > 0;
}

bool sfw::operator>(const char * a, const string & b)
{
	
	return strcmp(a, b.cstring()) > 0;
}

bool sfw::operator>=(const string & a, const string & b)
{
	
	return (a > b || a == b);
}

bool sfw::operator>=(const string & a, const char * b)
{
	
	return strcmp(a.cstring(), b ) >= 0;
}

bool sfw::operator>=(const char * a, const string & b)
{
	
	return strcmp(a, b.cstring()) >= 0;
}

bool sfw::operator!=(const string & a, const string & b)
{
	return !(a == b);
}

bool sfw::operator!=(const string & a, const char * b)
{
	return !(a == b);
}

bool sfw::operator!=(const char * a, const string & b)
{
	return !(a == b);
}

bool sfw::operator==(const string & a, const string & b)
{
	
	return strcmp(a.cstring(),b.cstring()) == 0;
}

bool sfw::operator==(const string & a, const char * b)
{
	
	return strcmp(a.cstring(), b) == 0;
}

bool sfw::operator==(const char * a, const string & b)
{
	
	return strcmp(a,b.cstring()) == 0;
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
	return string(a,len+1);
}