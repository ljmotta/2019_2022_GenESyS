#include "dialogmodelinformation.h"
#include "ui_dialogmodelinformation.h"
#include <QString>
#include <QMessageBox>

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

void DialogModelInformation::setModelMVC(ModelInfo* info)
{
	//general
	ui->lineEdit_AnalystName->setText(QString::fromStdString(info->analystName()));
	ui->lineEdit_Description->setText(QString::fromStdString(info->description()));
	ui->lineEdit_ModelName->setText(QString::fromStdString(info->description()));
	ui->lineEdit_ProjectTitle->setText(QString::fromStdString(info->projectTitle()));
	ui->lineEdit_Version->setText(QString::fromStdString(info->version()));
	//simulation
	_modelMVC = info;
}

void DialogModelInformation::on_buttonBox_accepted()
{
	//general
	_modelMVC->setAnalystName(ui->lineEdit_AnalystName->text().toStdString());
	_modelMVC->setDescription(ui->lineEdit_Description->text().toStdString());
	_modelMVC->setName(ui->lineEdit_ModelName->text().toStdString());
	_modelMVC->setProjectTitle(ui->lineEdit_ProjectTitle->text().toStdString());
	_modelMVC->setVersion(ui->lineEdit_Version->text().toStdString());
	//simulation
	this->close();
}

void DialogModelInformation::on_buttonBox_rejected()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Cancel", "Information has changed. Cancel anyway?", QMessageBox::Yes|QMessageBox::No);
	if (reply == QMessageBox::No) {
		return;
	}
	this->close();
}

void DialogModelInformation::on_lineEdit_AnalystName_textChanged(const QString &arg1)
{
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_ProjectTitle_textChanged(const QString &arg1)
{
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_ModelName_textChanged(const QString &arg1)
{
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_Description_textChanged(const QString &arg1)
{
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_Version_textChanged(const QString &arg1)
{
	_hasChanged = true;
}

void DialogModelInformation::on_buttonBox_clicked(QAbstractButton *button)
{

}
