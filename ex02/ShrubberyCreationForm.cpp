#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("DefaultTarget")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm("ShrubberyCreationForm", 145, 137), target(name)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ob): AForm(ob), target(ob.target){}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ob)
{
    if (this != &ob)
    {
        AForm::operator=(ob);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::performAction() const
{
    std::string fileName = this->target + "_shrubbery";
    std::ofstream outFile(fileName.c_str());

    if (!outFile.is_open())
    {
        std::cout << "Error: Could not open file " << fileName << std::endl;
        return ;
    }

    outFile << "      /\\      " << std::endl;
    outFile << "     /\\*\\     " << std::endl;
    outFile << "    /\\O\\*\\    " << std::endl;
    outFile << "   /*/\\/\\/\\   " << std::endl;
    outFile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outFile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outFile << "    |||||     " << std::endl;
    outFile << "    |||||     " << std::endl;


    outFile.close();
}