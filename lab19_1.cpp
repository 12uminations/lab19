#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string H, vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream x(H);
    string text;
    int s1,s2,s3,tot=0;
    char op[50];
    char grude;
    char format[]="%[^:]: %d %d %d";
    while(getline(x,text)){
        sscanf(text.c_str(),format,&op,&s1,&s2,&s3);
        names.push_back(op);
        tot = s1+s2+s3;
        grude = score2grade(tot);
        scores.push_back(tot);
        grades.push_back(grude);
    }
}

void getCommand(string &command, string &key){
    string xter;
    char format[] = "%s %[^:]s";
    char comd[10], quey[100];
    cout << "Please input your command: ";
    getline(cin, xter);
    sscanf(xter.c_str(), format, &comd, &quey);
    command = comd;
    key = quey;
}

void searchName( vector<string> names,vector<int> scores,vector<char> grades,string key){
    int j = 0;
    cout << "---------------------------------\n";
    for (unsigned int i=0 ; i < names.size() ; i++)
    {
        string henti = names.at(i);
        henti = toUpperStr(henti);
        if (key == henti)
        {
            cout << names.at(i) << "'s score = " << scores.at(i) << "\n";
            cout << names.at(i) << "'s grade = " << grades.at(i) << "\n";
            j++;
        }
    }
    if (j == 0) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
}

void searchGrade( vector<string> names,vector<int> scores,vector<char> grades,string key){
        int j = 0;
    cout << "---------------------------------\n";
    for (unsigned int i = 0; i < grades.size(); i++){
        if (*key.c_str() == grades[i]){
            cout << names.at(i) << " (" << scores.at(i) << ")\n";
            j++;
        }
    }
    if (j == 0) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
