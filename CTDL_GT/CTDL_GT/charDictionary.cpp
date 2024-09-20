#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string word;
    Node *next;
    Node(string s = "") : word(s), next(NULL) {}
};

struct Dict
{
    Node **head;

    Dict()
    {
        head = new Node *[26];
        for (int i = 0; i < 26; i++)
        {
            head[i] = NULL;
        }
    }

    void insert(string word, int idx)
    {
        if (head[idx] == NULL)
        {
            head[idx] = new Node(word);
        }
        else
        {
            Node *tmp = head[idx];
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node(word);
        }
    }

    void insertWord(string word)
    {
        int idx = int(tolower(word[0]) - 'a');
        if (head[idx] == NULL)
        {
            head[idx] = new Node(string(1, word[0]));
        }

        insert(word, idx);
    }

    void display()
    {
        for (int i = 0; i < 26; i++)
        {
            if (head[i] != NULL)
            {
                Node *tmp = head[i];
                while (tmp != NULL)
                {
                    cout << tmp->word << " -> ";
                    tmp = tmp->next;
                }
                cout << "NULL" << endl;
            }
        }
    }

    bool search(string word)
    {
        int idx = int(tolower(word[0]) - 'a');

        if (head[idx] == NULL)
        {
            return false;
        }
        else
        {
            Node *tmp = head[idx];
            while (tmp != NULL)
            {
                if (tmp->word == word)
                {
                    return true;
                }
                tmp = tmp->next;
            }
            return false;
        }
    }
};

int main()
{
    Dict dict;
    dict.insertWord("hello");
    dict.insertWord("apple");
    dict.insertWord("amazing");
    dict.insertWord("black");
    dict.insertWord("blue");
    dict.insertWord("bright");
    dict.insertWord("supper");
    dict.insertWord("mercy");
    dict.insertWord("yiel");
    dict.display();

    cout << dict.search("Blue") << endl;
    return 0;
}
