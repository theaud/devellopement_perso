#ifndef Complexe_H_INCLUDED
#define Complexe_H_INCLUDED

#include "include.h"


class Complexe
{
private :         double _re;                                         double _im;
public :
/************************            Constructeur Destructeur          *****************************/

		Complexe();

		Complexe(const Complexe&);
		Complexe(double re=0,double im=0);// a faire un template

        Complexe(int re,int im);
        Complexe(float re,float im);
        //template<typename Type1, typename Type2>  Complexe(Type1 operande1, Type2 operande2);



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

       //Complexe operator+ (Complexe &arg1);
       Complexe operator+  (Complexe &Arg){ _re =_re +Arg._re; _im =_im + Arg._im;return *this;}
      /* Complexe operator- (Complexe &arg1);
       Complexe operator* (Complexe &arg1);
       Complexe operator/ (Complexe &arg1);
       Complexe operator= (const Complexe & Arg );

*/

// operateur + - * /

Complexe operator - (Complexe &Arg){_re = _re - Arg._re;_im = _im - Arg._im;return *this;}
Complexe operator * (Complexe &Arg){_re = (_re*Arg._re)-(_im*Arg._im);_im = Arg._re*_im + _re*Arg._im;return *this;}
Complexe operator / (Complexe &Arg)
        {_re =_re*Arg._re+_im*Arg._re/(_im*_im+Arg._im*Arg._im);
        _im =Arg._re*_im-_re*Arg._im/(_im*_im+Arg._im*Arg._im);
        return *this; }

// operateur =
Complexe operator = (const Complexe & Arg ){ _re = Arg._re; _im = Arg . _im ;return  * this ; }

       //a voir pour en rajouter
       operator double();       operator int();       operator float();       operator long();

/************************     Operateur   operateur  avancer          *****************************/

       inline friend bool operator== (const Complexe& left, const Complexe& right);
       inline friend bool operator!= (const Complexe& left, const Complexe& right);

/************************                 Test                        *****************************/
            void test_opetateur1()const;//test opetateur <<
            void test_opetateur2()const;//test opetateur ==
            void test_opetateur3()const;//test opetateur !=

           // test opetateur < > <= >= a faire
           //autre test a faire
};





///*************************************************************************************************************************
///*************************************************************************************************************************
///*************************************************************************************************************************
///***********************************************  cpp   ********************************************************************
///*************************************************************************************************************************
///*************************************************************************************************************************
///*************************************************************************************************************************










#endif // Complexe_H_INCLUDED


