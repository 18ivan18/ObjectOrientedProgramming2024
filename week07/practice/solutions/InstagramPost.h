#ifndef INSTAGRAM_POST
#define INSTAGRAM_POST

#include <fstream>
#include <iostream>
#include <cstring>

const int MAX_DESCRIPTION_SIZE = 1024;
const int MAX_PHOTO_PATH_SIZE = 64;

class InstagramPost
{
private:
    char description[MAX_DESCRIPTION_SIZE];
    unsigned int likes;
    char photoPath[MAX_PHOTO_PATH_SIZE];

public:
    void printPhoto(std::ostream &os = std::cout) const;
    void like();
    friend std::ostream &operator<<(std::ostream &os, const InstagramPost &ip);

    InstagramPost(const char *description, const char *photoPath);
    InstagramPost() {}
};

#endif