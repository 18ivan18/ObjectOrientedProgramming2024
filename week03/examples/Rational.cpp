class Rational
{
private:
    int numerator;
    int denominator;

public:
    void setNumerator(int n)
    {
        numerator = n;
    }
    int getNumerator()
    {
        return numerator;
    }
    void setDenominator(int n)
    {
        numerator = n;
    }
    int getDenominator()
    {
        return denominator;
    }
    Rational add(Rational &b)
    {
        Rational c;
        if (this->denominator == b.denominator)
        {
            c.numerator = this->numerator + b.denominator;
            c.denominator = this->denominator;
        }
        else
        {
            c.numerator = this->numerator * b.denominator + b.numerator * this->denominator;
            c.denominator = this->denominator * b.denominator;
        }
        return c;
    }
};

int main()
{
    Rational a, b, c;
    a.setNumerator(5);
    a.setDenominator(7);
    b.setNumerator(3);
    b.setDenominator(4);
    c = a.add(b);
}