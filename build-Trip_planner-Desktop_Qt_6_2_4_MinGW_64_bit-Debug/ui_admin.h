/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QAction *actionSave;
    QAction *actionSales_Report;
    QAction *actionPurchases_Char;
    QAction *actionPurchases_Chart;
    QAction *actionMember_Purchases;
    QAction *actionManage_Inventory;
    QAction *actionItem_List;
    QAction *actionItem_Search;
    QAction *actionManage_Members;
    QAction *actionMember_Search;
    QAction *actionUpgrade_Downgrade_List;
    QWidget *centralwidget;
    QPushButton *addCityButton;
    QLineEdit *cityLineEdit;
    QLineEdit *endingCityLineEdit;
    QLineEdit *kilometerLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTableView *tableView;
    QPushButton *uploadFile;
    QTableView *tableView2;
    QLineEdit *cityLineEdit2;
    QLineEdit *foodLineEdit;
    QLineEdit *costLineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *addFoodButton;
    QPushButton *uploadFile2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(1138, 589);
        actionSave = new QAction(Admin);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSales_Report = new QAction(Admin);
        actionSales_Report->setObjectName(QString::fromUtf8("actionSales_Report"));
        actionPurchases_Char = new QAction(Admin);
        actionPurchases_Char->setObjectName(QString::fromUtf8("actionPurchases_Char"));
        actionPurchases_Chart = new QAction(Admin);
        actionPurchases_Chart->setObjectName(QString::fromUtf8("actionPurchases_Chart"));
        actionMember_Purchases = new QAction(Admin);
        actionMember_Purchases->setObjectName(QString::fromUtf8("actionMember_Purchases"));
        actionManage_Inventory = new QAction(Admin);
        actionManage_Inventory->setObjectName(QString::fromUtf8("actionManage_Inventory"));
        actionItem_List = new QAction(Admin);
        actionItem_List->setObjectName(QString::fromUtf8("actionItem_List"));
        actionItem_Search = new QAction(Admin);
        actionItem_Search->setObjectName(QString::fromUtf8("actionItem_Search"));
        actionManage_Members = new QAction(Admin);
        actionManage_Members->setObjectName(QString::fromUtf8("actionManage_Members"));
        actionMember_Search = new QAction(Admin);
        actionMember_Search->setObjectName(QString::fromUtf8("actionMember_Search"));
        actionUpgrade_Downgrade_List = new QAction(Admin);
        actionUpgrade_Downgrade_List->setObjectName(QString::fromUtf8("actionUpgrade_Downgrade_List"));
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName(QString::fromUtf8("addCityButton"));
        addCityButton->setGeometry(QRect(460, 310, 93, 29));
        cityLineEdit = new QLineEdit(centralwidget);
        cityLineEdit->setObjectName(QString::fromUtf8("cityLineEdit"));
        cityLineEdit->setGeometry(QRect(60, 310, 113, 26));
        endingCityLineEdit = new QLineEdit(centralwidget);
        endingCityLineEdit->setObjectName(QString::fromUtf8("endingCityLineEdit"));
        endingCityLineEdit->setGeometry(QRect(190, 310, 113, 26));
        kilometerLineEdit = new QLineEdit(centralwidget);
        kilometerLineEdit->setObjectName(QString::fromUtf8("kilometerLineEdit"));
        kilometerLineEdit->setGeometry(QRect(320, 310, 113, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 290, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 290, 91, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 290, 101, 20));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 391, 251));
        uploadFile = new QPushButton(centralwidget);
        uploadFile->setObjectName(QString::fromUtf8("uploadFile"));
        uploadFile->setGeometry(QRect(460, 350, 93, 29));
        tableView2 = new QTableView(centralwidget);
        tableView2->setObjectName(QString::fromUtf8("tableView2"));
        tableView2->setGeometry(QRect(580, 10, 411, 251));
        cityLineEdit2 = new QLineEdit(centralwidget);
        cityLineEdit2->setObjectName(QString::fromUtf8("cityLineEdit2"));
        cityLineEdit2->setGeometry(QRect(620, 310, 113, 26));
        foodLineEdit = new QLineEdit(centralwidget);
        foodLineEdit->setObjectName(QString::fromUtf8("foodLineEdit"));
        foodLineEdit->setGeometry(QRect(750, 310, 113, 26));
        costLineEdit = new QLineEdit(centralwidget);
        costLineEdit->setObjectName(QString::fromUtf8("costLineEdit"));
        costLineEdit->setGeometry(QRect(880, 310, 113, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(620, 290, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(750, 290, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(880, 290, 63, 20));
        addFoodButton = new QPushButton(centralwidget);
        addFoodButton->setObjectName(QString::fromUtf8("addFoodButton"));
        addFoodButton->setGeometry(QRect(1020, 310, 93, 29));
        uploadFile2 = new QPushButton(centralwidget);
        uploadFile2->setObjectName(QString::fromUtf8("uploadFile2"));
        uploadFile2->setGeometry(QRect(1020, 350, 93, 29));
        Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Admin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1138, 26));
        Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Admin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Admin->setStatusBar(statusbar);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Administrator", nullptr));
        actionSave->setText(QCoreApplication::translate("Admin", "Save", nullptr));
        actionSales_Report->setText(QCoreApplication::translate("Admin", "Sales Report", nullptr));
        actionPurchases_Char->setText(QCoreApplication::translate("Admin", "Purchases Char", nullptr));
        actionPurchases_Chart->setText(QCoreApplication::translate("Admin", "Purchases Chart", nullptr));
        actionMember_Purchases->setText(QCoreApplication::translate("Admin", "Member Purchases", nullptr));
        actionManage_Inventory->setText(QCoreApplication::translate("Admin", "Manage Inventory", nullptr));
        actionItem_List->setText(QCoreApplication::translate("Admin", "Inventory List", nullptr));
        actionItem_Search->setText(QCoreApplication::translate("Admin", "Item Search", nullptr));
        actionManage_Members->setText(QCoreApplication::translate("Admin", "Manage Members", nullptr));
        actionMember_Search->setText(QCoreApplication::translate("Admin", "Member Search", nullptr));
        actionUpgrade_Downgrade_List->setText(QCoreApplication::translate("Admin", "Upgrade/Downgrade List", nullptr));
        addCityButton->setText(QCoreApplication::translate("Admin", "Add City", nullptr));
        label->setText(QCoreApplication::translate("Admin", "City", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "Ending City", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "Distance (km)", nullptr));
        uploadFile->setText(QCoreApplication::translate("Admin", "Upload File", nullptr));
        label_4->setText(QCoreApplication::translate("Admin", "City", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "Food", nullptr));
        label_6->setText(QCoreApplication::translate("Admin", "Cost", nullptr));
        addFoodButton->setText(QCoreApplication::translate("Admin", "Add Food", nullptr));
        uploadFile2->setText(QCoreApplication::translate("Admin", "Upload File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
