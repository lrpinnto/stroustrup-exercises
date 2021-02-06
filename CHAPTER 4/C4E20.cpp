#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 4 EX 20

/*True for int, false for string */
bool input_type(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        switch (input[i])
        {
        case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '0':
            break;
        default:
        return false;
            break;
        }
    }
    return true;
}

int myPow(int x, int p) //ter de escrever a minha propria definição de potencia :xxxxx
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int str_to_int(string input)
{

    int counter = 0;
    int final_number = 0;
    vector<int>zero_index;
    for (int i = input.size()-1; i>=0; i--)
    {
        switch (input[i])
        {
        case '1':
            final_number+= 1*myPow(10,counter);
            counter++;
            break;
        case '2':
            final_number+= 2*myPow(10,counter);
            counter++;
            break;
        case '3':
            final_number+= 3*myPow(10,counter);
            counter++;
            break;
        case '4':
            final_number+= 4*myPow(10,counter);
            counter++;
            break;
        case '5':
            final_number+= 5*myPow(10,counter);
            counter++;
            break;
        case '6':
            final_number+= 6*myPow(10,counter);
            counter++;
            break;
        case '7':
            final_number+= 7*myPow(10,counter);
            counter++;
            break;
        case '8':
            final_number+= 8*myPow(10,counter);
            counter++;
            break;
        case '9':
            final_number+= 9*myPow(10,counter);
            counter++;
            break;
        case '0':
            final_number+=myPow(10,counter+1) ;
            zero_index.push_back(counter+1);
            counter++;
            break;        
        default:
            cout<<"????????";
            break;
        }
    }

    //really bad zero fix
    for (int i : zero_index)
    {
        final_number-=myPow(10,i);
    }
    return final_number;
}

bool check_repeating(vector<string>names, string name)
{
    for (string h: names)
    {
        if (h==name)
        {
            return true;
        }
        
    }
    return false;
    
}

int main()
{
    string name;
    int age = 0;
    vector<int>ages;
    vector<string>names;
    while (true)
    {
        cout<<"Please enter a name followed by age:\n\t";
        cin>>name>>age;
        if (name=="NoName" && age==0)
        {
            break;
        }
        else if (check_repeating(names,name))
        {
            cout<<"\nThat name was already entered. Please pick another name!\n";
        }
        
        else
        {
            ages.push_back(age);
            names.push_back(name);
        }
    }
    for (int i = 0; i < names.size(); i++)
    {
        cout<<names[i]<<" aged "<<ages[i]<<".\n";
    }


    string query;
    bool age_exists; //acts as a switch to check if the "if" was run at lease once. for int
    while (true)
    {
        query = "";
        age_exists=false;
        cout<<"\nPlease enter either an age or a name to check for matching results-->";
        cin>>query;
        
        if (input_type(query)) //Int
        {
            for (int i = 0; i < ages.size(); i++)
            {
                if (str_to_int(query)==ages[i])
                {
                    cout<<names[i]<<", ";
                    age_exists=true;
                }

                if (i==names.size()-1 && age_exists==false)
                {
                    cout<<"No one exists with that age!!\n";
                }
                
            }
            if (age_exists==true) cout<<" are all aged "<<str_to_int(query);
            
            
        }
        else //string
        {
            for (int i = 0; i < names.size() ; i++)
            {
                if (query==names[i])
                {
                    cout<<"The age of "<<names[i]<<" is "<<ages[i]<<".\n";
                    break;
                }
                if (i==names.size()-1)
                {
                    cout<<"That name does not exist!\n";
                }
            }
            
        }
    }
    
    

}