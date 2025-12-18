#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	int			i;
	string			t;
	string			inTxt;
	string			which_tokens;
	vector<string>		tokens;
	vector<unsigned int>	tokenIndexes;


	std::cout << "Implementing awk...\n";
	inTxt = "11 13";
	which_tokens = ".2 .1 .45 -1";

	stringstream ss(inTxt);
	while (getline(ss, t, ' '))
		tokens.push_back(t);
	stringstream ss2(which_tokens);
	while (getline(ss2, t, ' '))
	{
		i = -1;
		while (++i < t.size())
			t[i] = t[i + 1];
		cout << t << "\n";
		tokenIndexes.push_back(atoi(t.c_str()) - 1);	
	}
	i = -1;
	while (++i < tokenIndexes.size())
	{
		if (tokenIndexes[i] >= 0 && tokenIndexes[i] < tokens.size())
			cout << tokens[tokenIndexes[i]] << "\n";
	}
	return (0);
}
