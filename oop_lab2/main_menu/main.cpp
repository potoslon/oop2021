#include "dop_funcs.h"

using namespace std;

int main() {
    int c = 0;
    float x, y, a;

    while(1) {
        cout<<"Please enter a\n";
        getNum(a);
        cout<<"Please enter x\n";
        getNum(x);
        cout<<"Please enter y\n";
        getNum(y);
        try {
            kardioida k(a, x, y);
            cases(k);
            break;
        }
        catch (runtime_error &e) {
            cout << e.what() << endl;
            continue;
        }
    }
    return 0;
}
