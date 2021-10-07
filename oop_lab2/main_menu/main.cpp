#include "dop_funcs.h"

using namespace std;

int main() {
    int c = 1;
    float x, y, a;
    while(c) {
        cout<<"Please enter a\n";
        c = getNum(a);
        if(c == 0){
            return 0;
        }
        cout<<"Please enter x\n";
        c = getNum(x);
        if(c == 0){
            return 0;
        }
        cout<<"Please enter y\n";
        c = getNum(y);
        if(c == 0){
            return 0;
        }
        try {
            kardioida k(a, x, y);
            cases(k);
            return 0;
        }
        catch (runtime_error &e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
