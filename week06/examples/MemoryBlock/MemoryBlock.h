#pragma once
#include <iostream>
#include <algorithm>

class MemoryBlock
{
public:
    // Simple constructor that initializes the resource.
    explicit MemoryBlock(size_t length)
        : mLength(length), mData(new int[length])
    {
        std::cout << "In MemoryBlock(size_t). length = "
                  << mLength << "." << std::endl;
    }

    // Destructor.
    ~MemoryBlock()
    {
        std::cout << "In ~MemoryBlock(). length = "
                  << mLength << ".";

        if (mData != nullptr)
        {
            std::cout << " Deleting resource.";
            // Delete the resource.
            delete[] mData;
        }

        std::cout << std::endl;
    }

    // Copy constructor.
    MemoryBlock(const MemoryBlock &other)
        : mLength(other.mLength), mData(new int[other.mLength])
    {
        std::cout << "In MemoryBlock(const MemoryBlock&). length = "
                  << other.mLength << ". Copying resource." << std::endl;

        std::copy(other.mData, other.mData + mLength, mData);
    }

    // Copy assignment operator.
    MemoryBlock &operator=(const MemoryBlock &other)
    {
        std::cout << "In operator=(const MemoryBlock&). length = "
                  << other.mLength << ". Copying resource." << std::endl;

        if (this != &other)
        {
            // Free the existing resource.
            delete[] mData;

            mLength = other.mLength;
            mData = new int[mLength];
            std::copy(other.mData, other.mData + mLength, mData);
        }
        return *this;
    }

    // Move constructor.
    MemoryBlock(MemoryBlock &&other) noexcept
        : mData(nullptr), mLength(0)
    {
        std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                  << other.mLength << ". Moving resource." << std::endl;

        // Copy the data pointer and its length from the
        // source object.
        mData = other.mData;
        mLength = other.mLength;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other.mData = nullptr;
        other.mLength = 0;
    }

    // using std::move
    // MemoryBlock(MemoryBlock &&other) noexcept
    //     : mData(nullptr), mLength(0)
    // {
    //     *this = std::move(other);
    // }

    // Move assignment operator.
    MemoryBlock &operator=(MemoryBlock &&other) noexcept
    {
        std::cout << "In operator=(MemoryBlock&&). length = "
                  << other.mLength << "." << std::endl;

        if (this != &other)
        {
            // Free the existing resource.
            delete[] mData;

            // Copy the data pointer and its length from the
            // source object.
            mData = other.mData;
            mLength = other.mLength;

            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other.mData = nullptr;
            other.mLength = 0;
        }
        return *this;
    }

    // Retrieves the length of the data resource.
    size_t length() const
    {
        return mLength;
    }

private:
    size_t mLength; // The length of the resource.
    int *mData;     // The resource.
};