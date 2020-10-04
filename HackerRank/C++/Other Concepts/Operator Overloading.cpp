#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
    public:
        vector<vector<int> > a;

        Matrix& operator+(Matrix& rhs)
        {
            int i, j;
            Matrix *result;
            result = new Matrix;
			
            // "this" refers to the pointer to the variable of the Matrix using this operator
			for(i=0; i< this->a.size(); ++i)
			{
				vector<int> x;
				int n;
				for(j=0; j< this->a[i].size(); ++j)
				{
					n = this->a[i][j] + rhs.a[i][j];
					x.push_back(n);;
				}
				result->a.push_back(x);
			}
			return *result;
		}
};

// // The function of this type is defined outside the class
// Matrix& operator+(Matrix& lhs, Matrix& rhs)
// {
//     int i, j;
//     Matrix *result;
//     result = new Matrix;
//     for(i=0; i< lhs.a.size(); ++i)
//     {
//         vector<int> x;
//         int n;
//         for(j=0; j< lhs.a[i].size(); ++j)
//         {
//             n = lhs.a[i][j] + rhs.a[i][j];
//             x.push_back(n);;
//         }
//         result->a.push_back(x);
//     }
//     return *result;
// }

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}