#include <iostream>
#include <string>

using namespace std;

class Person
{
		string name;
		int age;
	public:
		virtual void getdata()
		{
			cin >> name;
			cin >> age;
		}

		virtual void putdata()
		{
			cout << name << ' ' << age << ' ';
		}
};

class Professor : public Person
{
		int publications;
		int curr_id;
		static int count;
	public:
		Professor()
		{
			count++;
			curr_id = count;
		}

		void getdata()	//overriding the Person::getdata()
		{
			Person::getdata();
			cin >> publications;
		}

		void putdata()	//overriding the Person::putdata()
		{
			Person::putdata();
			cout << publications << ' ' << curr_id << '\n';
		}
};

class Student : public Person
{
		int marks[6];
		int curr_id;
		static int count;
	public:
		Student()
		{
			count++;
			curr_id = count;
		}

		void getdata()
		{
			Person::getdata();
			for(int i=0; i<6; ++i)
				cin >> marks[i];
		}

		void putdata()
		{
			Person::putdata();
			int sum=0;

			for(int i=0; i<6; ++i)
				sum += marks[i];

			cout << sum << ' ' << curr_id << '\n';
		}
};

// static variables must be initialized before main()
int Professor::count = 0;
int Student::count = 0;

int main()
{
	std::ios::sync_with_stdio(false);
    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];
    
    for(int i = 0;i < n;i++)
    {
    	cin>>val;
        if(val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}