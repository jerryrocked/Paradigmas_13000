#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class forma{
public:

    string color,form;

    void agg_forma();
    void show_forma();
};

void forma::agg_forma(){

    cout<<"ingresa el nombre de la forma: ";
    cin>>form;

};

void forma::show_forma(){

}


class rectan: public forma{
public:
    int l_ma,l_me;

    void agg_rectan();
    void show_rectan();
};

void rectan::agg_rectan(){
    agg_forma();
    char deci;
    cout<<"quiere mostrar el rectangulo??... ";
    cin>>deci;
};

void rectan::show_rectan(){
    show_forma();
    l_ma=10;
    l_me=5;
    for(int i=0;i<l_me;i++){
        for(int j=0;j<l_ma;j++){
            cout<<"* ";
        }
    cout<<endl;
    }
    int area=(l_ma*l_me);
    cout<<"el area del rectangulo es: "<<area<<"unidades";
};

class cuadrado:public rectan{
public:
    int lado=(l_ma/2);
    void show_cuadrado();
};

void cuadrado::show_cuadrado(){
show_rectan();

    for(int i=0;i=l_ma;i++){
        for(int j=0;j<l_me;j++){
            cout<<"* ";
        }
    cout<<endl;
    }


};

int main(){
    rectan r;
    cuadrado c;
    char op;
    cout<<"Hola!!, elige una figura a imprimir:\n"<<endl;
    cout<<"a)  Rectangulo \n"<<endl;
    cout<<"b)  cuadrado \n"<<endl;
    cout<<"c)   elipse \n"<<endl;
    cout<<"Elige tu alternativa!! : ";

    cin>>op;
    switch(op){
        case'a':
            cout<<"\nhaz elegido rectangulo!!! \n"<<endl;
            r.agg_rectan();
            r.show_rectan();
        break;

        case'b':
            cout<<" haz elegido cuadrado!!!"<<endl;
            c.show_cuadrado();
        break;

        case'c':
            cout<<" haz elegido elipse!!!"<<endl;
        break;
    }


    return 0;
}

