#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 5 EX 13 &12

/*BULLS AND COWS GAME*/

int char_to_int(char c)
{
    switch (c)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 99; //terrible idea. Return 99 if anything but a number.
        break;
    }
}


int main()
try{
    constexpr int max_vector_size = 4;
    bool success=false;
    vector<int>random_numbers;
    int n=0;
    bool repeat = false;
    int val = 0;
    vector<int>numbers;
    string input;
    int count; 

    while (true)
    {
        cout<<"Please enter any number:";
        cin>>n;
        if (!cin) error("Bad input.");


        seed_randint(n); //randomizes numbers
        while (random_numbers.size() < max_vector_size) 
        {
            val = randint(9);
            repeat = false;

            if (random_numbers.size() == 0)
                random_numbers.push_back(val);
            else 
            {
                for (int h : random_numbers) if (h == val) repeat = true;

                if (!repeat) random_numbers.push_back(val);
            }
        }
        
        
        
        success=false;
        while (!success)
        {
            int bulls=0;
            int cows=0;
            numbers={};
            count =0;
            cout<<"Please input your guess:";
            cin>>input;
            if (!cin) error("Bad input.");
            for (char c : input)
            {
                if (count>=max_vector_size) break;
                if (char_to_int(c)==99)
                {
                    continue; //ignores any non int character and skips to the next one until it finds another int
                }
                numbers.push_back(char_to_int(c));
                count++;
            }
            for (int i = 0; i < numbers.size(); i++)
            {
                for (int j = 0; j < random_numbers.size(); j++)
                {
                    if (random_numbers[j]==numbers[i] && i!=j)
                    {
                        cows++;
                    }
                }

                if (random_numbers[i]==numbers[i])
                {
                    bulls++;
                }
                
            }

            cout<<cows<<" cows and "<<bulls<<" bulls.\n";

            if (bulls == 4) 
            {
                success=true;
                cout<<"YOU DID IT!! Value: ";
                for (int h : random_numbers) cout<<h;
                cout<<" Your guess: ";
                for(int h : numbers) cout<<h;
                cout<<".\n";
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