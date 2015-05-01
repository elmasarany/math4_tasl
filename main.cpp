#include"ttt.h"

using namespace std;

int main()
{
    char choice;

    cout<<"enter E for eular"<<endl;
    cout<<"enter I for improved eular"<<endl;
    cout<<"enter R for range kutta"<<endl;
    cout<<"enter H for hean"<<endl;
    cout<<"enter O for fourth range kutta"<<endl;

    cin>>choice;
    get_h();

    display();
    switch (choice) {
    case 'e':
    case 'E':
        eular();

        break;
   case 'i':
    case 'I':

        improve_eular();
        break;
   case'r':
    case 'R':
       range_kutta();
        break;
    case'h':
    case'H':
        hean();
        break;
    case'o':
    case'O':
        range_kutta_fourth();
        break;

    default:
        cout<<"enter correct choice";
        break;
    }
    //cout << "Hello World!" << endl;
    return 0;
}

