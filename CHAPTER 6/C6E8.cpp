#include "../stroustrup/std_lib_facilities.h"

//CAP 6 EX 08

/*BULLS AND COWS GAME*/

int main()
try{
    constexpr int max_vector_size = 4;
    bool success=false;
    vector<char>random_chars;
    int n=0;
    bool repeat = false;
    int val = 0;
    vector<char>numbers;
    string input;
    int count; 
    char char_converter;

    while (true)
    {
        cout<<"Please enter any number, this will generate a seed for your game:";
        cin>>n;
        if (!cin) error("Bad input.");

        seed_randint(n); //randomizes numbers
        while (random_chars.size() < max_vector_size) 
        {
            val = randint(65,122);  //From 65 to 122 covering all letters both lower case and upper.
            if (val >=91 && val <=96) continue;   //91 to 96 contain symbols in the ascii table. Ignore these.
            char_converter=val;
            repeat = false;

            if (random_chars.size() == 0)
                random_chars.push_back(char_converter);
            else 
            {
                for (char h : random_chars) if (h == char_converter) repeat = true;

                if (!repeat) random_chars.push_back(val);
            }
        }
        
        success=false;
        while (!success)
        {
            int bulls=0;
            int cows=0;
            numbers={};
            count =0;
            cout<<"Please input your guess (A-Z and a-z):";
            cin>>input;
            if (!cin) error("Bad input.");
            for (char c : input)
            {
                if (count>=max_vector_size) break;
                numbers.push_back(c);
                count++;
            }
            for (int i = 0; i < numbers.size(); i++)
            {
                for (int j = 0; j < random_chars.size(); j++)
                {
                    if (random_chars[j]==numbers[i] && i!=j)
                    {
                        cows++;
                    }
                }

                if (random_chars[i]==numbers[i])
                {
                    bulls++;
                }
                
            }

            cout<<cows<<" cows and "<<bulls<<" bulls.\n";

            if (bulls == 4) 
            {
                success=true;
                cout<<"YOU DID IT!! Value: ";
                for (char h : random_chars) cout<<h;
                cout<<" Your guess: ";
                for(char h : numbers) cout<<h;
                cout<<".\n";
                random_chars.clear(); //clears the vector to get another set of values
            }
        }
    }
}
catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}