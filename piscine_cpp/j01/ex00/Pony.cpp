#include "Pony.hpp"

Pony::Pony(std::string name, int color, double height): name(name), color(color), height(height)
{
    std::cout << "A pony was created" << std::endl;
    return;
}

Pony::~Pony(void)
{
    std::cout << "A pony was deleted" << std::endl;
    return;
}

Pony ponyOnTheStack(std::string name, int color, double height)
{
    Pony pony = Pony(name, color, height);
    return (pony);
}

Pony *ponyOnTheHeap(std::string name, int color, double height)
{
    Pony *pony = new Pony(name, color, height);
    return (pony);
}
