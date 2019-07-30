#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

using namespace std;

const int size = 50;

char random_char()
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(33,126);	
	return char(dist(rng));
}

void fill_vec(vector<char> & coll)
{
	char item;
	while(coll.size()!=size)
	{
		item = random_char();
		if(!(find(coll.begin(), coll.end(), item) != coll.end()))
			coll.emplace_back(item);
		continue;
	}
}
void fill_map(map<char, char> & cip, map<char, char> & cip_rev, vector<char> coll, string let)
{
	for(int i = 0; i<size; i++)	
		cip.emplace(make_pair(let[i], coll[i]));	
	for(int i = 0; i<size; i++)	
		cip_rev.emplace(make_pair(coll[i], let[i]));
}

void encryption(map<char, char> cip, const string str, string & n_str)
{
	n_str=str;
	for(int i = 0; i<str.size(); i++)
	{
		auto search = cip.find(str[i]);
		if(search != cip.end())
			n_str[i]=search->second;
	}
}

void show(const vector<char> & coll)
{
	for(auto a : coll)
		cout<<a<<" ";
	cout<<endl;
}

void show(const map<char, char> & cip)
{
	for(auto a : cip)
		cout<<a.first<<" "<<a.second<<endl;
}
int main()
{
	string new_str;
	string result;
	vector<char> collection{};
	map<char, char> cipher;
	map<char, char> cipher_reverse;
	string letters = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ";

	fill_vec(collection);
	show(collection);
	
	fill_map(cipher,cipher_reverse, collection, letters);
	show(cipher);
	
	cout<<"Podaj zdanie do rozszyfrowania"<<endl;
	string words;
	getline(cin,words);
	
	cout<<"Encryption"<<endl;
	encryption(cipher, words, new_str);
	cout<<new_str<<endl;
	
	cout<<"Decryption"<<endl;
	encryption(cipher_reverse, new_str, result);
	cout<<result<<endl;

return 0;
}
