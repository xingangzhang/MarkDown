#ifndef DESIGNPATTERN_ADAPTEE_H
#define DESIGNPATTERN_ADAPTEE_H

#include <iostream>

// 自带的充电器（两脚扁型）
class OwnCharger
{
public:
    void ChargeWithFeetFlat()
    {
        std::cout << "OwnCharger::ChargeWithFeetFlat\n";
    }
};

#endif //DESIGNPATTERN_ADAPTEE_H
