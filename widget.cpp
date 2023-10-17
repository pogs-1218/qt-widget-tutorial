#include "widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QVBoxLayout>

static const void VBoxLayout(Widget *w)
{
    auto b1 = new QPushButton("b1", w);
    auto b2 = new QPushButton("b2", w);
    auto b3 = new QPushButton("b3", w);
    auto b4 = new QPushButton("b4", w);

    auto vbox = new QVBoxLayout(w);
    vbox->addWidget(b1);
    vbox->addWidget(b2);
    vbox->addWidget(b3);
    vbox->addWidget(b4);
}

static const void HBoxLayout(Widget *w)
{
    // Note: The order of declaration affects the order of displaying.
    auto b1 = new QPushButton("b1", w);
    auto b2 = new QPushButton("b2", w);
    auto b3 = new QPushButton("b3", w);
    auto b4 = new QPushButton("b4", w);

    auto hbox = new QHBoxLayout(w);
    hbox->addWidget(b1);
    hbox->addWidget(b2);
    hbox->addWidget(b3);
    hbox->addWidget(b4);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QLabel");
    resize(500, 400);

    //    QLabel *label = new QLabel(this);
    //    label->setText("This is a label");
    //    label->move(200, 200);
    //    label->setFont(QFont("Fira Code", 15));
    //    label->setStyleSheet("color:red");

    QPushButton *button = new QPushButton("click", this);
    //    button->setGeometry(30, 30, 130, 30);
    if (button->isFlat()) {
        qDebug() << "is flat";
    }
    QMenu *menu = new QMenu();
    menu->addAction("Copy");
    menu->addAction("Cut");
    menu->addAction("Paste");
    button->setMenu(menu);

    QPushButton *button2 = new QPushButton("click2", this);
    //    button->setGeometry(30, 30, 130, 30);

    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(30, 70, 130, 30);
    //    lineEdit->setEnabled(false);
    lineEdit->setEchoMode(QLineEdit::EchoMode::Password);

    HBoxLayout(this);
    //    VBoxLayout(this);
}

Widget::~Widget()
{
}
