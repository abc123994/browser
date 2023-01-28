#include <QApplication>
#include"Core/broswer.h"

#include <Windows.h>
#include"Tool/conf.hpp"
using namespace std;
int main(int argc, char* argv[])
{
    
    auto debug = settings.value("debug/console", "false").toBool();
    if (debug) {
        AllocConsole();
        freopen("CON", "w", stdout);
        freopen("CON", "w", stderr);
    }
    QApplication   app(argc, argv);
    broswer broswer;
 
 
    return app.exec();
}
