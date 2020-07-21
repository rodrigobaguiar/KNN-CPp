#include "CAboutScreen.h"
#include "ui_CAboutScreen.h"

CAboutScreen::CAboutScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CAboutScreen)
{
    ui->setupUi(this);
    connect(ui->PBOk, &QPushButton::clicked, this, &CAboutScreen::close);
}

CAboutScreen::~CAboutScreen()
{
    delete ui;
}
