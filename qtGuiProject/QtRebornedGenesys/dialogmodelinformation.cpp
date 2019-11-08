#include "dialogmodelinformation.h"
#include "ui_dialogmodelinformation.h"

DialogModelInformation::DialogModelInformation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogModelInformation)
{
	ui->setupUi(this);
}

DialogModelInformation::~DialogModelInformation()
{
	delete ui;
}
