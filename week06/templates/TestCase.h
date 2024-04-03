#pragma once
#include <string>

#include "Error.h"

/// TestCase represents the result of a test that has been
/// executed. It may be passing or failing and in the case
/// of a failing test, there's some Error different from None
class TestCase
{
    /// Feel free to add additional private/public methods/fields
public:
    /// Constructor we'll need to create a new TestCase
    TestCase(const char *name = "", const Error &error = Error::newNone());

    /// Retrieve the name of the TestCase
    const char *getName() const;

    /// Check if the test is passing or failing. A test is passing if
    /// its Error is None or Warning
    bool isPassing() const;

    /// Check if the test has an Error. A test has an error if its
    /// Error is different from None. This is a method intended to be
    /// used before calling getErrorType() or getErrorMessage()
    bool hasError() const;

    /// Retrieve the type of Error this test has (it could be None)
    ErrorType getErrorType() const;

    /// Retrieve the message of the error if Error has one,
    /// otherwise return an empty string
    const char *getErrorMessage() const;
};