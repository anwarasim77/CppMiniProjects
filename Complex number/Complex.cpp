#include <iostream>
#include <cmath>
using std::string;
using std::istream;
using std::ostream;
class Complex{

   public: double realNum;
   public: double imgNum;
   
public: 
   
   Complex(double real , double img){
      
      realNum=real;
      imgNum=img;
   }
   
   Complex(double real){
      
      realNum=real;
      imgNum=0;
   }
   
   friend Complex operator+(Complex a,Complex b);
   friend Complex operator-(Complex a,Complex b);
   friend Complex operator*(Complex a,Complex b);
   friend Complex operator/(Complex a,Complex b);
   
   friend Complex operator+(Complex a,double b);
   friend Complex operator-(Complex a,double b);
   friend Complex operator*(Complex a,double b);
   friend Complex operator/(Complex a,double b);
   
   friend Complex operator+(double a,Complex b);
   friend Complex operator-(double a,Complex b);
   friend Complex operator*(double a,Complex b);
   friend Complex operator/(double a,Complex b);
   
   
};
   
   Complex operator+(Complex a,Complex b){
      
      return Complex(a.realNum+b.realNum,a.imgNum+b.imgNum);
   }
   
   Complex operator-(Complex a,Complex b){
      
      return Complex(a.realNum-b.realNum,a.imgNum-b.imgNum);
   }
   
   Complex operator*(Complex a,Complex b){
      
      double one=a.realNum*b.realNum;
      double two=(a.realNum*b.imgNum)+(a.imgNum*b.realNum);
      double three=(a.imgNum*b.imgNum)*(-1);
      return Complex(one+three,two);
   }
   
   Complex operator/(Complex a,Complex b){
      Complex c= Complex(a.realNum,a.imgNum);
      Complex top=c*(Complex(b.realNum,-1*b.imgNum));
      Complex buttom=b*( Complex(b.realNum,-1*b.imgNum));
      return  Complex(top.realNum/buttom.realNum,top.imgNum/buttom.realNum);
   }
   
   Complex operator+(Complex a,double b){
      
      return  Complex(a.realNum+b,a.imgNum);
   }
   
   Complex operator-(Complex a,double b){
      
      return  Complex(a.realNum-b,a.imgNum);
   }
   
   Complex operator*(Complex a,double b){
      
      return  Complex(a.realNum*b,a.imgNum*b);
   }
   
   Complex operator/(Complex a,double b){
      
      return  Complex(a.realNum/b,a.imgNum/b);
   }
   
   Complex operator+(double a,Complex b){
   
      return Complex(a)+b;
   }
   
   Complex operator-(double a,Complex b){
   
      return Complex(a)-b;
   }
   Complex operator*(double a,Complex b){
   
      return Complex(a)*b;
   }
   Complex operator/(double a,Complex b){
   
      return Complex(a)/b;
   }
   
   std::ostream& operator<<(ostream& out, const Complex& c){
   
      if(c.realNum==0 && c.imgNum==0){
         out<< "0";
         return out;
      }
      else
         if(c.realNum!=0 && c.imgNum==0){
            out<<""<<c.realNum<<"";
            return out;
         }
         else
            if(c.realNum==0 && c.imgNum!=0){
               out<<""<<c.imgNum<<"i";
               return out;
            }
            else
               {
                  if(c.imgNum>0)
                     out<<""<<c.realNum<<" + "<<c.imgNum<<"i";
                  else
                     out<<""<<c.realNum<<" - "<<std::abs(c.imgNum)<<"i";
                  return out;
               }
               
   }

   
   int main(){
      
      Complex a= Complex(2.0,5.0);
      Complex b= Complex(1.0,6.0);
      
      std::cout<<"("<<a<<") + ("<<b<<") = "<<a+b<<std::endl;
      std::cout<<"("<<a<<") - ("<<b<<") = "<<a-b<<std::endl;
      std::cout<<"("<<a<<") * ("<<b<<") = "<<a*b<<std::endl;
      std::cout<<"("<<a<<") / ("<<b<<") = "<<a/b<<std::endl;
      std::cout<<"("<<a<<") + "<<2<<" = "<<a+2<<std::endl;
      std::cout<<"("<<a<<") - "<<2<<" = "<<a-2<<std::endl;
      std::cout<<"("<<a<<") * "<<2<<" = "<<a*2<<std::endl;
      std::cout<<"("<<a<<") / "<<2<<" = "<<a/2<<std::endl;
      std::cout<<3<<" + ("<<b<<") = "<<3+b<<std::endl;
      std::cout<<3<<" - ("<<b<<") = "<<3-b<<std::endl;
      std::cout<<3<<" * ("<<b<<") = "<<3*b<<std::endl;
      std::cout<<3<<" / ("<<b<<") = "<<3/b<<std::endl;
           
      return 0;        
   }
