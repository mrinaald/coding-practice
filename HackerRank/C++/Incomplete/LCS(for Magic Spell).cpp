#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(string str1, string str2);

int main()
{
	// string str1 = "eAquaVitaeztflm";
	// string str2 = "efAadkgfAruTaVaey";		//Ans : eAuaVae
	// string str1 = "AquaVitae";
	// string str2 = "AruTaVae";
	string str1 = "qrygahGtxCsJEJaIOQSPJDtWrvZQzdHEQxeEqLdGfRfUOVToUTFpvbICYDnhoOCRPdDRSNdQQQxZrRMjRllzGvxHRIVzfdvbMXOvNNUgGptoCAWBlEQLjnkbeyctSivOtTJnoTfBrhneRLlSRLObhEITIKnbTTWyzGPMLEytSUYKBZhenpbGRuCDBWeSGfQKHKeSSzpWTLQIyaGsZgMJHsPLDjSRxkprgsqOQJTdekJJHkgNqXtzGXVCdSfMKmtpOMzjaqWSQoNHdAHBipgEgGtlTRzDBiUAFjuZPlZpvIkNrJrMpMQcqODUhRZvokBwtnTdQfzZlyBcWRbpwDefDPXDvbyDxXuIrFtNFvtzVcUyCQhZBKUWpjBWxFMwYshVBSkjplUDzUKmiDrYuliEJFJkYZjozGwbpkkbRrGZbcqEjVeyKoTOaLWOXRtBjGliCoyTRqIwNeAARnjLNnXPVpGouHxqfDdJYjydQtGCmwhTwBMiLySvOEHGJOswpGkCrPnAzdoxRcsInWeAwRZqkojTApMVKqCzYCdwORimVwSTuqZBNgYoIwwcnGZfGULQpmRyQawksnehLnEpobGyCpjZrsVGALzDshulaDlZJdxhgmtTfWjrxmEmPebINYuWcOEtImTXZZqvFFrhZBoAabXrGugTcyzfZsMfVvwneJZoEAJZGwIPhmcLyHmyjOsbPZZOmPWVSMTCXmBLaPbWJAnzfdhhXczReAQivivczqzMvEtNOe";
	string str2 = "HEWgReGyQkgqxcVwBZhvDasxXYvPbTLDZmpiGnrhCtCvVGyExpXaatOlHgUXbGbZVWwkEzcPopzpOjOhyaJLPcOrYltUfLRGLEcpbinaxdRgZpWofyUdM";

	if(str1.length() > str2.length())
	{
		cout << LCS(str1, str2) << '\n';
	}
	else
	{
		cout << LCS(str2, str1) << '\n';
	}

	return 0;
}

int LCS(string str1, string str2)
{
	// assuming str1.length() > str2.length()
	int len1 = str1.length();
	int len2 = str2.length();

	vector<int> column;
	int row[len2];

	int i, j;

	for(i=0; i<len2; i++)
	{
		row[i] = -1;

		for(j=0; j<len1; ++j)
		{
			if( str2[i] == str1[j] )
			{
				column.push_back(j);
				if( row[i] == -1 )
					row[i] = column.size()-1;
			}
		}
	}

	// for(i=0; i<len2; ++i)
	// 	cout << row[i] << ' ';

	// cout << '\n';

	// return column.size();

	int next_i, curr_i;
	int max=0;
	vector<int> lcs;
	
	for(i=0, curr_i=0, next_i=0; i<len2; i++, curr_i=next_i, next_i=i+1)
	{
		if( row[i] == -1 )
		{
			continue;
		}
		
		curr_i = row[i];
		
		if( i == len2-1 )
			next_i = column.size();
		else
		{
			int k=i+1;
			next_i = row[k];
			while( (next_i<len2) && (row[k]==-1) )
				k++;


			if( k >= len2 )
				next_i = column.size();
			else
				next_i = row[k];
		}
// cout << "curr=" << curr_i << " next=" << next_i << ", ";
		for(j=curr_i; j<next_i; ++j)
		{
			if( lcs.size() )
			{
				if( lcs[lcs.size()-1] < column[j] )
				{
					lcs.push_back(column[j]);
					break;
				}
				else
				{
					if( j == next_i-1 )
					{
						int tempmax = lcs.size();

						if( tempmax > max)
							max = tempmax;

						while( lcs[lcs.size()-1] > column[j] )
							lcs.pop_back();

						lcs.push_back(column[j]);
						break;
					}
				}
			}
			else
			{
				lcs.push_back(column[j]);
				break;
			}
		}
	}
	if( lcs.size() < max )
		return max;
	else
		return lcs.size();
}