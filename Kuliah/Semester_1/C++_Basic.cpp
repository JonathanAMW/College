#include <iostream>

int main() {
    std::cout << "berapa maks?" << std::endl;
    int num;
    std::cin >> num;
    int data[num];

    for (int i = 0;i<num;i++) {
        std::cout << "masukan data ke " << i+1 << std::endl;
        std::cin >> data[i];
    }

    for (int i = 0;i<num;i++) {
        std::cout << "data ke " << i+1 << "adalah " << data[i] << std::endl;
    }
}