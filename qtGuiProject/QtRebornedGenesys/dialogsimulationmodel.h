#ifndef DIALOGSIMULATIONMODEL_H
#define DIALOGSIMULATIONMODEL_H

#include <QDialog>
#include "../../Model.h"
#include "mapkernelandui.h"

namespace Ui {
	class DialogSimulationModel;
}

class DialogSimulationModel : public QDialog
{
	Q_OBJECT

public:
	explicit DialogSimulationModel(Model* model, QWidget *parent = 0);
	~DialogSimulationModel();
protected:
	virtual void closeEvent(QCloseEvent *e);

private slots:
	void _on_reject();
	void on_horizontalSliderZoom_valueChanged(int value);
	void _on_graphicalmodelScene_mousemove(QMouseEvent *event);

private:
	void _refresh();
private:
	Ui::DialogSimulationModel *ui;
	Model* _model;
	MapKernelAndUI* _mapSimUI = new MapKernelAndUI();
};

#endif // DIALOGSIMULATIONMODEL_H
