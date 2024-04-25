#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}
};
vector<string> splitPhrase(const string& String)
{
	vector <string> words;
	string word;
	char c;
	int i;
	for (i = 0; i < String.size(); i++)
	{
		c = String[i];
		if (c == ' ' | c == ',' || c == '?' || c == '!' || c == '.')
		{
			if (!word.empty())
			{
				words.push_back(word);
				word.clear();
			}
		}
			else
				word += c;
	}
	if (!word.empty())
	{
		words.push_back(word);
		word.clear();
	}
	return words;
}

void countWords(const vector<string>& words, map<string, int>& wordCounts)
{
	int i, j;
	for (i = 0; i < words.size(); i++)
	{
		string lower = words[i];
		for (j = 0; j < lower.size(); j++)
			if (lower[j] >= 'A' && lower[j] <= 'Z')
				lower[j] = lower[j] -'A' + 'a';
		wordCounts[lower] += 1;
	}
}

int main()
{
	string myString;
	ifstream myFile("input.txt");
	if (!myFile)
	{
		printf("error la deschiderea fisierului: input.txt");
		return 0;
	}
	if (!getline(myFile, myString)) {
		printf("error la citirea din fisier: input.txt");
		return 0;
	}
	
	vector<string> words = splitPhrase(myString);
	
	map<string, int> wordCounts;
	countWords(words, wordCounts);

	for (auto mapIterator = wordCounts.begin(); mapIterator != wordCounts.end(); mapIterator++) 
		printf("caracterul: %s apare de %d ori\n", mapIterator->first.c_str(), mapIterator->second);

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> Queue1;
	for (auto mapIterator = wordCounts.begin(); mapIterator != wordCounts.end(); mapIterator++)
		 Queue1.push(pair<string, int>(mapIterator->first, mapIterator->second));

	cout << '\n';

	while (!Queue1.empty())
	{
		cout << Queue1.top().first << " => " << Queue1.top().second << '\n';
		Queue1.pop();
	}
}