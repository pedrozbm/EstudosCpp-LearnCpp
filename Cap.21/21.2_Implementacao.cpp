#include <iostream>

class MinMax
{
private:
	int m_min {}; // The min value seen so far
	int m_max {}; // The max value seen so far

public:
	MinMax(int min, int max)
		: m_min { min }, m_max { max }
	{ }

	int getMin() const { return m_min; }
	int getMax() const { return m_max; }

	friend MinMax operator+(const MinMax& m1, const MinMax& m2);
	friend MinMax operator+(const MinMax& m, int value);
	friend MinMax operator+(int value, const MinMax& m);
};

MinMax operator+(const MinMax& m1, const MinMax& m2)
{
	// Obtém o menor valor visto em m1 e m2
	int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };

	// Obtém o maior valor visto em m1 e m2
	int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

	return MinMax { min, max };
}

MinMax operator+(const MinMax& m, int value)
{
	// Obtém o menor valor visto em m e value
	int min{ m.m_min < value ? m.m_min : value };
	// Obtém o maior valor visto em m e value
	int max{ m.m_max > value ? m.m_max : value };

	return MinMax { min, max };
}

MinMax operator+(int value, const MinMax& m)
{
	// chama operator+(MinMax, int)
	return m + value;
}

int main()
{
	MinMax m1{ 10, 15 };
	MinMax m2{ 8, 11 };
	MinMax m3{ 3, 12 };

	MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

	std::cout << "Result: (" << mFinal.getMin() << ", " <<
		mFinal.getMax() << ")\n";

	return 0;
}