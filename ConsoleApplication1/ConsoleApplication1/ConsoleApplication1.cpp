

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include<vector>
#include <cstdlib> 
#include <ctime>
#include <thread> 


using namespace std;

vector<int> arr(1000000);

void change_level() {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }
    
    arr[61] = 59;
    arr[62] = 59;
    arr[119] = 2;
    arr[120] = 13;
    arr[12] = 6;
    arr[121] = 59;
    arr[245] = 59;
    arr[246] = 59;
    arr[115] = 0;
    arr[116] = 1;
    arr[118] = 27;
    arr[473] = -1;

    arr[949] = 0;
    arr[950] = 1;

    arr[1892] = 1891;
    arr[3784] = 3783;
    arr[7568] = 7567;

    arr[1894] = 1893;
    arr[3788] = 3787;
    arr[7576] = 7575;

    arr[15151] = 15135;
    arr[15152] = 15136;
    
    arr[943] = 945;
    arr[944] = 946;

    arr[30271] = 15136;
    arr[30272] = -1;

    arr[60549] = 0;
    arr[60550] = 1;

    arr[60548] = 60547;
    
    arr[121095] = -1;
    arr[121096] = -2;
    
    
}


void clear_function() {
    string file_name;

    file_name = "files/" + to_string(0) + ".txt";
    ofstream  file(file_name);

    string file_name2;
    string text;
    file_name2 = "files/" + to_string(100031) + ".txt";
    ifstream file2(file_name2);

    while (getline(file2, text)) {
        file << text << endl;
    }


    //In memory of those who sacrificed everything to make this possible.
    cout << "clearing the story\n";
    for (int i = 1; i <= 100030; i++) {
        string file_name;
        string text;
        file_name = "files/" + to_string(i) + ".txt";
        ofstream  file(file_name);
        file << "the story was deleted";
        file.close();
    }

    
  

    cout << "story deleted\n";
}


void l_cout(int id,bool space=true) {

    if (space) {
        int t = 100;
        while (t--) {
            cout << "\n";
        }
    }
    
    string file_name;
    string text;
    file_name = "files/" + to_string(id) + ".txt";
    ifstream file(file_name);
    
    while (getline(file, text)) {


        cout << "\t\t\t\t";
        for (char c : text) {
            cout << c;
            cout.flush();
            this_thread::sleep_for(std::chrono::milliseconds(25));
        }
        cout << "\t\t\t\t" << endl;
    }
    cout << "\t\t\t\t";
}

void level(int curr,bool space) {

    curr = arr[curr];

    if (curr == -1) {
        return;
    }
    else if (curr == -2) {
        clear_function();
        return;
    }
    l_cout(curr,space);

    if (curr == 1) {
        return;
    }

    bool con;
    do {
        string n;
        cin >> n;
       
        con = false;
        bool space = true;
        

    
        if (n == "0") {
            level(2 * curr + 1,space);
        }
        else if (n == "1") {
            level(2 * curr + 2,space);
        }
        else {
            con = true;

            srand((unsigned)time(0));
            int i;
            i = (rand() % 14)+100000;
            l_cout(i,false);
        }

    } while (con);
    
    

}



int main()
{
    
    change_level();
    

    level(0,true);
    
}
