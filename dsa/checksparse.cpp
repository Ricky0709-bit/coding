#include<iostream>
using namespace std;

int main()
{
 int r,c,nz=0,count=0;
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

 cout<<"\n Matrix is:"<<endl;
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

 if(nz>(r*c)/2)
 {
    cout<<"\n Not a Sparse Matrix!";
 }
 else
 {
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
    }

    return 0;
}