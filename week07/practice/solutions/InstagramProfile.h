#ifndef INSTAGRAM_PROFILE
#define INSTAGRAM_PROFILE

#include "InstagramPost.h"

class InstagramProfile
{
private:
    char *username;
    unsigned int capacity, size;
    InstagramPost **posts;

    void erase();
    void copy(const InstagramProfile &);

public:
    InstagramProfile(const char *username, const char *profileFilePath, unsigned int capacity);
    InstagramProfile(const InstagramProfile &);
    InstagramProfile(InstagramProfile &&);
    InstagramProfile &operator=(const InstagramProfile &);
    InstagramProfile &operator=(InstagramProfile &&);
    ~InstagramProfile();

    void operator+=(const InstagramPost &);
    InstagramPost operator[](unsigned int);
    bool isEmpty(unsigned int);
};

#endif
