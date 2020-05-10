#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab10OOP.h"

class Lab10OOP : public QMainWindow
{
	Q_OBJECT

public:
	Lab10OOP(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab10OOPClass ui;
};
