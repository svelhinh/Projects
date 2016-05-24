#include <fstream>

int main(void)
{
    std::string s1 = "bonjour", s2 = "au revoir";
    std::ofstream fd("file.replace");
    s1.replace(s1.begin(),s1.end(), s2);
    fd << s1 << std::endl;
    fd.close();
    return 0;
}
