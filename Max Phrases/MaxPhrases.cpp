#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

void getall(std::map<string,int> &F)
{
   int max=0;
   int maxC=0;
   
   for (std::map<string,int>::iterator it=F.begin(); it!=F.end(); ++it)
   {    
      if(F[it->first]>max)
         max=F[it->first];
   }
   
   for (std::map<string,int>::iterator it=F.begin(); it!=F.end(); ++it)
   {    
      if(F[it->first]==max)
         maxC++;
   }
   
   if(maxC==F.size() && maxC!=1)
      cout<< "ALL PHRASES EQUALLY FREQUENT"<<"\n";
   else
   {
      for (std::map<string,int>::iterator it=F.begin(); it!=F.end(); ++it)
      {    
            cout << it->first << " " << it->second << "\n";
      }
   }
   
}


void getTop(std::map<string,int> &F)
{
   int max=0;
   int maxC=0;
   
   for (std::map<string,int>::iterator it=F.begin(); it!=F.end(); ++it)
   {    
      if(F[it->first]>max)
         max=F[it->first];
   }
   
   for (std::map<string,int>::iterator it=F.begin(); it!=F.end(); ++it)
   {    
      if(F[it->first]==max)
         maxC++;
   }
   
   if(maxC==F.size())
      cout<< "ALL PHRASES EQUALLY FREQUENT"<<"\n";
   else
   {
      for (std::map<string,int>::iterator it=F.begin(); it!=F.end(); ++it)
      {    
         if(F[it->first]==max)
            cout << it->first << " " << it->second << "\n";
      }
   }
   
}

string Lcase(std::string S)
{
   std::string L=S;
   for(int c=0;c<S.length();c++)
   {   L[c]=tolower(S[c]);}
   
   return L;
}


bool CM(std::string S)
{
   if(S=="all" || S=="top")
      return true;
   else
      return false;
}

bool intcheck(std::string S)
{  
   bool b;     
   for(int c=0;c<S.length();c++)
   {
      if(S[c]>='0' && S[c]<='9')
         b=true;
      else
         {  b=false;
            return b;
         }
          
   }
   return b;
}

//00000000000000000000000000000000000000000000000
int main(int argLength, char *CL[])
{  
   int N=0;
   bool twc;
   int wordC=0;
   std::vector<std::string> array;
   std::vector<std::string> array2;
   std::string word;
   std::map<string,int> Freq;
   //std::map<string,int> MaxFreq;
   
   
   std::string Mode;
   ifstream infile;
   if (argLength<=1)
   {
      cerr << "NO PHRASE LENGTH\n";
      return 0;
   }
//---------------------------------   
   bool intch=intcheck(CL[1]);
   if(intch==true && stoi(CL[1])>0)
      N=stoi(CL[1]);
   else
      {cerr << "INVALID PHRASE LENGTH\n";
      return 0;}
//----------------------------------
   if (argLength<3)
   {
   cerr << "NO MODE\n";
   return 0;
   }
   
   if(CM(CL[2]))
      Mode=CL[2];
   else   
      {
      cerr << "INVALID MODE\n";
      return 0;
      } 
//----------------------------------
   if (argLength<4)
   {
   cerr << "NO FILES GIVEN\n";
   return 0;
   }
   
for(int cc=3;cc<argLength;cc++)
{
   infile.open(CL[cc]);
   if( infile.is_open() == false ) {
   cerr << "BAD FILE "<<CL[cc]<<"\n";
   }
   infile.close();
}
//----------------------------------

//ifstream infile;

for(int cf=3;cf<argLength;cf++)
{  
      wordC=0;
      twc=true;
      infile.open(CL[cf]);
      infile >> word;
      
      if(!(word==" ") && !(word=="") && !(word=="\0"))
      {
         infile.close();
               
         infile.open(CL[cf]);
         infile >> word;
         
         while (!(infile.eof()) && !(word==" ") && !(word=="") && !(word=="\0") )
         {  
            if(!(infile.eof()) && !(word==" ") && !(word=="") && !(word=="\0") )
            {   
               wordC++;
               infile >> word;
            }
               
         }
         if(wordC==0)
            wordC=1;
      }


      if(wordC>=N)
         twc=true;
      else
         twc=false;
      
      infile.close();
      infile.open(CL[cf]);
      
      if(twc == true)
      {  

         for (int x=0;x<wordC;x++)
         {  
             infile >> word;
             array.push_back(Lcase(word)); 
         }

 //--make phrase     
   for(int c=0;c<=array.size()-N;c++)
   {  
      array2.push_back(" ");
      array2[c]="";
      for(int r=c;r<c+N;r++)
      {
         array2[c]+=array[r];
         if(!(r==(c+N-1)))
            array2[c]+=" ";
      }
     
   }
 //---make phrase
  
  
//mapin it 
      for(int nn=0;nn<array2.size();nn++)
      {
         Freq[array2[nn]]++;
      }
//-------------------------------------------------------

      if(Mode=="top")
      {
         getTop(Freq);
      }
      else
         getall(Freq);
      
       
      }
      else
      {   cout<<"NO PHRASES"<<"\n";}
      
      
      Freq.clear();
      array2.clear();     
      array.clear();
      infile.close();
}
//------------------------------------------------------------------------------

return 0;
}