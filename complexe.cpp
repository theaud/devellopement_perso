#include <iostream> // pour les surcharges des operateurs d'E/S

#include "complexe.h"

/***************************************************************************************************/
/***************************************************************************************************/
/************************                 Fonction                     *****************************/
/***************************************************************************************************/
/***************************************************************************************************/

double modC(Complexe arg1)//=reel²+imaginaire² sert surtout pour comparer
        {return arg1.getRe()*arg1.getRe()+arg1.getIm()*arg1.getIm();}

bool comparaison(double arg1,double arg2){if(arg1>arg2){return 1;}return 0;}





/***************************************************************************************************/
/***************************************************************************************************/
/************************                 Constructeur                 *****************************/
/***************************************************************************************************/
/***************************************************************************************************/

Complexe::Complexe(){this->_re=0.0;this->_im=0.0;}
Complexe::Complexe(double re,double im){this->_re=re;this->_im=im;}


template<class Type> Complexe::Complexe(Type re, Type im)
{this->_re=(double)re;this->_im=(double)im;}

// constructeur par recopie,l’objet source est protégé par const
Complexe::Complexe(const Complexe &arg){this->_re=arg.getRe();this->_im=arg.getIm();}


/***************************************************************************************************/
/***************************************************************************************************/
/************************                 Operateur                    *****************************/
/***************************************************************************************************/
/***************************************************************************************************/

//opérateur de conversion vers un double ;retourne la partie reel  =perte partiel d'information mais peu tj etre utile
Complexe::operator double()    {return (double)_re; }
Complexe::operator int()       {return (int)   _re; }
Complexe::operator float()     {return (float) _re; }
Complexe::operator long()      {return (long)  _re; }

// operateur + - * /
Complexe Complexe::operator + (Complexe &Arg){ _re =_re +Arg._re; _im =_im + Arg._im;return *this;}
Complexe Complexe::operator - (Complexe &Arg){_re = _re - Arg._re;_im = _im - Arg._im;return *this;}
Complexe Complexe::operator * (Complexe &Arg){_re = (_re*Arg._re)-(_im*Arg._im);_im = Arg._re*_im + _re*Arg._im;return *this;}
Complexe Complexe::operator / (Complexe &Arg){_re =_re*Arg._re+_im*Arg._re/(_im*_im+Arg._im*Arg._im);
        _im =Arg._re*_im-_re*Arg._im/(_im*_im+Arg._im*Arg._im);return *this; }

// operateur =
Complexe Complexe::operator = (const Complexe & Arg ){ _re = Arg._re; _im = Arg . _im ;return  * this ; }

/***************************************************************************************************/
// operateur <<
ostream& operator<<(ostream& os,const Complexe& aComplexe){
if(aComplexe.getRe()==0.0 && aComplexe.getIm()==0.0)        {os<<" 0 ";}
        else if (aComplexe.getIm()==0.0)                    {os<<" "<<aComplexe.getRe();}
        else if (aComplexe.getRe()==0.0)                    {os<<" "<<aComplexe.getIm()<<"i ";}
        else if (aComplexe.getIm()>0.0)                     {os<<" "<< aComplexe.getRe() <<"+"<< aComplexe.getIm()<<"i ";}
        else if (aComplexe.getIm()<0.0)                     {os<<" "<< aComplexe.getRe() << aComplexe.getIm()<<"i ";}
        else                                                {os <<" Blabla 1";}
  return os;}

/***************************************************************************************************/
 inline bool operator==(const Complexe& left, const Complexe& right)
  {return (left._im == right._im)&& (left._re == right._re);}

 inline bool operator!=(const Complexe& left, const Complexe& right)
    {return !operator==(left,right);}
/***************************************************************************************************/
// on compare les 2 modes
inline bool operator< (const Complexe& left, const Complexe& right){return !comparaison(modC(left),modC(right));}
inline bool operator> (const Complexe& left, const Complexe& right){return comparaison(modC(left),modC(right));}
inline bool operator<=(const Complexe& left, const Complexe& right){return operator<(left,right)||operator==(left,right);}
inline bool operator>=(const Complexe& left, const Complexe& right){return operator>(left,right)||operator==(left,right);}

/***************************************************************************************************/
/***************************************************************************************************/
/************************                 Get Set                      *****************************/
/***************************************************************************************************/
/***************************************************************************************************/


void Complexe::setComplexe(double re,double im){ _re=re;_im=im;}

float Complexe::getRe()const{return _re;}
void Complexe::setRe(double reel){ _re=reel;}

float Complexe::getIm()const{return _im;}
void Complexe::setIm(double imaginaire){ _im=imaginaire;}


/***************************************************************************************************/
/***************************************************************************************************/
/************************                 fonction de test             *****************************/
/***************************************************************************************************/
/***************************************************************************************************/

//test operateur
void Complexe::test_opetateur1()const
{
        int i;
       Complexe a[9];

         a[0].setComplexe(0.0,0.0);
         a[1].setComplexe(0.0,1.0);a[2].setComplexe(0.0,-1.0);
         a[3].setComplexe(1.0,0.0);a[4].setComplexe(-1.0,0.0);

         a[5].setComplexe(1.0,1.0);a[6].setComplexe(1.0,-1.0);
         a[7].setComplexe(-1.0,1.0);a[8].setComplexe(-1.0,-1.0);

   cout <<"------------------------------------------"<<endl;
   for(i=0;i<9;i++){cout<<a[i]<<endl;}
   cout <<"------------------------------------------"<<endl;

}

void Complexe::test_opetateur2()const
{    Complexe a[3];

         a[0].setComplexe(0.0,0.0);
         a[1].setComplexe(0.0,1.0);
         a[2].setComplexe(1.0,0.0);
    cout <<"------------------------------------------"<<endl;
    cout <<" test 1 == "<<(bool) (a[0]==a[0])<<endl;
    cout <<" test 2 == "<<(bool) (a[0]==a[1])<<endl;
    cout <<" test 3 == "<<(bool) (a[1]==a[1])<<endl;
    cout <<" test 4 == "<<(bool) (a[2]==a[1])<<endl;
    cout <<" test 5 == "<<(bool) (a[1]==a[2])<<endl;
    cout <<"------------------------------------------"<<endl;
}

void Complexe::test_opetateur3()const
{
    Complexe a[3];

         a[0].setComplexe(0.0,0.0);
         a[1].setComplexe(0.0,1.0);
         a[2].setComplexe(1.0,0.0);

    cout <<"------------------------------------------"<<endl;
    cout <<" test 1 == "<<(bool) (a[0]!=a[0])<<endl;
    cout <<" test 2 == "<<(bool) (a[0]!=a[1])<<endl;
    cout <<" test 3 == "<<(bool) (a[1]!=a[1])<<endl;
    cout <<" test 4 == "<<(bool) (a[2]!=a[1])<<endl;
    cout <<" test 5 == "<<(bool) (a[1]!=a[2])<<endl;
    cout <<"------------------------------------------"<<endl;

}
