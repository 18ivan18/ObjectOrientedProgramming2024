#include "InstagramProfile.h"

void InstagramProfile::erase()
{
    for (size_t i = 0; i < size; i++)
    {
        delete posts[i];
    }
    delete[] posts;
    posts = nullptr;
}

void InstagramProfile::copy(const InstagramProfile &other)
{
    size = other.size;
    capacity = other.capacity;
    // assert(posts == nullptr);
    posts = new InstagramPost *[other.size];
    username = new char[strlen(other.username) + 1];
    strcpy(username, other.username);
    for (size_t i = 0; i < size; i++)
    {
        posts[i] = new InstagramPost(*other.posts[i]);
    }
}

InstagramProfile::InstagramProfile(const char *username, const char *profileFilePath, unsigned int capacity) : username{new char[strlen(username) + 1]}, capacity{capacity}, size{0}, posts{new InstagramPost *[capacity]}
{
    strcpy(this->username, username);
    std::ifstream is(profileFilePath, std::ios::binary);

    if (!is)
    {
        // "Could not open profile file."
        throw new std::exception();
    }

    is.seekg(0, std::ios::end);
    int fileSize = is.tellg();
    is.seekg(0, std::ios::beg);
    size = fileSize / sizeof(InstagramPost);
    if (size > capacity)
    {
        std::cerr << "The number of posts of user " << username << " exceeds the limits of posts. Limit: " << capacity << " Number of entries: " << size << std::endl;
        size = capacity;
    }
    InstagramPost *posts = new InstagramPost[size];

    is.read((char *)posts, size * sizeof(InstagramPost));

    for (size_t i = 0; i < size; i++)
    {
        this->posts[i] = new InstagramPost(posts[i]);
    }
    delete[] posts;

    for (size_t i = size; i < capacity; i++)
    {
        this->posts[i] = nullptr;
    }

    is.close();
}

InstagramProfile::InstagramProfile(const InstagramProfile &other) : size{other.size}, capacity{other.capacity}, posts{nullptr}, username{nullptr}
{
    copy(other);
}

InstagramProfile::InstagramProfile(InstagramProfile &&other) : size{other.size}, capacity{other.capacity}, username{other.username}, posts{other.posts}
{
    other.size = 0;
    other.capacity = 0;
    other.username = nullptr;
    other.posts = nullptr;
}

InstagramProfile &InstagramProfile::operator=(const InstagramProfile &rhs)
{
    if (this != &rhs)
    {
        erase();
        copy(rhs);
    }
    return *this;
}

InstagramProfile &InstagramProfile::operator=(InstagramProfile &&rhs)
{

    size = rhs.size;
    capacity = rhs.capacity;
    username = rhs.username;
    posts = rhs.posts;
    rhs.size = 0;
    rhs.capacity = 0;
    rhs.username = nullptr;
    rhs.posts = nullptr;

    return *this;
}

InstagramProfile::~InstagramProfile()
{
    erase();
}

void InstagramProfile::operator+=(const InstagramPost &ip)
{
    if (size == capacity)
    {
        delete posts[size - 1];
        posts[size - 1] = nullptr;
        size--;
    }
    posts[size++] = new InstagramPost(ip);
}

InstagramPost InstagramProfile::operator[](unsigned int idx)
{
    if (isEmpty(idx))
    {
        // "Invalid index."
        throw std::exception();
    }
    return *posts[idx];
}

bool InstagramProfile::isEmpty(unsigned int idx)
{
    if (idx >= capacity)
    {
        // "Invalid index."
        throw std::exception();
    }
    return !posts[idx];
}
