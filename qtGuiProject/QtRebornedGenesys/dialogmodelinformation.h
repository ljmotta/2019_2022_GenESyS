#ifndef DIALOGMODELINFORMATION_H
#define DIALOGMODELINFORMATION_H

#include <QDialog>

namespace Ui {
	class DialogModelInformation;
}

class DialogModelInformation : public QDialog
{
	Q_OBJECT

public:
	explicit DialogModelInformation(QWidget *parent = 0);
	~DialogModelInformation();

private:
	Ui::DialogModelInformation *ui;
};

#endif // DIALOGMODELINFORMATION_H
