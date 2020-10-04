#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ofstream fout("outLCS.txt");

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
    //  cout << row[i] << ' ';

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

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
            fout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
            fout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
            fout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
            fout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    Fireball *fb = dynamic_cast<Fireball *>(spell);
    if( fb != NULL )
    {
        fb->revealFirepower();
        return;
    }
    
    Frostbite *fbt = dynamic_cast<Frostbite *>(spell);
    if( fbt != NULL )
    {
        fbt->revealFrostpower();
        return;
    }
        
    Thunderstorm *ts = dynamic_cast<Thunderstorm *>(spell);
    if( ts != NULL )
    {
        ts->revealThunderpower();
        return;
    }

    Waterbolt *wb = dynamic_cast<Waterbolt *>(spell);
    if( wb != NULL )
    {
        wb->revealWaterpower();
        return;
    }

    string scroll = spell->revealScrollName();
    string counter = SpellJournal::read();

    if( scroll.length() > counter.length() )
    {
        int x = LCS(scroll, counter);
        cout << x << '\n';
        fout << x << '\n';
    }
    else
    {
        int x = LCS(counter, scroll);
        cout << x << '\n';
        fout << x << '\n';
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    fout.close();
    return 0;
}