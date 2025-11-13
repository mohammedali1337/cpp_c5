#include <iostream>
#include <stdexcept>
using namespace std;
// void func() {
//     try {
//         throw runtime_error("Something went wrong");
//     }
//     catch (...) {
//         cout << "Caught in func(), rethrowing..." << endl;
//         throw; // rethrow the same exception
//     }
// }
// int main(void)
// {
//     // try {
//     //     int age = -5;
//     //     if (age < 0)
//     //         throw invalid_argument("age cannot be negative \n");
//     // }
//     // catch (exception &e) {
//     //     cout << "error :" << e.what() << endl;
//     // }




//     //You can use multiple catch blocks to handle different exception types.
//     //     try {
//     //     throw 42;
//     // }
//     // catch (int n) {
//     //     cout << "Caught an int: " << n << endl;
//     // }
//     // catch (exception &e) {
//     //     cout << "Caught std::exception" << endl;
//     // }



//     try {
//         func();
//     }
//     catch (exception &e) {
//         cout << "Caught in main(): " << e.what() << endl;
//     }
// }






// int main(void)
// {
//     int x, y;
//     cout << "enter x : " << endl;
//     cin >> x;
//     cout << "enter y : " << endl;
//     cin >> y;
//     cout << endl << endl << endl;
//     // cout << x / y << endl;
//     try{
//         if (!y)
//         {
//             // cout << "y is not valide " << endl;
//             throw "division by zero !";
//         }
//         if (x > 100)
//             throw "x older tha 100 !";
//         if (y > 200)
//             throw y / x;
//         if (y < 0)
//             throw exception();
//         cout << x / y << endl;

//     }
//     catch(const char * e)
//     {
//         cout << e << endl;
//         cout << "try to enter values other than 0!" << endl;
//     }
//     catch (int num)
//     {

//         cout <<" catch for num " << num << endl;
//     }

//     catch (...)
//     {
//         cout << "error , try again (random issue )" << endl;
//     }

//     cout << "hello world " << endl;
//     return 0;
// }


// int compareage(int sonAge, int momAge)
// {
//     if (sonAge >= momAge)
//         throw 1;
//     else if (sonAge <= 0)
//         throw 2;
//     else if (momAge <= 0)
//             throw 3;
//     else if (momAge - sonAge < 12)
//         throw 4;
//     return momAge - sonAge;
// }


// int main(void)
// {
//     try
//     {
//         compareage(26, 24);
//     }
//     catch (int e)
//     {
//         switch (e)
//         {
//         case 1:
//             cout << "Error: son's age can't be less than his mom! \n" << endl;
//             break;
//         case 2:
//             cout << "Error: Son's age can't be less than or equal zero \n" << endl;
//             break;
//         case 3:
//             cout <<  "Error: Mom's age can't be less than or equal zero \n" << endl;
//             break;
//         case 4:
//             cout << "Error: Mom's age should be 12 years bigger than son age \n" << endl;
//             break;
//         }
//     }

//     cout << "the program is still working properly " << endl;
    
//     return 0;
    
// }






// عند استدعاءها نمرر لها عدد يمثل العمر checkAge() هنا قمنا بتعريف دالة إسمها
void checkAge(int age)
{
    // في حال كان العمر الذي تم تمريره لها أصغر أو يساوي 0 سترمي إستثناء
    if (age <= 0)
        throw "Error: Entered age can't be less or equal zero!";
    
    // في حال كان العمر الذي تم تمريره لها أكبر من 130 سترمي إستثناء
    if (age > 130)
        throw "Error: Entered age is impossible!";
    
    // في حال كان العمر الذي تم تمريره لها أصغر من 18 سترمي إستثناء
    if (age < 18)
        throw "Error: You are not allowed!";

    // إذا لم يتم رمي أي إستثناء سيتم تنفيذ أمر الطباعة التالي و الذي يعني أن العمر مقبول
    cout << "Age confirmed!";
}


// main() هنا قمنا بتعريف الدالة
int main()
{
    // و تمرير القيمة 15 لها checkAge() هنا قمنا باستدعاء الدالة 
    try
    {
        checkAge(19);
    }
    // بالتقاطه و طباعة الجملة الموضوعة فيه catch() ستقوم الدالة try أي إستثناء يتم رميه في الجملة
    catch (...)
    {
        cout << "Oops.. Something is not right!";
    }

    return 0;
}