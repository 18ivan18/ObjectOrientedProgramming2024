#pragma once
#include <string>
#include <vector>

#include "TestCase.h"

/// TestSuite is a collection of many Test Cases
/// A Test Suite has a name so we can know which problem it's from
class TestSuite
{
    /// Feel free to add additional private/public methods/fields
public:
    /// Constructor we'll need for initializing the TestSuite
    TestSuite(const char *name);

    /// Add a new test case to the collection of cases
    void add(const TestCase &);

    /// Retrieve the test cases, which are passing
    std::vector<TestCase> filterPassing() const;

    /// Retrieve the test cases, which are failing
    std::vector<TestCase> filterFailing() const;

    /// Retrieve the test cases, which have the specified error type
    std::vector<TestCase> filterByErrorType(ErrorType) const;

    /// Remove all test cases with the given error type
    void removeByErrorType(ErrorType);

    /// Retrieve the name of the TestSuite
    const char *getName() const;

    /// Change the name of the TestSuite
    void setName(const char *);
};