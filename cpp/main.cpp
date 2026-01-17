/*

#Input is : python awk.py intxt "$1 $2 $3"
#Input is : python awk.py -stdin "$1 $2 $3"
#Input is : python awk.py -stdin "$1:$3" = $1 $2 $3
*/

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

// ./awk "t g b" ".1 .2 .3"

string getInTxt(char **av)
{
	string t;
	string content;
	string filename;

	if (av[1][0] == '-')
	{
		if (av[1] == string("-stdin"))
		{
			cout << "Reading Stdin...\n";
			while (getline(cin, t))
			{
				content += t;
			}
			cout << "Debug Content read:" << content << "\n";
			return (content);
		}
		else
		{
			try
			{
				filename = string(av[1]).substr(1);
				ifstream file(filename);
				cout << "Opening..." << filename << "\n";
				while (getline(file, t))
				{
					content += t;
				}
				cout << "debug content:" << content << ".\n";
				file.close();
				return (content);
			}
			catch(exception e)
			{
				cout << "Error stdin\n"; return "";
			}
		}
	}
	else
	{
		cout << "Else returning:" << av[1] << "\n";
		return (av[1]);
	}
}


void getIdx(char **av, vector<int> &idx)
{
		string t;
		stringstream ss(av[2]);
		idx.clear();
		while (getline(ss, t, ' '))
		{
			cout << "debug t:" << t << "\n";
			if (t.size() == 0 || t[0] != '.') continue;
			idx.push_back(stoi(t.substr(1)));
		}
}
	
string getOutput(const vector<int> &idx, const vector<string> &tokens)
{
	int i;
	string output;
		
	i = -1;
	while (++i < idx.size())
	{
		output += tokens[idx[i]] + " ";
//		cout << "debug output:" << output << "\n";
	}
	cout << "Output:" << output << "\n";
	return (output);
}

bool getTokens(vector<string> &tokens, const string inTxt)
{
	string t;
	stringstream ss(inTxt);

	if (inTxt.size() == 0) return (false);

	while (getline(ss, t, ' '))
		tokens.push_back(t);
	return (true);
}

void getIndexes(vector<int> &tokenIndexes, const string which_tokens)
{
	string t;
	stringstream ss(which_tokens);

	while (getline(ss, t, ' '))
	{
		t = t.substr(1); //remove -
		tokenIndexes.push_back(atoi(t.c_str()) - 1); //turn 1 into 0
	}
}

int main(int ac, char **av)
{
	string inTxt;
	vector<int> idx;
	vector<string> tokens;
	vector<int> tokenIndexes;

	if (ac != 3) {cout << "Usage: python3 " << av[0] << " 'input' '.1'\n -filename '.1' to read from file\n -stdin '.1' to read from stdin"; return (1);}
	if(!getTokens(tokens, getInTxt(av))) return (1);
	getIdx(av, idx);
	string output = getOutput(idx, tokens);
	cout << "output:" << output << "\n";
	return (0);
}
