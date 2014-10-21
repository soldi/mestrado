// EPOS String Utility Declarations

#ifndef __string_h
#define __string_h

extern "C" {
    int memcmp(const void * m1, const void * m2, size_t n);
    void * memcpy(void * d, const void * s, size_t n);
    void * memset(void * m, int c, size_t n);
    void * memchr(const void * m, int c, size_t n);
    int strcmp(const char * s1, const char * s2);
    int strncmp(const char * s1, const char * s2, size_t n);
    char * strcpy(char * d, const char * s);
    char * strncpy(char * d, const char * s, size_t n);
    char *strchr(const char * s, int c);
    size_t strlen(const char * s);
}

#endif