#include <Mmsystem.h>
#include <mciapi.h>
#include<Windows.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")
using namespace std;

int main() {

    mciSendString("play \"sounds/music.wav\" repeat", NULL, 0, NULL);
    //return 0;
}