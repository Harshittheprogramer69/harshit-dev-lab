#include <iostream>
using namespace std;

class BASE_1 {
    public:
        BASE_1() {
            cout << "First Base\n";
        }
};
class BASE_2 {
    public:
        BASE_2() {
            cout << "Second Base\n";
        }
};
class MAIN_BASE : public BASE_1 {
    public:
        MAIN_BASE() {
            cout << "ITS MAIN BASE\n";
        }
};
class MAIN : public BASE_1, public BASE_2 {
    public:
        MAIN() {
            cout << "ITS THE MAIN\n";
        }
};

int main() {
    MAIN m;
    return 0;
}