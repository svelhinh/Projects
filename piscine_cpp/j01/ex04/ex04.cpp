#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *pt = &brain;
    std::string &ref = brain;

    std::cout << "pointer : " << *pt << std::endl;
    std::cout << "reference : " << ref << std::endl;
    return 0;
}
