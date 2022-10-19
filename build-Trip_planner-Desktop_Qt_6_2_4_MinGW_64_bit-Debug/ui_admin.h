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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *initStartingCitiesPushButton;
    QPushButton *initNewCitiesPUshButton;
    QPushButton *InitializeStartingFoodsPushButton;
    QPushButton *InitializeNewFoodsPushButton;
    QPushButton *userWindowPushButton;
    QPushButton *deleteTablePushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QTableView *distanceTableView;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLineEdit *cityLineEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QLineEdit *endingCityLineEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *kilometerLineEdit;
    QPushButton *addCityButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_8;
    QTableView *foodTableView;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *cityLineEdit2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *foodLineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLineEdit *costLineEdit;
    QPushButton *addFoodButton;
    QPushButton *editFoodButton;
    QPushButton *deleteFood;
    QHBoxLayout *horizontalLayout_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(1141, 535);
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        initStartingCitiesPushButton = new QPushButton(centralwidget);
        initStartingCitiesPushButton->setObjectName(QString::fromUtf8("initStartingCitiesPushButton"));

        horizontalLayout->addWidget(initStartingCitiesPushButton);

        initNewCitiesPUshButton = new QPushButton(centralwidget);
        initNewCitiesPUshButton->setObjectName(QString::fromUtf8("initNewCitiesPUshButton"));

        horizontalLayout->addWidget(initNewCitiesPUshButton);

        InitializeStartingFoodsPushButton = new QPushButton(centralwidget);
        InitializeStartingFoodsPushButton->setObjectName(QString::fromUtf8("InitializeStartingFoodsPushButton"));

        horizontalLayout->addWidget(InitializeStartingFoodsPushButton);

        InitializeNewFoodsPushButton = new QPushButton(centralwidget);
        InitializeNewFoodsPushButton->setObjectName(QString::fromUtf8("InitializeNewFoodsPushButton"));

        horizontalLayout->addWidget(InitializeNewFoodsPushButton);

        userWindowPushButton = new QPushButton(centralwidget);
        userWindowPushButton->setObjectName(QString::fromUtf8("userWindowPushButton"));

        horizontalLayout->addWidget(userWindowPushButton);

        deleteTablePushButton = new QPushButton(centralwidget);
        deleteTablePushButton->setObjectName(QString::fromUtf8("deleteTablePushButton"));

        horizontalLayout->addWidget(deleteTablePushButton);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 181, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        gridLayout->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        distanceTableView = new QTableView(centralwidget);
        distanceTableView->setObjectName(QString::fromUtf8("distanceTableView"));

        verticalLayout_7->addWidget(distanceTableView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label);

        cityLineEdit = new QLineEdit(centralwidget);
        cityLineEdit->setObjectName(QString::fromUtf8("cityLineEdit"));

        verticalLayout_6->addWidget(cityLineEdit);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        endingCityLineEdit = new QLineEdit(centralwidget);
        endingCityLineEdit->setObjectName(QString::fromUtf8("endingCityLineEdit"));

        verticalLayout_5->addWidget(endingCityLineEdit);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        kilometerLineEdit = new QLineEdit(centralwidget);
        kilometerLineEdit->setObjectName(QString::fromUtf8("kilometerLineEdit"));

        verticalLayout_4->addWidget(kilometerLineEdit);


        horizontalLayout_4->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName(QString::fromUtf8("addCityButton"));

        horizontalLayout_5->addWidget(addCityButton);


        verticalLayout_7->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        foodTableView = new QTableView(centralwidget);
        foodTableView->setObjectName(QString::fromUtf8("foodTableView"));

        verticalLayout_8->addWidget(foodTableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        cityLineEdit2 = new QLineEdit(centralwidget);
        cityLineEdit2->setObjectName(QString::fromUtf8("cityLineEdit2"));

        verticalLayout->addWidget(cityLineEdit2);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        foodLineEdit = new QLineEdit(centralwidget);
        foodLineEdit->setObjectName(QString::fromUtf8("foodLineEdit"));

        verticalLayout_2->addWidget(foodLineEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        costLineEdit = new QLineEdit(centralwidget);
        costLineEdit->setObjectName(QString::fromUtf8("costLineEdit"));

        verticalLayout_3->addWidget(costLineEdit);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        addFoodButton = new QPushButton(centralwidget);
        addFoodButton->setObjectName(QString::fromUtf8("addFoodButton"));

        horizontalLayout_3->addWidget(addFoodButton);

        editFoodButton = new QPushButton(centralwidget);
        editFoodButton->setObjectName(QString::fromUtf8("editFoodButton"));

        horizontalLayout_3->addWidget(editFoodButton);

        deleteFood = new QPushButton(centralwidget);
        deleteFood->setObjectName(QString::fromUtf8("deleteFood"));

        horizontalLayout_3->addWidget(deleteFood);


        verticalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout_8->addLayout(horizontalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Admin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1141, 26));
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
        initStartingCitiesPushButton->setText(QCoreApplication::translate("Admin", "Initialize Starting Cities", nullptr));
        initNewCitiesPUshButton->setText(QCoreApplication::translate("Admin", "Initialize New Cities", nullptr));
        InitializeStartingFoodsPushButton->setText(QCoreApplication::translate("Admin", "Initialize Starting Foods", nullptr));
        InitializeNewFoodsPushButton->setText(QCoreApplication::translate("Admin", "Initialize New Foods", nullptr));
        userWindowPushButton->setText(QCoreApplication::translate("Admin", "Show User Window", nullptr));
        deleteTablePushButton->setText(QCoreApplication::translate("Admin", "Delete Tables", nullptr));
        label->setText(QCoreApplication::translate("Admin", "City", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "Ending City", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "Distance (km)", nullptr));
        addCityButton->setText(QCoreApplication::translate("Admin", "Add City", nullptr));
        label_4->setText(QCoreApplication::translate("Admin", "City", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "Food", nullptr));
        label_6->setText(QCoreApplication::translate("Admin", "Cost", nullptr));
        addFoodButton->setText(QCoreApplication::translate("Admin", "Add Food", nullptr));
        editFoodButton->setText(QCoreApplication::translate("Admin", "Edit Food", nullptr));
        deleteFood->setText(QCoreApplication::translate("Admin", "Delete Food", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
