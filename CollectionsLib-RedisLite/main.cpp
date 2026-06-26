#include <iostream>
using namespace std;
#include "CollectionsLib.h"

int main() {
    std::cout << "Testing CollectionsLib Master Library" << std::endl;
    
    // Example usage of your structures:
    DynamicArray<int> myArr;
    myArr.pushBack(10);
    myArr.pushBack(20);
    
    std::cout << "Array size: " << myArr.getSize() << std::endl;
    std::cout << "First element: " << myArr.get(0) << std::endl;

    return 0;
}
