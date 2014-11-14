#include <iostream>
#include <cstdlib> //pour rand()
#include <ctime>   //pour time()
#include <vector>
#include <algorithm>
using namespace std;

class randomPadding{
public:
    int operator()() const{
        return rand()%10;
    }
private:

};

int main()
{
    vector<int> tab(100);

    srand(time(0));

    generate(tab.begin(), tab.end(), randomPadding());

    int const nombre = count(tab.begin(), tab.end(), 2);

    cout << nombre;

    return 0;
}