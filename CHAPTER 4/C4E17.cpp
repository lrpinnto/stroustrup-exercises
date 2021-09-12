#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 17

string mode (vector<string>words)
{
    vector<string>mode_words;
    vector<int>mode_count;
    int count = 0;
    sort(words);
    int mode_index = 0;
    for (int i = 0; i < words.size()-1; i++)
    {
        if (words[i]==words[i+1])
        {
            count++;
        }
        else
        {
            mode_words.push_back(words[i]);
            mode_count.push_back(count);
            count=0;
        }
    }

    for (int i = 0; i < mode_count.size()-1; i++)
    {
        if (mode_count[i]>=mode_count[i+1] && mode_count[i]>= mode_count[mode_index])
        {
            mode_index = i;
        }

        else if (mode_count[i]<=mode_count[i+1] && mode_count[i+1]>= mode_count[mode_index])
        {
            mode_index=i+1;
        }
    }
    return mode_words[mode_index];
}

string min_word(vector<string>words)
{
    sort(words);
    return words[0];
}

string max_words(vector<string>words)
{
    sort(words);
    return words[words.size()-1];
}

int main ()
{
    vector<string>words;
    for (string word; cin>>word;)
    {
        words.push_back(word);
    }
    cout<<"The word "<<mode(words)<<" is the mode. The word "<<min_word(words)<<" Is the min. The word "<<max_words(words)<<" is the max.";
}
