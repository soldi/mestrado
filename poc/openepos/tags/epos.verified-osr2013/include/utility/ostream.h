// EPOS OStream Interface

#include <system/config.h>

#ifndef __ostream_h
#define __ostream_h

__BEGIN_SYS

class OStream
{
public:
    struct Endl {};
    struct Hex {};
    struct Dec {};
    struct Oct {};
    struct Bin {};
    
public:
    OStream(): _base(10) {}

    OStream & operator<<(const Endl & endl) {
	print("\n");
	_base = 10;
	flush();
	return *this;
    }

    OStream & operator<<(const Hex & hex) {
	_base = 16;
	return *this;
    }
    OStream & operator<<(const Dec & dec) {
	_base = 10;
	return *this;
    }
    OStream & operator<<(const Oct & oct) {
	_base = 8;
	return *this;
    }
    OStream & operator<<(const Bin & bin) {
	_base = 2;
	return *this;
    }

    OStream & operator<<(char c) {
	char buf[2];
	buf[0] = c;
	buf[1] = '\0';
	print(buf);
	return *this;
    }
    OStream & operator<<(unsigned char c) { 
	return operator<<(static_cast<unsigned int>(c));
    }

    OStream & operator<<(int i) {
	char buf[64];
	buf[itoa(i, buf)] = '\0';
	print(buf);
	return *this;
    }
    OStream & operator<<(short s) {
	return operator<<(static_cast<int>(s));
    }
    OStream & operator<<(long l) {
	return operator<<(static_cast<int>(l));
    }

    OStream & operator<<(unsigned int u) {
	char buf[64];
	buf[utoa(u, buf)] = '\0';
	print(buf);
	return *this;
    }
    OStream & operator<<(unsigned short s) { 
	return operator<<(static_cast<unsigned int>(s));
    }
    OStream & operator<<(unsigned long l) {
	return operator<<(static_cast<unsigned int>(l));
    }

    OStream & operator<<(long long int u) {
	char buf[64];
	buf[llitoa(u, buf)] = '\0';
	print(buf);
	return *this;
    }

    OStream & operator<<(unsigned long long int u) {
	char buf[64];
	buf[llutoa(u, buf)] = '\0';
	print(buf);
	return *this;
    }

    OStream & operator<<(const void * p) {
	char buf[64];
	buf[ptoa(p, buf)] = '\0';
	print(buf);
	return *this;
    }

    OStream & operator<<(const char * s) { 
	print(s);
	return *this; 
    }

private:
    void print(const char * s);
    void flush() {}
    int itoa(int v, char * s);
    int utoa(unsigned int v, char * s, unsigned int i = 0);
    int llitoa(long long int v, char * s);
    int llutoa(unsigned long long int v, char * s, unsigned int i = 0);
    int ptoa(const void * p, char * s);

private:
    int _base;

    static const char _digits[];
}; 

extern OStream::Endl endl;
extern OStream::Hex hex;
extern OStream::Dec dec;
extern OStream::Oct oct;
extern OStream::Bin bin;
extern OStream kout, kerr;

__END_SYS

#endif
