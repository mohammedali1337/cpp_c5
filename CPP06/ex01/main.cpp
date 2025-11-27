#include "Serializer.hpp"

int main(void)
{
    Data ptr;

    ptr.name = "simo";
    ptr.x = 42;
    std::cout << "address: " << &ptr << std::endl;
    std::cout << "name: " << ptr.name << std::endl << "x: " << ptr.x << std::endl;

    uintptr_t raw;

    raw = Serializer::serialize(&ptr);

    Data* newptr = Serializer::deserialize(raw);

    std::cout << "adress: " << newptr << std::endl;
    std::cout << "name: " << ptr.name << std::endl << "x: " << ptr.x << std::endl;

    return 0;
}