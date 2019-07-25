#include "../../include/abstract_factory_pattern/Factory.h"
#include "../../include/abstract_factory_pattern/product.h"
#include "../../include/abstract_factory_pattern/FactoryMain.h"
#include <iostream>
using namespace std;

void FactoryMain()
{
    Factory * pFactory = Factory::CreateFactory(Factory::FACTORY_TYPE::BENZ_FACTORY);
    ICar * pCar = pFactory->CreateCar();
    IBike * pBike = pFactory->CreateBike();

    cout << "Benz factory - Car: " << pCar->Name() << endl;
    cout << "Benz factory - Bike: " << pBike->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pBike);
    SAFE_DELETE(pFactory);

    pFactory = Factory::CreateFactory(Factory::FACTORY_TYPE::BMW_FACTORY);
    pCar = pFactory->CreateCar();
    pBike = pFactory->CreateBike();
    cout << "Bmw factory - Car: " << pCar->Name() << endl;
    cout << "Bmw factory - Bike: " << pBike->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pBike);
    SAFE_DELETE(pFactory);

    pFactory = Factory::CreateFactory(Factory::FACTORY_TYPE::AUDI_FACTORY);
    pCar = pFactory->CreateCar();
    pBike = pFactory->CreateBike();
    cout << "Audi factory - Car: " << pCar->Name() << endl;
    cout << "Audi factory - Bike: " << pBike->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pBike);
    SAFE_DELETE(pFactory);
}