

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include<vector>
#include <cstdlib> 
#include <ctime>

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
        cout <<"\t\t\t\t" << text <<"\t\t\t\t" << endl;
    }
    cout << "\t\t\t\t";
}

void level(int curr,bool space) {

    curr = arr[curr];

    if (curr == -1) {
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
        if (n == "2" && curr!=0) {
            space = false;
            //roll a dice
            n = to_string(rand() % 2) ;
            cout << "\n\n";
            l_cout(200000, false);
            cout << "\n\n";
        }

        


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
    std::cout << "Hello World!\n";
    change_level();
   

    level(0,true);
    
}
