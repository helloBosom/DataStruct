#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    double x = 25.0, y;
    for (int i = 0; i < 10; i++) {
        x = x * (1.0 + y);
        if (x > 82.7) {
            printf("%d", y);
        }
    }
    return 0;
}
