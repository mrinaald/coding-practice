#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct Ingredient {
    llong n = 0;
    llong p = 0;
    llong required = 0;
    llong units = 0;
    llong spare = 0;
    llong price_per_unit = 0;
};


bool my_comparator(const Ingredient& lhs, const Ingredient& rhs) {
    return lhs.units <= rhs.units;
}

int main(){
    // - Use cin, cout for Faster I/O.
    // - Use cout << endl only when you want to flush the output forcefully
    // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Ingredient b, s, c;
    vector<Ingredient> ingredients;

    string burger;
    cin >> burger;

    int i, j;
    for (i=0; i<burger.length(); ++i) {
        switch(burger[i]) {
        case 'B': b.required++; break;
        case 'S': s.required++; break;
        case 'C': c.required++; break;
        }
    }

    cin >> b.n >> s.n >> c.n;
    cin >> b.p >> s.p >> c.p;

    llong r;
    cin >> r;

    if (b.required > 0) {
        ingredients.pb(b);
    }
    if (s.required > 0) {
        ingredients.pb(s);
    }
    if (c.required > 0) {
        ingredients.pb(c);
    }

    if (ingredients.size() <= 0) {
        cout << 0 << endl;
        return 0;
    }

    for (i=0; i<ingredients.size(); ++i) {
        ingredients[i].units = (ingredients[i].n / ingredients[i].required);
        ingredients[i].spare = (ingredients[i].n % ingredients[i].required);
        ingredients[i].price_per_unit = ingredients[i].required * ingredients[i].p;
    }

    sort(all(ingredients), my_comparator);

    llong total_burgers = 0;
    llong unit_price;
    llong x;
    for (i=0; i<ingredients.size(); ++i) {
        unit_price = 0;
        for (j=0; j<i; ++j) {
            unit_price += ingredients[j].price_per_unit;
        }

        if (unit_price > 0) {
            x = r / unit_price;
            x = min(x, ingredients[i].units);
            r -= (x * unit_price);
        } else {
            x = ingredients[i].units;
        }
        total_burgers += x;

        for (j=i; j<ingredients.size(); ++j) {
            ingredients[j].units -= x;
        }

        if (ingredients[i].units > 0) {
            break;
        }
    }

    if (r > 0) {
        // Adjusting Spare ingredients
        x = (ingredients[0].required - ingredients[0].spare) * ingredients[0].p;
        for (i=1; i<ingredients.size(); ++i) {
            if (ingredients[i].units > 0) {
                break;
            }
            x += ((ingredients[i].required - ingredients[i].spare) * ingredients[i].p);
        }

        if (x <= r) {
            total_burgers++;
            r -= x;
            for (i=1; i<ingredients.size(); ++i) {
                if (ingredients[i].units > 0) {
                    ingredients[i].units--;
                }
            }
        }

        // See whether we can buy all ingredients to make more hamburgers
        x = 0;
        for (i=0; i<ingredients.size(); ++i) {
            if (ingredients[i].units > 0) {
                break;
            }
            x += ingredients[i].price_per_unit;
        }

        if (i == ingredients.size()) {
            // all units == 0 and r > 0
            total_burgers += (r / x);
        }
    }

    cout << total_burgers << endl;

    cout << std::flush;
    return 0;
}
