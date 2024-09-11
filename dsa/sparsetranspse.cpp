#include<iostream>
using namespace std;

int main()
{
 int r,c,count=0,nz=0;
 cout<<"Enter the number of rows and columns: ";
 cin>>r>>c;

 int mat[r][c];
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
    cout<<"Enter the element at position ["<<i<<"]["<<j<<"] : ";
    cin>>mat[i][j];
  }
 }

 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   cout<<mat[i][j]<<" "; 
  }
  cout<<endl;
 }

 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
    if(mat[i][j]==0)
      count++;
    else
      nz++;
  }
 }

 if(count>(r*c)/2)
    cout<<"\nSparse Matrix!"<<endl;
 else
    cout<<"\nNot a Sparse Matrix"<<endl;

   int s[nz][3],k=0;
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(mat[i][j]!=0)
        {
          s[k][0]=i;
          s[k][1]=j;
          s[k][2]=mat[i][j];
          k++;
        }
      }
    }
     cout << "\nSparse Matrix Representation:\n";
        for (int i = 0; i < nz; i++)
        {
            cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
        }
 
      int trans[nz][3]; 

    
    for (int i = 0; i < nz; i++) 
    {
        trans[i][0] = s[i][1]; 
        trans[i][1] = s[i][0]; 
        trans[i][2] = s[i][2]; 
    }

    
    cout << "\nTranspose of Sparse Matrix (Row, Column, Value):\n";
    for (int i = 0; i < nz; i++) 
    {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }
 return 0;
}