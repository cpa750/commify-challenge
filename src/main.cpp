#include "../include/Checkout.h"

int main()
{
    Ruleset ruleset;
    ruleset.addItem('A', 60, {{3, 150}});
    ruleset.addItem('B', 30, {{2, 45}});
    ruleset.addItem('C', 30);
    ruleset.addItem('D', 25);

    Checkout checkout(ruleset);
    checkout.scan('D');
    checkout.scan('A');
    checkout.scan('B');
    checkout.scan('A');
    checkout.scan('B');
    checkout.scan('A');
    
    int total = checkout.getTotal();
    std::cout << "Total: " << total << std::endl;

    return 0;
}

