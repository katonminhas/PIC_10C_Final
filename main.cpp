#include <QApplication>
#include <QTime>
#include "game.h"
#include "titlescreen.h"


Game* game;

TitleScreen* title;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    title = new TitleScreen();

    game = new Game();

    game->show();

    return a.exec();
}
