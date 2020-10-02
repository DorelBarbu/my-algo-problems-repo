#include <iostream>
#include <string>
#include <vector>
#define ALPHABET_LENGTH 26
using namespace std;

int charToNumber(char c)
{
  return c - 'a';
}

struct Trie
{
  bool isWordEnding;
  Trie *children[ALPHABET_LENGTH + 1];

  void init()
  {
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
      children[i] = new Trie();
    }
  }
};

void add(Trie *root, string word, int wordIndex)
{
  if (word.length() - 1 == wordIndex)
  {
    root->isWordEnding = true;
    return;
  }

  // cout<<"add "<<wordIndex<<endl;

  char nextIndex = charToNumber(word[wordIndex + 1]);

  if (root->children[nextIndex] == NULL)
  {
    root->children[nextIndex] = new Trie();
  }

  add(root->children[nextIndex], word, wordIndex + 1);
}

bool contains(Trie *root, string word, int k)
{
  if (word.length() - 1 == k)
  {
    return root->isWordEnding;
  }

  int nextIndex = charToNumber(word[k + 1]);

  //cout<<word[k + 1]<<' '<<nextIndex<<' '<<root->children[nextIndex]<<' '<<root->children[nextIndex]->isWordEnding<<endl;

  return root->children[nextIndex] == NULL ? false : contains(root->children[nextIndex], word, k + 1);
}

bool concat(Trie *root, Trie *t, string w, int k, int c)
{
  cout<<w<<' '<<k<<' '<<c<<endl;
  if (w.length() - 1 == k)
  {
    cout<<"yes"<<endl;
    return t->isWordEnding;
  }

  int next = charToNumber(w[k + 1]);

  if (t->isWordEnding == true)
  {
    return concat(root, root, w.substr(k + 1), 0, c + 1) ||
           (t->children[next] != NULL && concat(root, t->children[next], w, k + 1, c) && c > 0);
  }
  else
  {
    return t->children[next] != NULL && concat(root, t->children[next], w, k + 1, c) && c > 0;
  }
}

Trie *createTrie()
{
  Trie *t = new Trie();
  t->init();
  return t;
}

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
  Trie *t = createTrie();
  for (string s : words)
  {
    add(t, s, 0);
  }

  vector<string> solution;

  for (string s : words)
  {
    cout << s << " " << concat(t, t, s, 0, 0) << endl;
    if(concat(t, t, s, 0, 0)) {
      solution.push_back(s);
    }
  }

  return solution;
}

void test1()
{
  cout << "---Test 1---" << endl;
  vector<string> v;
  v.push_back("cat");
  v.push_back("cats");
  v.push_back("catsdogcats");
  v.push_back("dog");
  v.push_back("dogcatsdog");
  v.push_back("hippopotamuses");
  v.push_back("rat");
  v.push_back("ratcatdogcat");
  findAllConcatenatedWordsInADict(v);
}

void test2()
{
  cout << "---Test 2---" << endl;
  Trie* t = new Trie();
  add(t, "dog", 0);
  add(t, "dogcat", 0);
  add(t, "dogc", 0);
  add(t, "at", 0);
  cout<<concat(t, t, "dogcat", 0, 0);
}

int main()
{
  test2();
  return 0;
}