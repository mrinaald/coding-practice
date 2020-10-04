#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;

llong dot(const vector<llong> &x, const vector<llong> &y){
	return ((x[0]*y[0]) + (x[1]*y[1]) + (x[2]*y[2]));
}

llong norm2sq(const vector<llong> &x){
	return ((x[0]*x[0]) + (x[1]*x[1]) + (x[2]*x[2]));
}

double norm(const vector<llong> &x){
	return sqrt((x[0]*x[0]) + (x[1]*x[1]) + (x[2]*x[2]));
}

vector<llong> diff(const vector<llong> &x, const vector<llong> &y){
	vector<llong> ans(3);
	for(int i=0; i<3; ++i){
		ans[i] = x[i] - y[i];
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);

	cout.precision(10);

	int t, i;
	llong z;

	cin >> t;
	while(t--){
		vector<llong> P(3);
		vector<llong> Q(3);
		vector<llong> d(3);
		vector<llong> c(3);
		llong r;

		for(i=0; i<3; ++i){
			cin >> P[i];
		}
		for(i=0; i<3; ++i){
			cin >> Q[i];
		}
		for(i=0; i<3; ++i){
			cin >> d[i];
		}
		for(i=0; i<3; ++i){
			cin >> c[i];
		}
		cin >> r;

		vector<llong> x = diff(c, P);
		vector<llong> y = diff(Q, P);

		double sinT = r/norm(x);
		double h = norm(x) - (r*sinT);

		double m = ((r*r)*(1 - (sinT*sinT)))/(h*h);

		llong xnorm = norm2sq(x);

		double A = ((1+m)*dot(d,x)*dot(d,x)/double(xnorm)) - norm2sq(d);
		double B = 2*(((1+m)*dot(y,x)*dot(d,x)/double(xnorm)) - dot(y,d));
		double C = ((1+m)*dot(y,x)*dot(y,x)/double(xnorm)) - norm2sq(y);

		// llong A = (z*norm2sq(d)) - pow(dot(d,x), 2);
		// llong B = 2*(z*dot(y,d) - dot(y,x)*dot(d,x));
		// llong C = z*norm2sq(y) - pow(dot(y,x), 2);

		// cout << z << endl;
		// cout << A << endl;
		// cout << B << endl;
		// cout << C << endl;
		// cout << D << endl;
		// cout << ans1 << endl;
		// cout << ans2 << endl;

		if(A!=0){
			double D = sqrt(B*B - 4*A*C);
			double ans1 = ((-B) + D)/double(2*A);
			double ans2 = ((-B) - D)/double(2*A);

			if(ans1 <= 0.0)
				cout << fixed << ans2 << endl;
			else if(ans2 <= 0.0)
				cout << fixed << ans1 << endl;
			else if(ans1 < ans2)
				cout << fixed << ans1 << endl;
			else
				cout << fixed << ans2 << endl;
		}
		else{
			double ans = (-C)/(float(B));
			cout << fixed << ans << endl;
		}
	}

	return 0;
}
