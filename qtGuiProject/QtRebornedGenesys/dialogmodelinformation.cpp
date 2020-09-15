#include "dialogmodelinformation.h"
#include "ui_dialogmodelinformation.h"
#include <QString>
#include <QMessageBox>

DialogModelInformation::DialogModelInformation(QWidget *parent) :
QDialog(parent),
ui(new Ui::DialogModelInformation) {
	ui->setupUi(this);
}

DialogModelInformation::~DialogModelInformation() {
	delete ui;
}

void DialogModelInformation::setModelMVC(ModelInfo* info) {
	//general
	ui->lineEdit_AnalystName->setText(QString::fromStdString(info->analystName()));
	ui->lineEdit_Description->setText(QString::fromStdString(info->description()));
	ui->lineEdit_ModelName->setText(QString::fromStdString(info->description()));
	ui->lineEdit_ProjectTitle->setText(QString::fromStdString(info->projectTitle()));
	ui->lineEdit_Version->setText(QString::fromStdString(info->version()));
	//simulation
	ui->doubleSpinBoxReplicationLength->setValue(info->replicationLength());
	ui->doubleSpinBoxWarmupTime->setValue(info->warmUpPeriod());
	ui->spinBoxNumberofReplications->setValue(info->numberOfReplications());
	int i = 1;
	Util::TimeUnit timeunit;
	std::string strtimeunit;
	do {
		timeunit = static_cast<Util::TimeUnit> (i);
		strtimeunit = Util::StrTimeUnit(timeunit);
		if (strtimeunit != "") {
			ui->comboBoxReplicationLengthTimeUnit->addItem(QString::fromStdString(strtimeunit)); //insertItem(i-1,"",QString::fromStdString(strtimeunit));
			ui->comboBoxWarmupTimeTimeUnit->addItem(QString::fromStdString(strtimeunit)); //insertItem(i-1,"",QString::fromStdString(strtimeunit));
		}
		i++;
	} while (strtimeunit != "");
	ui->comboBoxReplicationLengthTimeUnit->setCurrentIndex(static_cast<int> (info->replicationLengthTimeUnit()) - 1);
	ui->comboBoxWarmupTimeTimeUnit->setCurrentIndex(static_cast<int> (info->warmUpPeriodTimeUnit()) - 1);
	_hasChanged = false;
}

ModelInfo DialogModelInformation::getModelMVC() {
	//general
	ModelInfo info;
	info.setAnalystName(ui->lineEdit_AnalystName->text().toStdString());
	info.setDescription(ui->lineEdit_Description->text().toStdString());
	info.setName(ui->lineEdit_ModelName->text().toStdString());
	info.setProjectTitle(ui->lineEdit_ProjectTitle->text().toStdString());
	info.setVersion(ui->lineEdit_Version->text().toStdString());
	//simulation
	info.setNumberOfReplications(ui->spinBoxNumberofReplications->value());
	info.setReplicationLength(ui->doubleSpinBoxReplicationLength->value());
	info.setReplicationLengthTimeUnit(static_cast<Util::TimeUnit> (ui->comboBoxReplicationLengthTimeUnit->currentIndex() + 1));
	info.setWarmUpPeriod(ui->doubleSpinBoxWarmupTime->value());
	info.setWarmUpPeriodTimeUnit(static_cast<Util::TimeUnit> (ui->comboBoxWarmupTimeTimeUnit->currentIndex() + 1));
	return info;
}

void DialogModelInformation::on_buttonBox_accepted() {
}

void DialogModelInformation::on_buttonBox_rejected() {
}

void DialogModelInformation::on_lineEdit_AnalystName_textChanged(const QString &arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_ProjectTitle_textChanged(const QString &arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_ModelName_textChanged(const QString &arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_Description_textChanged(const QString &arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_lineEdit_Version_textChanged(const QString &arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_buttonBox_clicked(QAbstractButton *button) {
	if (button == (QAbstractButton*) (ui->buttonBox->button(QDialogButtonBox::Cancel)) && _hasChanged) {
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Cancel", "Information has changed. Cancel anyway?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::No) {
			return;
		}
	}
}

void DialogModelInformation::on_spinBoxNumberofReplications_valueChanged(const QString &arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_doubleSpinBoxReplicationLength_valueChanged(double arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_doubleSpinBoxWarmupTime_valueChanged(double arg1) {
	_hasChanged = true;
}

void DialogModelInformation::on_comboBoxReplicationLengthTimeUnit_currentIndexChanged(int index) {
	_hasChanged = true;
}

void DialogModelInformation::on_comboBoxWarmupTimeTimeUnit_currentIndexChanged(int index) {
	_hasChanged = true;
}
