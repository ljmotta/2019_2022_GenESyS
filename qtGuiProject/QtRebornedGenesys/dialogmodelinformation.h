#ifndef DIALOGMODELINFORMATION_H
#define DIALOGMODELINFORMATION_H

#include <QDialog>
#include <QAbstractButton>
#include "../../../RebornedGenESyS/ModelInfo.h"

namespace Ui {
	class DialogModelInformation;
}

class DialogModelInformation : public QDialog
{
	Q_OBJECT

public:
	explicit DialogModelInformation(QWidget *parent = 0);
	~DialogModelInformation();
	void setModelMVC(ModelInfo* info);
private slots:
	void on_buttonBox_accepted();

	void on_buttonBox_rejected();

	void on_lineEdit_AnalystName_textChanged(const QString &arg1);

	void on_lineEdit_ProjectTitle_textChanged(const QString &arg1);

	void on_lineEdit_ModelName_textChanged(const QString &arg1);

	void on_lineEdit_Description_textChanged(const QString &arg1);

	void on_lineEdit_Version_textChanged(const QString &arg1);

	void on_buttonBox_clicked(QAbstractButton *button);

private:
	Ui::DialogModelInformation *ui;
	ModelInfo* _modelMVC;
	bool _hasChanged = false;
};

#endif // DIALOGMODELINFORMATION_H
