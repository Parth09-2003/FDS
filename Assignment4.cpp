
#include <iostream>
using namespace std;
class matrix {
public:
  int r;
  int c;
  int count = 0;
  int mat[5][5];
  matrix(int row, int col) {
    r = row;
    c = col;
    int i, j;
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        cout << "Enter Element [" << i << "][" << j << "]:";
        cin >> mat[i][j];
        if (mat[i][j] != 0) {
          count = count + 1;
        }
      }
    }
  }

};
class sparse {
public:
  int s[10][3];
  int row, col, values;
  sparse() {}
  sparse(int r, int c) {
    row = r;
    s[0][0] = r;
    col = c;
    s[0][1] = c;
  }
  sparse(matrix A) {
    row = A.r;
    col = A.c;
    values = A.count;
    s[0][2] = values;
    s[0][0] = row;
    s[0][1] = col;
    int i, j;
    int count1 = 1;
    for (i = 0; i < A.r; i++) {
      for (j = 0; j < A.c; j++) {
        if (A.mat[i][j] != 0) {
          s[count1][0] = i;
          s[count1][1] = j;
          s[count1][2] = A.mat[i][j];
          count1 = count1 + 1;
        }
      }
    }
  }
  void dis() {
    cout << "Rows :" << row;
    cout << "\n";
    cout << "Cols :" << col;
    cout << "\n";
    cout << "Number of elements :" << values;
    cout << "\n";
    int i;
    cout<<"row\tcolumn\tvalue\n";
    for (i = 1; i <= values; i++)
      cout << "[" << s[i][0] << "]\t[" << s[i][1] << "]"
           << " :\t" << s[i][2] << "\n";
  }
};
sparse add(sparse a, sparse b) {
  int m, n;
  m = a.s[0][2];
  n = b.s[0][2];
  sparse c(a.s[0][0], a.s[0][1]);
  int i = 1, j = 1, k = 1;
  while (i <= m && j <= n) {
    if (a.s[i][0] == b.s[j][0]) {
      if (a.s[i][1] == b.s[j][1]) {
        c.s[k][0] = a.s[i][0];
        c.s[k][1] = a.s[i][1];
        c.s[k][2] = a.s[i][2] + b.s[i][2];
        i = i + 1;
        j = j + 1;
        k = k + 1;
      } else if (a.s[i][1] < b.s[j][1]) {
        c.s[k][0] = a.s[i][0];
        c.s[k][1] = a.s[i][1];
        c.s[k][2] = a.s[i][2];
        i = i + 1;
        k = k + 1;
      } else {
        c.s[k][0] = b.s[j][0];
        c.s[k][1] = b.s[j][1];
        c.s[k][2] = b.s[j][2];
        j = j + 1;
        k = k + 1;
      }

    } else if (a.s[i][0] < b.s[j][0]) {
      c.s[k][0] = a.s[i][0];
      c.s[k][1] = a.s[i][1];
      c.s[k][2] = a.s[i][2];
      i = i + 1;
      k = k + 1;
    } else {
      c.s[k][0] = b.s[j][0];
      c.s[k][1] = b.s[j][1];
      c.s[k][2] = b.s[j][2];
      j = j + 1;
      k = k + 1;
    }
  }
  while (i <= m) {
    c.s[k][0] = a.s[i][0];
    c.s[k][1] = a.s[i][1];
    c.s[k][2] = a.s[i][2];
    i = i + 1;
    k = k + 1;
  }
  while (j <= n) {
    c.s[k][0] = b.s[j][0];
    c.s[k][1] = b.s[j][1];
    c.s[k][2] = b.s[j][2];
    j = j + 1;
    k = k + 1;
  }
  c.s[0][2] = k - 1;
  c.values = k - 1;
  return c;
}
sparse simpletranspose(sparse a) {
  int row = a.s[0][0];
  int col = a.s[0][1];
  sparse b(col, row);
  b.values = a.values;
  int i, j, k;
  i = 1;
  for (j = 0; j < col; j++) {
    for (k = 1; k <= a.values; k++) {
      if (a.s[k][1] == j) {
        b.s[i][0] = a.s[k][1];
        b.s[i][1] = a.s[k][0];
        b.s[i][2] = a.s[k][2];
        i = i + 1;
      }
    }
  }
  return b;
}
sparse fasttranspose(sparse a)
{
  int row = a.s[0][0];
  int col = a.s[0][1];
  int freq[col];
  int rowstartpos[col];
  sparse b(col, row);
  b.s[0][0] = col;
  b.s[0][1] = row;
  b.s[0][2] = a.s[0][2];
  b.values=a.s[0][2];
  int i, k, temp;

  for (i = 0; i < col; i++)
  {
    freq[i] = 0;
  }

  for (k = 1; k <= a.s[0][2]; k++)
  {
    temp = a.s[k][1];
    freq[temp]++;
  }

  rowstartpos[0] = 1;
  for (i = 1; i < col; i++)
  {
    rowstartpos[i] = rowstartpos[i - 1] + freq[i - 1];
  }

  for (i = 1; i <= a.s[0][2]; i++)
  {
    k = rowstartpos[a.s[i][1]];
    b.s[k][0] = a.s[i][1];
    b.s[k][1] = a.s[i][0];
    b.s[k][2] = a.s[i][2];
    rowstartpos[a.s[i][1]]++;
  }

  return b;
}

using namespace std;
int main() {
  int row,col,choice; 
  cout<<"Enter choice\n1.Display sparse matrix\n";
  cout<<"2.Add two sparse matrices\n";
  cout<<"3.Find transpose using Simple transpose algorithm\n";
  cout<<"4.Find transpose using Fast transpose algorithm\n";
  cin>>choice;
  sparse sum,fa,sl; 
  switch(choice)
    {
      case 1:
      {
        cout<<" matrix :\n";
        cout<<"Enter number of rows :";
        cin>>row; 
        cout<<"Enter number of cols :";
        cin>>col;
        cout<<"Enter 1st matrix :\n";
        matrix A1(row,col);
        sparse mat1(A1);
        mat1.dis();
        break;
      }
      case 2:
      {
        cout<<"Enter number of rows :";
        cin>>row; 
        cout<<"Enter number of cols :";
        cin>>col;
        cout<<"Enter 1st matrix :\n";
        matrix A1(row,col);
        sparse mat1(A1);
        cout<<"Enter 2nd matrix";
        matrix A2(row,col);
        sparse mat2(A2);
       // sparse c;
        sum=add(mat1,mat2);
        sum.dis();
        break;
      }
      case 3:
      {
        cout<<"Enter number of rows :";
        cin>>row; 
        cout<<"Enter number of cols :";
        cin>>col;
        cout<<"Enter  matrix :\n";
        matrix A1(row,col);
        sparse mat1(A1);
        fa=simpletranspose(mat1);
        fa.dis();
        break;
      }
      case 4:
      {
        cout<<"Enter number of rows :";
        cin>>row; 
        cout<<"Enter number of cols :";
        cin>>col;
        cout<<"Enter matrix :\n";
        matrix A1(row,col);
        sparse mat1(A1);
        sl=fasttranspose(mat1);
        sl.dis();
        break;
      }
    }
  return 0;
}


