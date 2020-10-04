#include <iostream>
#include <vector>
using namespace std;

vector<short> add(vector<short> r, vector<short> a)
{
	if(r.size())
	{
		int carry=0;
		int temp;
		
		if( r.size() >= a.size() )
		{
			int i;
			for(i=0; i<a.size(); ++i)
			{
				temp = r[i] + a[i] + carry;
				r[i] = temp%10;
				carry = temp/10;
			}

			while(i<r.size())
			{
				temp = r[i] + carry;
				r[i] = temp%10;
				carry = temp/10;
				i++;
			}

			while(carry)
			{
				r.push_back(carry%10);
				carry /= 10;
			}
		}
		else
		{
			int i;
			for(i=0; i<r.size(); ++i)
			{
				temp = r[i] + a[i] + carry;
				r[i] = temp%10;
				carry = temp/10;
			}

			while(i<a.size())
			{
				temp = a[i] + carry;
				r.push_back(temp%10);
				carry = temp/10;
				i++;
			}

			while(carry)
			{
				r.push_back(carry%10);
				carry /= 10;
			}
		}
	}
	else
	{
		for(int i=0; i<a.size(); ++i)
			r.push_back(a[i]);
	}
	return r;
}

vector<short> multiply(vector<short> num, int n)
{
	int tens=1;
	vector<short> result;
	int temp;

	while(n)
	{
		short unit = (n%10)*tens;
		short carry = 0;
		vector<short> ans;
	
		for(int i=0; i<num.size(); ++i)
		{
			temp = (num[i]*unit)+carry;
			carry = temp/10;
			ans.push_back(temp%10);
		}

		while(carry)
		{
			ans.push_back(carry%10);
			carry /= 10;
		}

		result = add(result, ans);

		n /= 10;
		tens *=10;
	}

	return result;
}

void factorial(int n)
{
	vector<short> num(1);
	num[0] = 1;

	for(int i=2; i<=n; ++i)
	{
		num = multiply(num, i);
	}

	for(int j=num.size()-1; j>=0; --j)
		cout << num[j];

	cout << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	factorial(n);

	return 0;
}