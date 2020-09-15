/********************************************************************************
 ** Form generated from reading UI file 'dialogmodelinformation.ui'
 **
 ** Created by: Qt User Interface Compiler version 5.12.4
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_DIALOGMODELINFORMATION_H
#define UI_DIALOGMODELINFORMATION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogModelInformation {
public:
	QVBoxLayout *verticalLayout;
	QGroupBox *groupBox;
	QVBoxLayout *verticalLayout_2;
	QHBoxLayout *horizontalLayout_2;
	QLabel *label_2;
	QLineEdit *lineEdit_AnalystName;
	QHBoxLayout *horizontalLayout_3;
	QLabel *label_4;
	QLineEdit *lineEdit_ProjectTitle;
	QHBoxLayout *horizontalLayout;
	QLabel *label;
	QLineEdit *lineEdit_ModelName;
	QHBoxLayout *horizontalLayout_4;
	QLabel *label_3;
	QLineEdit *lineEdit_Description;
	QHBoxLayout *horizontalLayout_5;
	QLabel *label_5;
	QLineEdit *lineEdit_Version;
	QGroupBox *groupBox_2;
	QVBoxLayout *verticalLayout_3;
	QHBoxLayout *horizontalLayout_6;
	QLabel *label_6;
	QSpinBox *spinBoxNumberofReplications;
	QSpacerItem *horizontalSpacer_3;
	QHBoxLayout *horizontalLayout_7;
	QLabel *label_7;
	QDoubleSpinBox *doubleSpinBoxReplicationLength;
	QComboBox *comboBoxReplicationLengthTimeUnit;
	QSpacerItem *horizontalSpacer;
	QHBoxLayout *horizontalLayout_8;
	QLabel *label_8;
	QDoubleSpinBox *doubleSpinBoxWarmupTime;
	QComboBox *comboBoxWarmupTimeTimeUnit;
	QSpacerItem *horizontalSpacer_2;
	QDialogButtonBox *buttonBox;

	void setupUi(QDialog *DialogModelInformation) {
		if (DialogModelInformation->objectName().isEmpty())
			DialogModelInformation->setObjectName(QString::fromUtf8("DialogModelInformation"));
		DialogModelInformation->resize(437, 408);
		DialogModelInformation->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
		verticalLayout = new QVBoxLayout(DialogModelInformation);
		verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
		groupBox = new QGroupBox(DialogModelInformation);
		groupBox->setObjectName(QString::fromUtf8("groupBox"));
		verticalLayout_2 = new QVBoxLayout(groupBox);
		verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
		label_2 = new QLabel(groupBox);
		label_2->setObjectName(QString::fromUtf8("label_2"));

		horizontalLayout_2->addWidget(label_2);

		lineEdit_AnalystName = new QLineEdit(groupBox);
		lineEdit_AnalystName->setObjectName(QString::fromUtf8("lineEdit_AnalystName"));

		horizontalLayout_2->addWidget(lineEdit_AnalystName);


		verticalLayout_2->addLayout(horizontalLayout_2);

		horizontalLayout_3 = new QHBoxLayout();
		horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
		label_4 = new QLabel(groupBox);
		label_4->setObjectName(QString::fromUtf8("label_4"));

		horizontalLayout_3->addWidget(label_4);

		lineEdit_ProjectTitle = new QLineEdit(groupBox);
		lineEdit_ProjectTitle->setObjectName(QString::fromUtf8("lineEdit_ProjectTitle"));

		horizontalLayout_3->addWidget(lineEdit_ProjectTitle);


		verticalLayout_2->addLayout(horizontalLayout_3);

		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		label = new QLabel(groupBox);
		label->setObjectName(QString::fromUtf8("label"));

		horizontalLayout->addWidget(label);

		lineEdit_ModelName = new QLineEdit(groupBox);
		lineEdit_ModelName->setObjectName(QString::fromUtf8("lineEdit_ModelName"));

		horizontalLayout->addWidget(lineEdit_ModelName);


		verticalLayout_2->addLayout(horizontalLayout);

		horizontalLayout_4 = new QHBoxLayout();
		horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
		label_3 = new QLabel(groupBox);
		label_3->setObjectName(QString::fromUtf8("label_3"));

		horizontalLayout_4->addWidget(label_3);

		lineEdit_Description = new QLineEdit(groupBox);
		lineEdit_Description->setObjectName(QString::fromUtf8("lineEdit_Description"));

		horizontalLayout_4->addWidget(lineEdit_Description);


		verticalLayout_2->addLayout(horizontalLayout_4);

		horizontalLayout_5 = new QHBoxLayout();
		horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
		label_5 = new QLabel(groupBox);
		label_5->setObjectName(QString::fromUtf8("label_5"));

		horizontalLayout_5->addWidget(label_5);

		lineEdit_Version = new QLineEdit(groupBox);
		lineEdit_Version->setObjectName(QString::fromUtf8("lineEdit_Version"));

		horizontalLayout_5->addWidget(lineEdit_Version);


		verticalLayout_2->addLayout(horizontalLayout_5);


		verticalLayout->addWidget(groupBox);

		groupBox_2 = new QGroupBox(DialogModelInformation);
		groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
		verticalLayout_3 = new QVBoxLayout(groupBox_2);
		verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
		horizontalLayout_6 = new QHBoxLayout();
		horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
		label_6 = new QLabel(groupBox_2);
		label_6->setObjectName(QString::fromUtf8("label_6"));

		horizontalLayout_6->addWidget(label_6);

		spinBoxNumberofReplications = new QSpinBox(groupBox_2);
		spinBoxNumberofReplications->setObjectName(QString::fromUtf8("spinBoxNumberofReplications"));
		spinBoxNumberofReplications->setMinimum(1);
		spinBoxNumberofReplications->setMaximum(9999);

		horizontalLayout_6->addWidget(spinBoxNumberofReplications);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout_6->addItem(horizontalSpacer_3);


		verticalLayout_3->addLayout(horizontalLayout_6);

		horizontalLayout_7 = new QHBoxLayout();
		horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
		label_7 = new QLabel(groupBox_2);
		label_7->setObjectName(QString::fromUtf8("label_7"));

		horizontalLayout_7->addWidget(label_7);

		doubleSpinBoxReplicationLength = new QDoubleSpinBox(groupBox_2);
		doubleSpinBoxReplicationLength->setObjectName(QString::fromUtf8("doubleSpinBoxReplicationLength"));
		QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(doubleSpinBoxReplicationLength->sizePolicy().hasHeightForWidth());
		doubleSpinBoxReplicationLength->setSizePolicy(sizePolicy);
		doubleSpinBoxReplicationLength->setDecimals(3);
		doubleSpinBoxReplicationLength->setMinimum(0.000000000000000);
		doubleSpinBoxReplicationLength->setMaximum(999999.000000000000000);

		horizontalLayout_7->addWidget(doubleSpinBoxReplicationLength);

		comboBoxReplicationLengthTimeUnit = new QComboBox(groupBox_2);
		comboBoxReplicationLengthTimeUnit->setObjectName(QString::fromUtf8("comboBoxReplicationLengthTimeUnit"));

		horizontalLayout_7->addWidget(comboBoxReplicationLengthTimeUnit);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout_7->addItem(horizontalSpacer);


		verticalLayout_3->addLayout(horizontalLayout_7);

		horizontalLayout_8 = new QHBoxLayout();
		horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
		label_8 = new QLabel(groupBox_2);
		label_8->setObjectName(QString::fromUtf8("label_8"));

		horizontalLayout_8->addWidget(label_8);

		doubleSpinBoxWarmupTime = new QDoubleSpinBox(groupBox_2);
		doubleSpinBoxWarmupTime->setObjectName(QString::fromUtf8("doubleSpinBoxWarmupTime"));
		sizePolicy.setHeightForWidth(doubleSpinBoxWarmupTime->sizePolicy().hasHeightForWidth());
		doubleSpinBoxWarmupTime->setSizePolicy(sizePolicy);
		doubleSpinBoxWarmupTime->setDecimals(3);
		doubleSpinBoxWarmupTime->setMaximum(999999.000000000000000);

		horizontalLayout_8->addWidget(doubleSpinBoxWarmupTime);

		comboBoxWarmupTimeTimeUnit = new QComboBox(groupBox_2);
		comboBoxWarmupTimeTimeUnit->setObjectName(QString::fromUtf8("comboBoxWarmupTimeTimeUnit"));

		horizontalLayout_8->addWidget(comboBoxWarmupTimeTimeUnit);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout_8->addItem(horizontalSpacer_2);


		verticalLayout_3->addLayout(horizontalLayout_8);


		verticalLayout->addWidget(groupBox_2);

		buttonBox = new QDialogButtonBox(DialogModelInformation);
		buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
		buttonBox->setOrientation(Qt::Horizontal);
		buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

		verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
		label_2->setBuddy(lineEdit_AnalystName);
		label_4->setBuddy(lineEdit_ProjectTitle);
		label->setBuddy(lineEdit_ModelName);
		label_3->setBuddy(lineEdit_Description);
		label_5->setBuddy(lineEdit_Version);
#endif // QT_NO_SHORTCUT
		QWidget::setTabOrder(lineEdit_AnalystName, lineEdit_ProjectTitle);
		QWidget::setTabOrder(lineEdit_ProjectTitle, lineEdit_ModelName);
		QWidget::setTabOrder(lineEdit_ModelName, lineEdit_Description);
		QWidget::setTabOrder(lineEdit_Description, lineEdit_Version);

		retranslateUi(DialogModelInformation);
		QObject::connect(buttonBox, SIGNAL(accepted()), DialogModelInformation, SLOT(accept()));
		QObject::connect(buttonBox, SIGNAL(rejected()), DialogModelInformation, SLOT(reject()));

		QMetaObject::connectSlotsByName(DialogModelInformation);
	} // setupUi

	void retranslateUi(QDialog *DialogModelInformation) {
		DialogModelInformation->setWindowTitle(QApplication::translate("DialogModelInformation", "Model Information", nullptr));
		groupBox->setTitle(QApplication::translate("DialogModelInformation", "General", nullptr));
		label_2->setText(QApplication::translate("DialogModelInformation", "Analyst Name:", nullptr));
		label_4->setText(QApplication::translate("DialogModelInformation", "Project Title:", nullptr));
		label->setText(QApplication::translate("DialogModelInformation", "Model Name:", nullptr));
		label_3->setText(QApplication::translate("DialogModelInformation", "Description:", nullptr));
		label_5->setText(QApplication::translate("DialogModelInformation", "Version:", nullptr));
		groupBox_2->setTitle(QApplication::translate("DialogModelInformation", "Simulation", nullptr));
		label_6->setText(QApplication::translate("DialogModelInformation", "Number of replications:", nullptr));
		label_7->setText(QApplication::translate("DialogModelInformation", "Replication Length:", nullptr));
		label_8->setText(QApplication::translate("DialogModelInformation", "Warmup time:", nullptr));
	} // retranslateUi

};

namespace Ui {

	class DialogModelInformation : public Ui_DialogModelInformation {
	};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODELINFORMATION_H
