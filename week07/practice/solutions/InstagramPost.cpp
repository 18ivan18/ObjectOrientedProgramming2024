#include "InstagramPost.h"

void InstagramPost::printPhoto(std::ostream &os) const
{
    std::ifstream is(photoPath);

    if (!is)
    {
        // "Could not open photo."
        throw new std::exception();
    }

    // Get the file's size
    is.seekg(0, std::ios::end);
    int size = is.tellg();
    is.seekg(0, std::ios::beg);

    char *content = new char[size]; // Allocate memory for the content
    is.read(content, size);         // Read the content into the char array
    os << content;                  // Print the content to the console
    delete content;

    is.close();
}

void InstagramPost::like()
{
    likes++;
}

std::ostream &operator<<(std::ostream &os, const InstagramPost &ip)
{
    ip.printPhoto(os);
    os << "\nLiks: " << ip.likes << "\nDescription: " << ip.description << '\n';

    return os;
}

InstagramPost::InstagramPost(const char *description, const char *photoPath) : likes{0}
{
    strcpy(this->description, description);
    strcpy(this->photoPath, photoPath);
}