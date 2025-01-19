

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;


void l_cout(int id) {

    int t = 100;
    while (t--) {
        cout << "\n";
    }
    string file_name;
    string text;
    file_name = "files/" + to_string(id) + ".txt";
    ifstream file(file_name);
    while (getline(file, text)) {
        cout <<"\t\t\t\t" << text <<"\t\t\t\t" << endl;
    }
}

void next(int curr) {
    l_cout(curr);
    bool con;
    do {
        string n;
        
        auto startTime = chrono::steady_clock::now();
        con = false;

        while (true) {
            if (std::cin.rdbuf()->in_avail() > 0) { 
                std::cin.ignore(); 
                std::getline(std::cin,n ); 
                std::cout << "b" << input << std::endl;
                break;
            }

            auto elapsed = duration_cast<seconds>(steady_clock::now() - startTime).count();
            if (elapsed >= 10) {
                std::cout << "cc!" << std::endl;
                
            }
        }





        if (n == "1") {
            next(2 * curr + 1);
        }
        else if (n == "2") {
            next(2 * curr + 2);
        }
        else {
            con = true;
            l_cout(1000);
        }

    } while (con);
    
    

}


int main()
{
    std::cout << "Hello World!\n";
    l_cout(0);
    int n;
    cin >> n;
    l_cout(1000);

}
