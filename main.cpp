#include <QApplication>
#include <QTime>
#include "diver.h"
#include "game.h"
#include "endscreen.h"
#include "titlescreen.h"
#include "pearl.h"
#include "shark.h"

Game* game;
Title::TitleScreen* mainMenu;
End::EndScreen* endMenu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    mainMenu = new Title::TitleScreen();
    endMenu = new End::EndScreen();

    mainMenu->show();

    return a.exec();
}
