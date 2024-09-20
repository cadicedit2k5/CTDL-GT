#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#define MAX 100

using namespace std;

struct Word
{
    string word;
    string type;
    string mean;
    Word *next;

    Word(string word = "", string type = "", string mean = "", Word *ptr = NULL)
    {
        this->word = word;
        this->type = type;
        this->mean = mean;
        this->next = ptr;
    }
};

struct Dictionary
{
    Word **heads;
    int capacity;

    Dictionary()
    {
        capacity = nearestPrime(MAX);

        heads = new Word *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            heads[i] = NULL;
        }
    }

    bool isPrime(int n)
    {
        if (n < 2)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int nearestPrime(int n)
    {
        for (int i = n; i >= 2; i++)
        {
            if (isPrime(i))
            {
                return i;
            }
        }
        return -1;
    }

    int hashFunc(string s)
    {
        int h = 0;
        for (int i = 0; i < s.length(); i++)
        {
            h += (int)(tolower(s[i])) * (i + 1);
        }
        return h % capacity;
    }

    Word *searchWord(string word)
    {
        int index = hashFunc(word);

        Word *tmp = heads[index];
        while (tmp != NULL && tmp->word != word)
        {
            tmp = tmp->next;
        }

        if (tmp != NULL)
        {
            return tmp;
        }
        return NULL;
    }

    void loadDictionary()
    {
    }

    void insertWord(Word *w)
    {
        int index = hashFunc(w->word);

        heads[index] = new Word(w->word, w->type, w->mean, heads[index]);
    }

    void display()
    {
        cout << "======== DICTIONARY =========\n";
        for (int i = 0; i < capacity; i++)
        {
            if (heads[i] != NULL)
            {
                Word *tmp = heads[i];
                while (tmp != NULL)
                {
                    cout << tmp->word << " (" << tmp->type << ") : " << tmp->mean << endl;
                    tmp = tmp->next;
                }
            }
        }
    }
};

int main()
{
    Dictionary d;

    Word *w1, *w2, *w3, *w4, *w5, *w6;
    w1 = new Word("Hello", "V", "Xin chào");
    w2 = new Word("Teacher", "N", "Giáo viên");
    w3 = new Word("Good", "Adj", "Tốt");
    w4 = new Word("Student", "N", "Sinh viên");
    w5 = new Word("Pupil", "N", "Học sinh");
    w6 = new Word("teacher", "N", "Giảng viên");

    d.insertWord(w1);
    d.insertWord(w2);
    d.insertWord(w3);
    d.insertWord(w4);
    d.insertWord(w5);
    d.insertWord(w6);

    d.display();

    if (d.searchWord("linh") != NULL)
    {
        cout << "Tu co ton tai trong bang bam.\n";
    }
    else
        cout << "Tu khong ton tai.\n";
    return 0;
}
