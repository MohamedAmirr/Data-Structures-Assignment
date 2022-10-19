//
// Created by mohamed on ٢٧‏/٤‏/٢٠٢٢.
//

#include "fractionCalculator.h"

void Fraction_Calculator::calculations() {
    cout << "Enter a fraction:\n";
    fraction obj;
    try{
        cin >> obj;
    }
    catch (invalid_argument&e){
        cerr<<e.what();
        return ;
    }
    cout << "type ( Enter ) to continue:\n";
    string cond;
    while (cin >> cond and cond == "Enter") {
        cout << "Enter operation that you need to perform then blank then another fraction or 'r' to reduce fraction:\n";
        char operation;
        fraction res,obj2;
        cin>>operation;
        if(operation!='r'){
            cin >> obj2;
            if (operation == '+') {
                res = obj + obj2;
            } else if (operation == '-') {
                res = obj - obj2;
            } else if (operation == '*') {
                res = obj * obj2;
            } else {
                res = obj / obj2;
            }
            cout<<"Result: "<<res<<endl;
            obj=res;
        }
        else {
            obj.reducing_fraction();
            if(obj.getDenmo()==1){
                cout<<"Result: "<<obj.getnumo()<<endl;
            }
            else
            cout<<"Result: "<<obj<<endl;
        }
        cout<<"type ( Enter ) to continue:\n";
    }
}
