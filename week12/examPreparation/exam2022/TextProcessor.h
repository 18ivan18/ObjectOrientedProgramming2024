#ifndef TEXT_PROCESSOR_H
#define TEXT_PROCESSOR_H
#include <string>
#include <vector>

class TextProcessor
{
private:
    std::string openingTag, closingTag;

public:
    TextProcessor(const std::string &openingTag, const std::string &closingTag);
    struct Tag
    {
        std::string tagString;
        int startIndex, endIndex;
    };
    std::vector<TextProcessor::Tag> getAllTags(const std::string &s);
    static char toupper(char c)
    {
        if (c <= 'z' && c >= 'a')
        {
            return c - 'a' + 'A';
        }
        return c;
    }
};

#endif