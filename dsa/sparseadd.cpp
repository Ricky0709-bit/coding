#include<iostream>
using namespace std;

int main()
{
 int r,c,nzx=0,nzy=0;
 cout<<"Enter the number of rows & columns:"<<endl;
 cin>>r>>c;

 int x[r][c];
 int y[r][c];
 
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
    {
        cout<<"Enter the element at position ["<<i<<"]["<<j<<"] of matrix x:"<<endl;
        cin>>x[i][j];
        if (x[i][j] != 0) 
            nzx++;
    }
 }

 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
    cout<<"Enter the element at position ["<<i<<"]["<<j<<"] of matrix y:"<<endl;
    cin>>y[i][j];
    if(y[i][j]!=0)
      nzy++;
  }
 }

 cout<<"\n Matrix x is:"<<endl;
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   cout<<x[i][j]<<" "; 
  }
  cout<<endl;
 }

 cout<<"\n Matrix y is:"<<endl;
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   cout<<y[i][j]<<" "; 
  }
  cout<<endl;
 }

 int s1[nzx][3],k1=0;
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(x[i][j]!=0)
        {
          s1[k1][0]=i;
          s1[k1][1]=j;
          s1[k1][2]=x[i][j];
          k1++;
        }
      }
    }
     cout << "\nSparse Matrix Representation:\n";
        for (int i = 0; i < nzx; i++)
        {
            cout << s1[i][0] << " " << s1[i][1] << " " << s1[i][2] << endl;
        }

 int s2[nzy][3],k2=0;
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(y[i][j]!=0)
        {
          s2[k2][0]=i;
          s2[k2][1]=j;
          s2[k2][2]=y[i][j];
          k2++;
        }
      }
    }
     cout << "\nSparse Matrix Representation:\n";
        for (int i = 0; i < nzy; i++)
        {
            cout << s2[i][0] << " " << s2[i][1] << " " << s2[i][2] << endl;
        }

  int i=0,j=0,k=0;
  int res[nzx+nzy][3];
  while(i<nzx && j<nzy)
  {
   if(s1[i][0]==s2[j][0])
   {
    if(s1[i][1]==s2[j][1])
    {
      res[k][0]=s1[i][0];
      res[k][1]=s1[i][1];
      res[k][2]=s1[i][2]+s2[j][2];
      i++;
      j++;
    }
    else if(s1[i][1]<s2[j][1])
    {
     res[k][0]=s1[i][0];
     res[k][1]=s1[i][1];
     res[k][2]=s1[i][2];
     i++;
    }
    else if(s1[i][1]>s2[j][1])
    {
      res[k][0]=s2[j][0];
      res[k][1]=s2[j][1];
      res[k][2]=s2[j][2];
      j++;
    }
   }
   else if(s1[i][0]<s2[j][0])
   {
    res[k][0]=s1[i][0];
    res[k][1]=s1[i][1];
    res[k][2]=s1[i][2];
    i++;
   }
   else if(s1[i][0]>s2[j][0])
   {
    res[k][0]=s2[j][0];
    res[k][1]=s2[j][1];
    res[k][2]=s2[j][2];
    j++;
   }
   k++;
  }

  if(i<nzx)
  {
   while(i<nzx)
   {
    res[k][0]=s1[i][0];
    res[k][1]=s1[i][1];
    res[k][2]=s1[i][2];
    i++;
    k++;
   }
  }

  if(j<nzy)
  {
   while(j<nzy)
   {
    res[k][0]=s2[j][0];
    res[k][1]=s2[j][1];
    res[k][2]=s2[j][2];
    j++;
    k++;
   }
  }

    res[0][0]=r;
    res[0][1]=c;
    res[0][2]=k-1;
  
  cout<<"\nSparse matrix addition is:"<<endl;
  
   for(int i=0;i<k;i++)
   {
    cout<<res[i][0]<<"\t"<<res[i][1]<<"\t"<<res[i][2]<<endl;
   }

  return 0;

}
