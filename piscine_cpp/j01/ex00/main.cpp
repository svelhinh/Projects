#include "Pony.hpp"

int main(void)
{
    Pony pony = ponyOnTheStack("pony", 0xffffff, 12.5);
    Pony *pony2 = ponyOnTheHeap("pony2", 0xff, 10.3);

    std::cout << "Pony On The Stack : " << pony.name << ", " << pony.color << ", " << pony.height << std::endl;
    std::cout << "Pony On The Heap : " << pony2->name << ", " << pony2->color << ", " << pony2->height << std::endl;
    delete pony2;
    return 0;
}
