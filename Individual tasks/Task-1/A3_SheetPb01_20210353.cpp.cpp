#include<iostream>
#include<vector>
#include<fstream>
using namespace std;



vector<string>dictionary;
bool done;
void fill_dictionary()
{
    ifstream file;
    string word;
    file.open("dictionary.txt");
    while (! file.eof())
    {
        file>>word;
        dictionary.push_back(word);
    }
}


bool found(string word)
{
    for(string m:dictionary)
    {
        if (word == m)
        {
            return true;
        }
    }
    return false;
}
bool seperate(string text , int depth , string& s)
{    
    string word;
    if (depth == text.length())
    {
        return true;
    }
    
    for (int i = depth; i < text.length(); i++)
    {
        word.push_back(text[i]);
        if (found(word))
        {
            s+=word;
            s+=" ";
            if (seperate(text,i+1,s)) // i wear my shoes   // i wear my 
            {
                return true;
            }
            s.erase(s.end()-word.size()-1,s.end());
        }
    }
    return false;
}

int main()
{
    fill_dictionary(); 
    string s;
    string tst = "iwearmyshoes";
    seperate(tst,0,s);
    cout<<s;
}