//
// Created by xiemenghui on 2018/7/20.
//

#include <iostream>
#include "../module/include/singleton_pattern/SingletonMain.h"
#include "../module/include/abstract_factory_pattern/FactoryMain.h"
#include "../module/include/adapter_pattern/AdapterMain.h"
#include "../module/include/bridge_pattern/BridgeMain.h"
#include "../module/include/observer_pattern/ObserverMain.h"
int main() {
    std::cout << "*******************" << std::endl;
    std::cout << "** ���ģʽ���� **" << std::endl;
    std::cout << "*******************" << std::endl;

    std::cout << "*******************" << std::endl;
    std::cout << "** ����ģʽ **" << std::endl;
    std::cout << "*******************" << std::endl;
    SingletonMain();

    std::cout << "*******************" << std::endl;
    std::cout << "** ���󹤳�ģʽ **" << std::endl;
    std::cout << "*******************" << std::endl;
    FactoryMain();
    
    std::cout << "*******************" << std::endl;
    std::cout << "** ������ģʽ **" << std::endl;
    std::cout << "*******************" << std::endl;
    AdapterMain();

    std::cout << "*******************" << std::endl;
    std::cout << "** �Ž�ģʽ **" << std::endl;
    std::cout << "*******************" << std::endl;
    BridgeMain();
    
    std::cout << "*******************" << std::endl;
    std::cout << "** �۲���ģʽ **" << std::endl;
    std::cout << "*******************" << std::endl;
    ObserverMain();

    return 0;
}