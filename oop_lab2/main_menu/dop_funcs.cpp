#include "dop_funcs.h"

const char *MSGS[] = {"0. Quit", "1. Set a", "2. Set x", "3. Set y", "4. Distance to center", "5. The farthest point from axis",
                      "6. Radius vector of curvature at characteristic points", "7. Square", "8. Length"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);


using namespace std;


template<class T>
int getNum(T &a) {
    while (!(cin>>a)){
        if(cin.eof()){
            return 0;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value.\n" << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 1;
}

int dialog(const char *msgs[], int n) {
    const char *error = "";
    int choice;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

void cases(kardioida k){
    float a, x, y;
    int c;
    do{
        c = dialog(MSGS, MSGS_SIZE);
        switch (c) {
            case 0: {
                break;
            }
            case 1:{
                cout<<"Please enter a\n";
                getNum(a);
                try{
                    k.set_a(a);
                }
                catch(runtime_error& e){
                    cout<<e.what()<<endl;
                    k.set_a(0);
                }
                break;
            }
            case 2:{
                cout<<"Please enter x\n";
                getNum(x);
                k.set_x(x);
                break;
            }
            case 3:{
                cout<<"Please enter a\n";
                getNum(y);
                k.set_y(y);
                break;
            }
            case 4:{
                cout<<"Please enter fi\n";
                float fi;
                getNum(fi);
                float rad = k.radius(fi);
                cout<<rad<<endl;
                break;
            }
            case 5:{
                float* rad = k.farthest();
                cout<<"x = "<<rad[0]<< ", y = "<<rad[1]<<endl;
                delete[] rad;
                break;
            }
            case 6:{
                float* mass = k.rad_vec();
                for(int i = 0; i < 3; i++){
                    cout<<mass[i]<<", ";
                }
                cout<<mass[3]<<endl;
                delete[] mass;
                break;
            }
            case 7:{
                float s = k.square();
                cout<<s<<endl;
                break;
            }
            case 8:{
                float l = k.lengths();
                cout<<l<<endl;
                break;
            }
        }
    }while(c);
}