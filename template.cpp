// #include <iostream>

// using namespace std;

// template <class T>

// T Max(T a, T b)
// {
//     return (a < b ? b:a);
// }

// int main(void)
// {

//     cout << "Max: " << Max(1, 2) << endl;
//     cout << "Max: " << Max(1.5, 2.5) << endl;
//     return 0;

// }

// #include <iostream>

// using namespace std;

// template <typename T> T myMax(T x, T y)
// {
//     return (x > y) ? x:y;
// }

// int main(void)
// {
//     cout << "Max of 3 and 7 is: " << myMax(3, 7) << endl;
//     cout << "Max of 3.5 and 7.5 is :" << myMax<double>(3.5, 7.5) << endl;
//     cout << "Max of 'g' and 'e' is: " << myMax<char>('g', 'e') << endl;
    
//     return 0;
// }



// class templates

#include <iostream>
using namespace std;

// Template function to return maximum of two values
template <typename T> class Geek
{
	public:
		T x;
		T y;
		Geek(T xx, T yy): x(xx), y(yy){}
		void getValue()
		{
			cout << x << " " << y << endl;
		}
};


int main(void)
{
	Geek<int> intGeek(1, 2);
	Geek<double> doubleGeek(2.3, 3.3);
	
	intGeek.getValue();
	doubleGeek.getValue();
	return 0;
}


// we can pass more than one data type as arguments to templates

// template <typename T1, typename T2, typename T3>
// class Geek{
//     public:
//     T1 x;
//     T2 y;
//     T3 z;

//     //constructor to initialization
//     Geek(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3)
//     {
//     }

//     void getValues()
//     {
//         cout << x << " " << y << " " << z;
//     }
// };


// int main(void)
// {
//     // Creating objects of Geek with different data types
//     Geek<int, double, string> intDoubleStringGeek(10, 3.14, "Hello");
//     Geek<char, float, bool> charFloatBoolGeek('A', 5.67f, true);

//     intDoubleStringGeek.getValues();
//     cout << endl;
//     charFloatBoolGeek.getValues();

//     return 0;
// }

