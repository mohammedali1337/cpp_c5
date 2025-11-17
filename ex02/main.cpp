#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib> // For std::srand
#include <ctime>   // For std::time

int main()
{
    // Seed the random number generator ONCE for RobotomyRequestForm
    std::srand(std::time(NULL));

    /*
    // -----------------------------------------------------------------
    // --- THIS BLOCK WILL NOT COMPILE (AForm is abstract) ---
    // -----------------------------------------------------------------
    
    // AForm test("AForm", 1, 1); // <-- Uncommenting this line must cause a compile error
    
    // -----------------------------------------------------------------
    */


    // -----------------------------------------------------------------
    // --- TEST 1: Bureaucrat and Form Instantiation ---
    // -----------------------------------------------------------------
    std::cout << "--- 1. TESTING INSTANTIATION ---\n" << std::endl;
    
    Bureaucrat* zaphod = NULL;
    Bureaucrat* arthur = NULL;

    try {
        zaphod = new Bureaucrat("Zaphod", 1);    // Top grade
        arthur = new Bureaucrat("Arthur", 140); // Low grade
        std::cout << *zaphod << std::endl;
        std::cout << *arthur << std::endl;

        Bureaucrat invalid("Invalid", 151);     // Will throw
    } 
    catch (std::exception &e) {
        std::cerr << "Instantiation Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Creating Forms ---\n" << std::endl;

    // AForm pointers are used to demonstrate polymorphism
    AForm* shrub = new ShrubberyCreationForm("home");
    AForm* robo = new RobotomyRequestForm("Bender");
    AForm* pardon = new PresidentialPardonForm("Ford");

    std::cout << *shrub << std::endl;
    std::cout << *robo << std::endl;
    std::cout << *pardon << std::endl;


    // -----------------------------------------------------------------
    // --- TEST 2: Signing and Executing (Success) ---
    // -----------------------------------------------------------------
    std::cout << "\n--- 2. TESTING SIGN & EXECUTE (SUCCESS) ---\n" << std::endl;

    zaphod->signForm(*shrub);
    zaphod->executeForm(*shrub);
    std::cout << "\n(Check for the 'home_shrubbery' file in your directory)\n" << std::endl;

    zaphod->signForm(*robo);
    zaphod->executeForm(*robo);
    std::cout << std::endl;
    
    zaphod->signForm(*pardon);
    zaphod->executeForm(*pardon);
    std::cout << std::endl;

    // -----------------------------------------------------------------
    // --- TEST 3: Execution Failures (Not Signed / Grade Too Low) ---
    // -----------------------------------------------------------------
    std::cout << "\n--- 3. TESTING EXECUTION FAILURES ---\n" << std::endl;
    
    AForm* unsignedPardon = new PresidentialPardonForm("Trillian");
    
    // Test 1: Execute without signing
    std::cout << "--- Attempt: Execute unsigned form ---" << std::endl;
    zaphod->executeForm(*unsignedPardon); // Fails: FormNotSignedException
    std::cout << std::endl;

    // Test 2: Sign, but fail execution (Grade Too Low)
    std::cout << "--- Attempt: Low grade executes high form ---" << std::endl;
    std::cout << *arthur << std::endl;
    arthur->signForm(*shrub);   // Success: Arthur (140) can sign (145)
    arthur->executeForm(*shrub); // Fails: Arthur (140) cannot exec (137)
    std::cout << std::endl;

    // Test 3: Fail signing (Grade Too Low)
    std::cout << "--- Attempt: Low grade signs high form ---" << std::endl;
    arthur->signForm(*pardon); // Fails: Arthur (140) cannot sign (25)
    std::cout << std::endl;


    // -----------------------------------------------------------------
    // --- TEST 4: Robotomy 50/50 Chance ---
    // -----------------------------------------------------------------
    std::cout << "\n--- 4. TESTING ROBOTOMY 50/50 CHANCE ---\n" << std::endl;
    
    zaphod->executeForm(*robo);
    zaphod->executeForm(*robo);
    zaphod->executeForm(*robo);
    zaphod->executeForm(*robo);
    

    // -----------------------------------------------------------------
    // --- CLEANUP ---
    // -----------------------------------------------------------------
    std::cout << "\n--- 5. CLEANING UP ---\n" << std::endl;
    
    delete zaphod;
    delete arthur;
    delete shrub;
    delete robo;
    delete pardon;
    delete unsignedPardon;

    return 0;
}