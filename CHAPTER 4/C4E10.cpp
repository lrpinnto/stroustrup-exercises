// CHAPTER 4 EX 10

//Lost my first file for some reason. Doing second attempt from scratch

#include "../stroustrup/std_lib_facilities.h"

constexpr char rock {'r'};
constexpr char paper {'p'};
constexpr char scissors {'s'};

int char2int(char c)
{
    return c - '0';
}

// Function to reverse a string
void reverseStr(string& str) //reference, to be introduced
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

vector<char> get_rand_vector(int i) //Get a pseudo random vector from int seed
{
    constexpr int vector_max_size {20};
    string s {to_string(i)};
    if(s.size()<5) error("Please type a bigger input number");
    double number {vector_max_size*1.0/(s.size()*1.0)};
    number = ceil(number);
    while(s.size()*number>20) s.pop_back(); //takes out last char
    string s2 {s};
    for (int i = 0 ; i < vector_max_size ; i++ ) //scramble vector to mimic randomness
    {
        if(s2.size()>=20) break;
        if (char2int(s2[i]) % 2 == 0  )
        {
            reverseStr(s);  //reverse the string
        }
        s2+=s;
    }
    vector<char> random_vector;
    for (int i = 0; i < vector_max_size; i+=2)
    {
        if (char2int(s2[i])%2==0 && char2int(s2[i+1])%2==0) //rock
        {
            random_vector.push_back(rock);
        }
        else if (char2int(s2[i])%2==0 && char2int(s2[i+1])%2==1) //paper
        {
            random_vector.push_back(paper);
        }
        else if (char2int(s2[i])%2==1 && char2int(s2[i+1])%2==0) //scissors
        {
            random_vector.push_back(scissors);
        }
        else
        {
            //ignore, get last one
            if(random_vector.size()==0) continue;
            else random_vector.push_back(random_vector[random_vector.size()-1]);
        }
    }
    if(random_vector.size()<2) error("Please try another input");
    while (random_vector.size()<vector_max_size/2)
    {
        int i {0};
        random_vector.push_back(random_vector[i++]);
    }
    
    return random_vector;
}

int main()
{
    int wins {0};
    int losses {0};
    int ties {0};
    while(true)
    {
        int seed;
        cout<<"Please enter any number of atleast 5 digits:";
        cin>>seed;
        cout<<"Play 10 games\n";
        for(char c : get_rand_vector(seed))
        {
            char input;
            cout<<"Play Rock, Paper or Scissors? (r,p,s):";
            cin>>input;
            switch (input)
            {
            case rock:
                switch (c)
                {
                case rock:
                    ties++;
                    cout<<"It's a tie\n";
                    break;
                case paper:
                    losses++;
                    cout<<"You lost!\n";
                    break;
                case scissors:
                    wins++;
                    cout<<"You won!\n";
                    break;
                default:
                    error("unknown error");
                    break;
                }
                break;
            case paper:
                switch (c)
                {
                case rock:
                    wins++;
                    cout<<"You won!\n";
                    break;
                case paper:
                    ties++;
                    cout<<"It's a tie\n";
                    break;
                case scissors:
                    losses++;
                    cout<<"You lost!\n";
                    break;
                default:
                    error("unknown error");
                    break;
                }
                break;
            case scissors:
                switch (c)
                {
                case rock:
                    losses++;
                    cout<<"You lost!\n";
                    break;
                case paper:
                    wins++;
                    cout<<"You won!\n";
                    break;
                case scissors:
                    ties++;
                    cout<<"It's a tie\n";
                    break;
                default:
                    error("unknown error");
                    break;
                }
                break;
            default:
                cout<<"wrong input. use r p or s\n";
                break;
            }
        }
        cout<<"Try again?(y/n):";
        string choice;
        cin>>choice;
        if(choice!="y") break;
    }
    cout<<"Won "<<wins<<" games\n"
        <<"Lost "<<losses<<" games\n"
        <<"Tied "<<ties<<" games\n";
}