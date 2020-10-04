#include <sstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct HRML
{
    string name;
    vector< string > att_name;
    vector< string > att_value;
    HRML *parent;
    vector< HRML* > child;
}*head;

void input(HRML **pnode, string str);
void Query(string str);
void print(HRML* node);

int main()
{
    std::ios::sync_with_stdio(false);

    head = new HRML;
    HRML *present_node;
    present_node = head;
    head->name = "head";

    int n, q;
    string str;
    stringstream ss;

    cin >> n >> q;
    char ch;
    cin.get(ch);
    
    for( int i=0; i<n; ++i)
    {
        getline(cin, str);
        // cout << str << '\n';
        input(&present_node, str);
    }

    for( int j=0; j<q; ++j)
    {
        getline(cin, str);
        
        Query(str);
    }

    return 0;
}

void input(HRML **pnode, string in)
{
    stringstream ss(in);
    char ch;
    string str;
    HRML* node = new HRML;

    // to extract the starting '<'
    ss.read(&ch, 1);
    
    // checking whether the tag is of starting HRML or end tag
    if( (char)ss.peek() != '/' )
    {
        ss >> str;
        
        // if the tag has no attributes
        if( ss.eof() )
        {
            // erasing the last '>'
            str.erase(str.size()-1, 1);
            node->name = str;
            (*pnode)->child.push_back(node);
            node->parent = *pnode;
            // print(node);
            *pnode = node;
            return;
        }
        else
        {
            node->name = str;
        }
        
        // reading the next whitespace for satisfying while condition
        ss.read(&ch, 1);
        while(ss.gcount())
        {
            ss >> str;
            node->att_name.push_back(str);
            ss.ignore(10,'\"');
            ss >> str;
            
            // if a whitespace is succeding, it means that there is 
            // another attribute in the tag
            if( ss.peek() == ' ' )
            {
                // deleting the last '\"'
                ss.read(&ch,1);
                str.erase(str.size()-1, 1);
                node->att_value.push_back(str);
            }
            else
            {
                // deleting the last '\"' and '>'
                str.erase(str.size()-2, 2);
                node->att_value.push_back(str);
                break;
            }
        }
        (*pnode)->child.push_back(node);
        node->parent = *pnode;
        // print(node);
        *pnode = node;
    }
    else
    {
        *pnode = (*pnode)->parent;
    }
    return;
}

void Query(string in)
{
    stringstream ss(in);
    string str;
    char arr[300];
    int flag = 0;
    string q_name;
    HRML *pnode, *cnode;
    pnode = head;

    // segmenting the query string till '~'
    ss.getline(arr, 300, '~');
    str = arr;
    // the string left in the stringstream is just the attribute name
    ss >> q_name;

    stringstream newss(str);

    // segmenting the newss at each '.'
    while(newss.getline(arr, 300, '.'))
    {
        str = arr;
        for(int i=0; i< (pnode->child.size()); i++)
        {
            cnode = pnode->child[i];
            if( str == cnode->name )
            {
                flag = 1;
                pnode = cnode;
                break;
            }
        }
        if(flag==1)
        {
            flag = 0;
        }
        else
        {
            cout << "Not Found!\n";
            return;
        }
    }

    for(int i=0; i< (pnode->att_name.size()); ++i)
    {
        if( q_name == pnode->att_name[i] )
        {
            cout << pnode->att_value[i] << '\n';
            return;
        }
    }
    cout << "Not Found!\n";

    return;
}

void print(HRML* node)
{
    cout << "----------\n";
    cout << '\"' <<node->name << '\"' << '\n';
    for(int i=0; i< node->att_name.size(); ++i)
    {
        cout << node->att_name[i] << '\n';
        cout << node->att_value[i] << '\n';
    }
    cout << node->parent->name << '\n';
    cout << "----------\n";
}