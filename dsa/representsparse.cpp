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
    cout<<"\nSparse Matrix!";
 else
    cout<<"\nNot a Sparse Matrix";

  int x[nz][3],k=0;
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(mat[i][j]!=0)
        {
          x[k][0]=i;
          x[k][1]=j;
          x[k][2]=mat[i][j];
          k++;
        }
      }
    }
     cout << "\nSparse Matrix Representation:\n";
        for (int i = 0; i < nz; i++)
        {
            cout << x[i][0] << " " << x[i][1] << " " << x[i][2] << endl;
        }


 return 0;
}