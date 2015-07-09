#ifndef Complexe_H_INCLUDED
#define Complexe_H_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

class Complexe
{
private :         double _re;                                         double _im;
public :
/************************            Constructeur Destructeur          *****************************/

		Complexe();
		Complexe(const Complexe &arg);
		Complexe(double re,double im);// a faire un template

		~Complexe(){};

/************************                 Fonction                     *****************************/

        double modC(Complexe arg1);//=reel²+imaginaire² sert surtout pour comparer
        bool comparaison(double,double);// a faire un template

/************************                 Get Set                      *****************************/

            float getIm()const;            void  setIm(double Im);
            float getRe()const;            void  setRe(double poids);

            void setComplexe(double re,double im);// a faire un template

/************************                 Operateur  simple            *****************************/

        friend ostream& operator<<(ostream& os,const Complexe& aComplexe);

       Complexe operator + (Complexe &arg1);       Complexe operator - (Complexe &arg1);
       Complexe operator * (Complexe &arg1);       Complexe operator / (Complexe &arg1);
       Complexe operator = (const Complexe & Arg );

       //a voir pour en rajouter
       operator double();       operator int();       operator float();       operator long();

/************************     Operateur   operateur  avancer          *****************************/

       inline friend bool operator  == (const Complexe& left, const Complexe& right);
       inline friend bool operator  != (const Complexe& left, const Complexe& right);

/************************                 Test                        *****************************/
            void test_opetateur1()const;//test opetateur <<
            void test_opetateur2()const;//test opetateur ==
            void test_opetateur3()const;//test opetateur !=

           // test opetateur < > <= >= a faire
           //autre test a faire
};
#endif // Complexe_H_INCLUDED
