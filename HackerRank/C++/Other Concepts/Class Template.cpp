#include <iostream>
#include <string>

using namespace std;

template <class T>
class AddElements
{
    T elem;
    public:
        AddElements(T arg)
        {
            elem = arg;
        }
        
        T add(T arg)
        {
            return elem+arg;
        }
};

// class template specialization:
template <>
class AddElements <string>
{
    string element;
    public:
        AddElements (string arg) {element=arg;}
        string concatenate(string str)
        {
            return element+str;
        }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
