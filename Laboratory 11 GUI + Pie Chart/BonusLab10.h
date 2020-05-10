#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BonusLab10.h"

class BonusLab10 : public QMainWindow
{
	Q_OBJECT

public:
	BonusLab10(QWidget *parent = Q_NULLPTR);

private:
	Ui::BonusLab10Class ui;
};
