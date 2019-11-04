#include <iostream>
using namespace std;

void print (int (&array)[8][8]){
for (int r=0; r<8;r++){
   for (int col=0; col<8; col++){
      if((array[r][col]<10)){
         cout << " "<< array[r][col] << "  ";
      }
      else
         cout << array[r][col] << "  ";
   
   }
cout << "  " << endl;
}

}

bool cellcheck(int r,int c,int (&array)[8][8]){
   if (r<8 && r>=0 && c>=0 && c<8 && array[r][c]==0)
      return true;

   return false;
}

bool Knight(int row, int column, int (&array)[8][8], int count){

   if(count==8*8+1){
      return true;
   }

   if(cellcheck(row+2,column+1,array)){
      array[row+2][column+1]=count;
      
         if(Knight (row+2, column+1, array,count+1)){
            return true;
         }
         else
            array[row+2][column+1]=0;
         
   }
   
   if(cellcheck(row+1,column+2,array)){
      array[row+1][column+2]=count;
         if(Knight (row+1, column+2, array,count+1)){
            return true;
         }
         else
            array[row+1][column+2]=0;
   }
   
   if(cellcheck(row-1,column+2,array)){
      array[row-1][column+2]=count;
         if(Knight (row-1, column+2, array,count+1)){
            return true;
         }
         else
            array[row-1][column+2]=0;
   }
         
   if(cellcheck(row-2,column+1,array)){
      array[row-2][column+1]=count;
         if(Knight (row-2, column+1, array,count+1)){
            return true;
         }
         else
            array[row-2][column+1]=0;
   }
   
   if(cellcheck(row-2,column-1,array)){
      array[row-2][column-1]=count;
         if(Knight (row-2, column-1, array,count+1)){
            return true;
         }
         else
            array[row-2][column-1]=0;
         
   }

   if(cellcheck(row-1,column-2,array)){
      array[row-1][column-2]=count;
         if(Knight (row-1, column-2, array,count+1)){
            return true;
         }
         else
            array[row-1][column-2]=0;
   }         
   
   if(cellcheck(row+1,column-2,array)){
      array[row+1][column-2]=count;
         if(Knight (row+1, column-2, array,count+1)){
            return true;
         }
         else
            array[row+1][column-2]=0;
         
   } 
   
   if(cellcheck(row+2,column-1,array)){
      array[row+2][column-1]=count;
         if(Knight (row+2, column-1, array,count+1)){
            return true;
         }
         else
            array[row+2][column-1]=0;
   }
         
   return false;

}

int main(){

int count=1;
int array [8][8];

for (int r=0; r<8;r++){
   for (int col=0; col<8; col++){
      array[r][col]=0;
   }
}


array[0][0]=count;
Knight(0,0,array,count+1);
print (array);
return 0;
}
