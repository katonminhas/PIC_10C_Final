#include <QApplication>
#include <QTime>
#include "diver.h"
#include "game.h"
#include "endscreen.h"
#include "titlescreen.h"
#include "pearl.h"
#include "shark.h"

Game* game;
Title::TitleScreen* MainMenu;
End::EndScreen* EndMenu;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Construct the game and both menus
    game = new Game();
    MainMenu = new Title::TitleScreen();
    EndMenu = new End::EndScreen();


    MainMenu->show();


    return a.exec();
}
