#include <iostream>
#include <cassert>

class IntArray
{
private:
    int *m_array{nullptr};
    int m_length{0};

public:
    explicit IntArray(int length) : m_length{length}
    {
        assert ( length > 0 && "O comprimento deve ser positivo! ");
        m_array = new int [static_cast<std::size_t>(m_length)]{};
    }
   
   
    ~IntArray()
    {
        delete[] m_array;
        std::cout << "destruidor chamado \n";
    }

    void deepCopy(const IntArray &arr)
    {
        delete[] m_array;

        m_length = arr.m_length;

        if (arr.m_array)
        {
            m_array = new int[m_length];
            
            for (int i{0}; i < m_length; ++i)
            {
                m_array[i] = arr.m_array[i];
            }
        }
        else
        {
            m_array = nullptr;
        }
    }


    friend std::ostream &operator<<(std::ostream &out, IntArray &arr)
    {
        for (int i{0}; i < arr.m_length; ++i)
        {
            out << arr.m_array[i] << " ";
        }
        return out;
    }

    int &operator[](int index) { return m_array[index]; }

    IntArray &operator=(const IntArray &arr)
    {
        if (this != &arr)
        {
            deepCopy(arr);
        }
        return *this;
    }

    double operator()(int num)
{
    // assert("numero invalido" && num < 0);

    return m_array[num];
}
};

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{fillArray()};

    std::cout << a << '\n';

    auto& ref{a};
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}

// Essa foi a minha solução... 
// Agora abaixo é a solução do LearnCpp:

// #include <iostream>
// #include <cassert> // for assert

// class IntArray
// {
// private:
// 	int m_length{ 0 };
// 	int* m_array{ nullptr };

// public:
// 	explicit IntArray(int length)
// 		: m_length{ length }
// 	{
// 		assert(length > 0 && "IntArray length should be a positive integer");

// 		m_array = new int[static_cast<std::size_t>(m_length)] {};
// 	}

// 	// Copy constructor that does a deep copy
// 	IntArray(const IntArray& array)
// 		: m_length{ array.m_length }
// 	{
// 		// Allocate a new array
// 		m_array = new int[static_cast<std::size_t>(m_length)] {};

// 		// Copy elements from original array to new array
// 		for (int count{ 0 }; count < array.m_length; ++count)
// 			m_array[count] = array.m_array[count];
// 	}

// 	~IntArray()
// 	{
// 		delete[] m_array;
// 	}

// 	// If you're getting crazy values here you probably forgot to do a deep copy in your copy constructor
// 	friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
// 	{
// 		for (int count{ 0 }; count < array.m_length; ++count)
// 		{
// 			out << array.m_array[count] << ' ';
// 		}
// 		return out;
// 	}

// 	int& operator[] (const int index)
// 	{
// 		assert(index >= 0);
// 		assert(index < m_length);
// 		return m_array[index];
// 	}

// 	// Assignment operator that does a deep copy
// 	IntArray& operator= (const IntArray& array)
// 	{
// 		// self-assignment guard
// 		if (this == &array)
// 			return *this;

// 		// If this array already exists, delete it so we don't leak memory
// 		delete[] m_array;

// 		m_length = array.m_length;

// 		// Allocate a new array
// 		m_array = new int[static_cast<std::size_t>(m_length)] {};

// 		// Copy elements from original array to new array
// 		for (int count{ 0 }; count < array.m_length; ++count)
// 			m_array[count] = array.m_array[count];

// 		return *this;
// 	}

// };

// IntArray fillArray()
// {
// 	IntArray a(5);
// 	a[0] = 5;
// 	a[1] = 8;
// 	a[2] = 2;
// 	a[3] = 3;
// 	a[4] = 6;

// 	return a;
// }

// int main()
// {
// 	IntArray a{ fillArray() };

// 	// If you're getting crazy values here you probably forgot to do a deep copy in your copy constructor
// 	std::cout << a << '\n';

// 	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
// 	a = ref;

// 	IntArray b(1);
// 	b = a;

// 	a[4] = 7; // change value in a, b should not change

// 	// If you're getting crazy values here you probably forgot to do self-assignment check
// 	// If b ends in 7, you probably forgot to do a deep copy in your copy assignment
// 	std::cout << b << '\n';

// 	return 0;
// }