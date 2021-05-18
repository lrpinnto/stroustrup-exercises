#include "../stroustrup/std_lib_facilities.h"

class Name_pairs
{
    private:
        vector<string> name;
        vector<double> age;
    public:
        Name_pairs(string name,double age);
        Name_pairs(vector<string> name, vector<double> age);
        void print();
        double size() const {return age.size();}
        void read_ages();
        void read_names(int n); //adds a series of names with 0.1 as age
        vector<string>  get_names() const {return name;}
        vector<double> get_ages() const {return age;}
        void sort();
};

ostream& operator<<(ostream& os, const Name_pairs& d)
{
    string result = "name\tage\n";
    vector<double>age=d.get_ages();
    vector<string>name=d.get_names();
    for (int i = 0; i < d.size(); i++)
    {
        result.append(name[i]);
        result.push_back('\t');
        result.append(to_string(age[i]));
        result.push_back('\n');
    }
    
    return os << result;
}

Name_pairs::Name_pairs(string names, double ages)
    :name{names},age{ages}
{
    if(!name.empty() || !age.empty()) {name.clear();age.clear();}   //avoids adding extra elements through initialization
    if(ages<0) error("age cannot be negative");
    name.push_back(names);
    age.push_back(ages);
}

Name_pairs::Name_pairs(vector<string> names, vector<double> ages)
    :name{names},age{ages}
{
    if(names.size()!=ages.size()) error("vectors need to have same size");
    for(double i : ages) if(i<0) error("age cannot be negative");
    name=names;
    age=ages;
}

void Name_pairs::read_names(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"Name:";
        string a;
        cin>>a;
        name.push_back(a);
        age.push_back(0.1);
        cout<<'\n';
    }
}

void Name_pairs::read_ages()
{
    for (int i = 0; i<name.size(); ++i) {         //only prompts ages for new users (assigned with 0.1, terrible hack)
        if(age[i]!=0.1) continue;
        cout << "Name:" << name[i] << " Age:";
        double a;
        cin >> a;
        age[i]=a;;
        cout<<'\n';
    }
}

int get_index_n (string s, vector<string>vect)
{
    for (int i = 0; i < vect.size(); i++) if (s==vect[i]) return i;
    error("No index found.");
    return 0;
}

void Name_pairs::sort()
{
    vector<string>copy_names = name;
    vector<double>ages_sorted ;

    std::sort(name.begin(),name.end());
    vector<int>sort_order;
    for (string s : name)
    {
        sort_order.push_back(get_index_n(s,copy_names));
    }

    for (int i : sort_order)
    {
        ages_sorted.push_back(age[i]);
    }
    age=ages_sorted;
}

void Name_pairs::print()  //Terrible hack
{
    Name_pairs result {name,age};
    cout<<result<<'\n';
}

int main()
{
    Name_pairs maria {"maria",9};
    maria.print();
    vector<double>idades = {1,2,3};
    vector<string>nomes = {"rute","joana","cao"};
    Name_pairs turma {nomes,idades};
    turma.print();
    turma.read_names(5);
    turma.print();
    turma.read_ages();
    turma.print();
    turma.sort();
    turma.print();
}