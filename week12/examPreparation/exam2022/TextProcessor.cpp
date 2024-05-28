#include "TextProcessor.h"

#include <iostream>

std::vector<TextProcessor::Tag> TextProcessor::getAllTags(const std::string &s)
{
    std::vector<TextProcessor::Tag> tags;
    bool sequenceStart = false;
    int sequenceStartIndex = -1, sequenceEndIndex = -1;
    for (size_t i = 0; i < s.size(); i++)
    {

        if (sequenceStart && i < s.size() - closingTag.length() + 1 && s.substr(i, closingTag.length()) == closingTag)
        {
            sequenceEndIndex = i;
            sequenceStart = false;

            int sequenceLength = sequenceEndIndex - sequenceStartIndex;
            tags.push_back({s.substr(sequenceStartIndex, sequenceLength), sequenceStartIndex, sequenceEndIndex});

            continue;
        }

        if (i < s.size() - openingTag.length() && s.substr(i, openingTag.length()) == openingTag)
        {
            sequenceStartIndex = i;
            sequenceStart = true;
        }
    }
    return tags;
}

TextProcessor::TextProcessor(const std::string &openingTag, const std::string &closingTag) : openingTag{openingTag}, closingTag{closingTag} {}
