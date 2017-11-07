//TLE
#include <bits/stdc++.h>
using namespace std;
string s[200001];
int maxind = 0, n;

struct TrieNode
{
	struct TrieNode * children[26];
	bool isEndofWord;
	int indexcount;
	int minpos;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pnode = new TrieNode;
	pnode -> isEndofWord = false;
	pnode -> indexcount = -1;
	pnode -> minpos = n;
	for(int i = 0; i < 26; i++)
		pnode->children[i] = NULL;
	return pnode;
}

void insert(struct TrieNode *root, string key, int indval)
{
	struct TrieNode *pcrawl = root;
	for(int i = 0; i < key.length(); i++)
	{
		int ind = key[i] - 'a';
		if(!pcrawl->children[ind])
			pcrawl->children[ind] = getNode();

		pcrawl = pcrawl->children[ind];
		pcrawl->indexcount = indval;
		pcrawl->minpos = min(pcrawl->minpos, indval);
	}
	pcrawl->isEndofWord = true;
}

void search(struct TrieNode *root, string key)
{
	struct TrieNode *pcrawl = root;
	int flag = 0;
	for(int i = 0; i < key.length(); i++)
	{
		int ind = key[i] - 'a';
		if(!pcrawl->children[ind])
		{
			//when there is no match or key is bigger
			for(int j = ind - 1; j >= 0; j--)
			{
				if(pcrawl -> children[j])
				{
					maxind = pcrawl->children[j]->indexcount;
					return;
				}
			}

			for(int j = ind + 1; j < 26; j++)
			{
				if(pcrawl -> children[j])
				{
				/*	while(1)
					{
						maxind = pcrawl->children[j]->indexcount - 1;
						pcrawl = pcrawl->children[j];
						int indval = -1;
						for(int k = 0; k < 26; k++)
						{
							if(pcrawl->children[k])
							{
								indval = k; break;
							}
						}
						j = indval;
						if(j < 0) break;
					}*/
					maxind = pcrawl->children[j]->minpos - 1;
					return;
				}
			}
			return;
		}	
		pcrawl = pcrawl -> children[ind];
		//cout << (char)('a' + ind) << " " << pcrawl->indexcount<< endl;
		maxind = pcrawl->indexcount;
	}
	// either word is equal or key is smaller matched
	if(pcrawl->isEndofWord)
	{
		for(int j = 0; j < 26; j++)
		{
			if(pcrawl->children[j])
			{
				//maxind = pcrawl->children[j]->indexcount - 1;	
				maxind = pcrawl->children[j]-> minpos - 1;
				return;
			}
		}
		//maxind = pcrawl->minpos;
		return;
	}
	else
	{
		for(int j = 0; j < 26; j++)
		{
			if(pcrawl->children[j])
			{
				//maxind = pcrawl->children[j]->indexcount - 1;	
				maxind = pcrawl->children[j]-> minpos - 1;
				return;
			}
		}
	}
}

int main()
{
	int q; scanf("%d%d",&n,&q);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	struct TrieNode *root = getNode();
	for(int i = 0; i < n; i++) 
	{
		insert(root, s[i], i);
		//if(s[i][0] <= 'b') cout << i << " " << s[i] << endl;
	}	
	while(q--)
	{
		string temp;
		cin >> temp;
		maxind = -1;
		//cout << temp << endl;
		search(root, temp);
		//cout << "maxind =" << maxind << endl;
		int ans = maxind + 1;
		printf("%d\n", ans);
	}
	return 0;
}