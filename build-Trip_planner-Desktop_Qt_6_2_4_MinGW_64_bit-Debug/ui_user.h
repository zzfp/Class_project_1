/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *travelStackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *distanceAndFoodPushButton;
    QPushButton *berlinPushButton;
    QPushButton *parisCustomTripPushButton;
    QPushButton *customTripButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *searchFoodItemLineEdit;
    QPushButton *searchFoodPushButton;
    QLabel *searchErrorLabel;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTableView *distanceTableView;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTableView *foodTableView;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *beginTripPushButton;
    QVBoxLayout *verticalLayout_11;
    QLabel *validCityErrorBerlin;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *berlin11CitiesPushButton;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *berlin13CitiesPushButton;
    QTableView *tripTableView;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QLabel *currentCityLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *enterItemLineEdit;
    QLineEdit *quantityItemLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addItemPushButton;
    QPushButton *nextCityPushButton;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QTableView *currentCityTableView;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QTableView *receiptTabTableView;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QTableView *totalAmountPerCityTableView;
    QLabel *totalAmountSpentLabel;
    QLabel *totalDistanceTraveledLabel;
    QWidget *parisPage;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *parisBeginTrip;
    QVBoxLayout *verticalLayout_13;
    QLabel *parisWrongError;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *numberOfCitiesLineEdit;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *addParisCitiesPushButton;
    QTableView *parisTableView;
    QWidget *customTripPage;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_12;
    QTableView *citiesTableView;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_13;
    QTableView *customTripTableView;
    QLabel *customTripErrorLabel;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *citiesComboBox;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *addCustomCityPushButton;
    QPushButton *finalizeTripCustomCityPushButton;
    QPushButton *beginTripCustomCityPushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(865, 503);
        centralwidget = new QWidget(user);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        travelStackedWidget = new QStackedWidget(centralwidget);
        travelStackedWidget->setObjectName(QString::fromUtf8("travelStackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(639, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        distanceAndFoodPushButton = new QPushButton(page);
        distanceAndFoodPushButton->setObjectName(QString::fromUtf8("distanceAndFoodPushButton"));

        horizontalLayout_2->addWidget(distanceAndFoodPushButton);

        berlinPushButton = new QPushButton(page);
        berlinPushButton->setObjectName(QString::fromUtf8("berlinPushButton"));

        horizontalLayout_2->addWidget(berlinPushButton);

        parisCustomTripPushButton = new QPushButton(page);
        parisCustomTripPushButton->setObjectName(QString::fromUtf8("parisCustomTripPushButton"));

        horizontalLayout_2->addWidget(parisCustomTripPushButton);

        customTripButton = new QPushButton(page);
        customTripButton->setObjectName(QString::fromUtf8("customTripButton"));

        horizontalLayout_2->addWidget(customTripButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        searchFoodItemLineEdit = new QLineEdit(page);
        searchFoodItemLineEdit->setObjectName(QString::fromUtf8("searchFoodItemLineEdit"));

        horizontalLayout_6->addWidget(searchFoodItemLineEdit);

        searchFoodPushButton = new QPushButton(page);
        searchFoodPushButton->setObjectName(QString::fromUtf8("searchFoodPushButton"));

        horizontalLayout_6->addWidget(searchFoodPushButton);


        verticalLayout_10->addLayout(horizontalLayout_6);

        searchErrorLabel = new QLabel(page);
        searchErrorLabel->setObjectName(QString::fromUtf8("searchErrorLabel"));
        searchErrorLabel->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout_10->addWidget(searchErrorLabel);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        distanceTableView = new QTableView(page);
        distanceTableView->setObjectName(QString::fromUtf8("distanceTableView"));

        verticalLayout->addWidget(distanceTableView);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        foodTableView = new QTableView(page);
        foodTableView->setObjectName(QString::fromUtf8("foodTableView"));

        verticalLayout_2->addWidget(foodTableView);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_10->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_10, 1, 0, 1, 1);

        travelStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        beginTripPushButton = new QPushButton(page_2);
        beginTripPushButton->setObjectName(QString::fromUtf8("beginTripPushButton"));
        beginTripPushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(beginTripPushButton);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        validCityErrorBerlin = new QLabel(page_2);
        validCityErrorBerlin->setObjectName(QString::fromUtf8("validCityErrorBerlin"));
        validCityErrorBerlin->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0)"));

        verticalLayout_11->addWidget(validCityErrorBerlin);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        berlin11CitiesPushButton = new QPushButton(page_2);
        berlin11CitiesPushButton->setObjectName(QString::fromUtf8("berlin11CitiesPushButton"));

        horizontalLayout_10->addWidget(berlin11CitiesPushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        label_9 = new QLabel(page_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        berlin13CitiesPushButton = new QPushButton(page_2);
        berlin13CitiesPushButton->setObjectName(QString::fromUtf8("berlin13CitiesPushButton"));

        horizontalLayout_10->addWidget(berlin13CitiesPushButton);


        verticalLayout_4->addLayout(horizontalLayout_10);

        tripTableView = new QTableView(page_2);
        tripTableView->setObjectName(QString::fromUtf8("tripTableView"));

        verticalLayout_4->addWidget(tripTableView);


        verticalLayout_11->addLayout(verticalLayout_4);


        gridLayout_3->addLayout(verticalLayout_11, 1, 0, 1, 1);

        travelStackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        currentCityLineEdit = new QLabel(page_3);
        currentCityLineEdit->setObjectName(QString::fromUtf8("currentCityLineEdit"));
        currentCityLineEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        horizontalLayout_7->addWidget(currentCityLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_9->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);


        gridLayout_4->addLayout(verticalLayout_9, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        enterItemLineEdit = new QLineEdit(page_3);
        enterItemLineEdit->setObjectName(QString::fromUtf8("enterItemLineEdit"));

        horizontalLayout_4->addWidget(enterItemLineEdit);

        quantityItemLineEdit = new QLineEdit(page_3);
        quantityItemLineEdit->setObjectName(QString::fromUtf8("quantityItemLineEdit"));
        quantityItemLineEdit->setMouseTracking(true);
        quantityItemLineEdit->setAutoFillBackground(false);

        horizontalLayout_4->addWidget(quantityItemLineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        addItemPushButton = new QPushButton(page_3);
        addItemPushButton->setObjectName(QString::fromUtf8("addItemPushButton"));

        horizontalLayout_4->addWidget(addItemPushButton);

        nextCityPushButton = new QPushButton(page_3);
        nextCityPushButton->setObjectName(QString::fromUtf8("nextCityPushButton"));

        horizontalLayout_4->addWidget(nextCityPushButton);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        currentCityTableView = new QTableView(page_3);
        currentCityTableView->setObjectName(QString::fromUtf8("currentCityTableView"));

        verticalLayout_5->addWidget(currentCityTableView);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        receiptTabTableView = new QTableView(page_3);
        receiptTabTableView->setObjectName(QString::fromUtf8("receiptTabTableView"));

        verticalLayout_6->addWidget(receiptTabTableView);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_7->addWidget(label_7);

        totalAmountPerCityTableView = new QTableView(page_3);
        totalAmountPerCityTableView->setObjectName(QString::fromUtf8("totalAmountPerCityTableView"));

        verticalLayout_7->addWidget(totalAmountPerCityTableView);


        horizontalLayout_5->addLayout(verticalLayout_7);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        totalAmountSpentLabel = new QLabel(page_3);
        totalAmountSpentLabel->setObjectName(QString::fromUtf8("totalAmountSpentLabel"));

        gridLayout_4->addWidget(totalAmountSpentLabel, 3, 0, 1, 1);

        totalDistanceTraveledLabel = new QLabel(page_3);
        totalDistanceTraveledLabel->setObjectName(QString::fromUtf8("totalDistanceTraveledLabel"));

        gridLayout_4->addWidget(totalDistanceTraveledLabel, 4, 0, 1, 1);

        travelStackedWidget->addWidget(page_3);
        parisPage = new QWidget();
        parisPage->setObjectName(QString::fromUtf8("parisPage"));
        gridLayout_5 = new QGridLayout(parisPage);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(parisPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        horizontalLayout_12->addWidget(label_10);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);

        parisBeginTrip = new QPushButton(parisPage);
        parisBeginTrip->setObjectName(QString::fromUtf8("parisBeginTrip"));
        parisBeginTrip->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        horizontalLayout_12->addWidget(parisBeginTrip);


        gridLayout_5->addLayout(horizontalLayout_12, 0, 0, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        parisWrongError = new QLabel(parisPage);
        parisWrongError->setObjectName(QString::fromUtf8("parisWrongError"));
        parisWrongError->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout_13->addWidget(parisWrongError);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        numberOfCitiesLineEdit = new QLineEdit(parisPage);
        numberOfCitiesLineEdit->setObjectName(QString::fromUtf8("numberOfCitiesLineEdit"));
        numberOfCitiesLineEdit->setClearButtonEnabled(false);

        horizontalLayout_11->addWidget(numberOfCitiesLineEdit);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_9);

        addParisCitiesPushButton = new QPushButton(parisPage);
        addParisCitiesPushButton->setObjectName(QString::fromUtf8("addParisCitiesPushButton"));

        horizontalLayout_11->addWidget(addParisCitiesPushButton);


        verticalLayout_12->addLayout(horizontalLayout_11);

        parisTableView = new QTableView(parisPage);
        parisTableView->setObjectName(QString::fromUtf8("parisTableView"));

        verticalLayout_12->addWidget(parisTableView);


        verticalLayout_13->addLayout(verticalLayout_12);


        gridLayout_5->addLayout(verticalLayout_13, 1, 0, 1, 1);

        travelStackedWidget->addWidget(parisPage);
        customTripPage = new QWidget();
        customTripPage->setObjectName(QString::fromUtf8("customTripPage"));
        gridLayout_6 = new QGridLayout(customTripPage);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_12 = new QLabel(customTripPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_15->addWidget(label_12);

        citiesTableView = new QTableView(customTripPage);
        citiesTableView->setObjectName(QString::fromUtf8("citiesTableView"));

        verticalLayout_15->addWidget(citiesTableView);


        horizontalLayout_15->addLayout(verticalLayout_15);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_13 = new QLabel(customTripPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_14->addWidget(label_13);

        customTripTableView = new QTableView(customTripPage);
        customTripTableView->setObjectName(QString::fromUtf8("customTripTableView"));

        verticalLayout_14->addWidget(customTripTableView);


        horizontalLayout_15->addLayout(verticalLayout_14);


        verticalLayout_16->addLayout(horizontalLayout_15);

        customTripErrorLabel = new QLabel(customTripPage);
        customTripErrorLabel->setObjectName(QString::fromUtf8("customTripErrorLabel"));
        customTripErrorLabel->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout_16->addWidget(customTripErrorLabel);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        citiesComboBox = new QComboBox(customTripPage);
        citiesComboBox->setObjectName(QString::fromUtf8("citiesComboBox"));
        citiesComboBox->setMinimumSize(QSize(400, 0));

        horizontalLayout_14->addWidget(citiesComboBox);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        addCustomCityPushButton = new QPushButton(customTripPage);
        addCustomCityPushButton->setObjectName(QString::fromUtf8("addCustomCityPushButton"));
        addCustomCityPushButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_13->addWidget(addCustomCityPushButton);

        finalizeTripCustomCityPushButton = new QPushButton(customTripPage);
        finalizeTripCustomCityPushButton->setObjectName(QString::fromUtf8("finalizeTripCustomCityPushButton"));
        finalizeTripCustomCityPushButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_13->addWidget(finalizeTripCustomCityPushButton);

        beginTripCustomCityPushButton = new QPushButton(customTripPage);
        beginTripCustomCityPushButton->setObjectName(QString::fromUtf8("beginTripCustomCityPushButton"));
        beginTripCustomCityPushButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_13->addWidget(beginTripCustomCityPushButton);


        horizontalLayout_14->addLayout(horizontalLayout_13);


        verticalLayout_16->addLayout(horizontalLayout_14);


        gridLayout_6->addLayout(verticalLayout_16, 0, 0, 1, 1);

        travelStackedWidget->addWidget(customTripPage);

        gridLayout_2->addWidget(travelStackedWidget, 0, 1, 1, 1);

        user->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(user);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        user->setStatusBar(statusbar);
        menubar = new QMenuBar(user);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 865, 22));
        user->setMenuBar(menubar);

        retranslateUi(user);

        travelStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QMainWindow *user)
    {
        user->setWindowTitle(QCoreApplication::translate("user", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("user", "User Trip Planner", nullptr));
        distanceAndFoodPushButton->setText(QCoreApplication::translate("user", "Show Distances and Food", nullptr));
        berlinPushButton->setText(QCoreApplication::translate("user", "Plan a Trip From Berlin", nullptr));
        parisCustomTripPushButton->setText(QCoreApplication::translate("user", "Plan a Trip From Paris", nullptr));
        customTripButton->setText(QCoreApplication::translate("user", "Plan a Custom Trip", nullptr));
        searchFoodItemLineEdit->setText(QString());
        searchFoodItemLineEdit->setPlaceholderText(QCoreApplication::translate("user", "Search by City for food items", nullptr));
        searchFoodPushButton->setText(QCoreApplication::translate("user", "Search Food", nullptr));
        searchErrorLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("user", "Distances from Rome", nullptr));
        label_3->setText(QCoreApplication::translate("user", "Food items for: ", nullptr));
        label_4->setText(QCoreApplication::translate("user", "Berlin Trip", nullptr));
        beginTripPushButton->setText(QCoreApplication::translate("user", "Begin Trip", nullptr));
        validCityErrorBerlin->setText(QString());
        berlin11CitiesPushButton->setText(QCoreApplication::translate("user", "11 Cities", nullptr));
        label_9->setText(QCoreApplication::translate("user", "Select Amount of Cities", nullptr));
        berlin13CitiesPushButton->setText(QCoreApplication::translate("user", "13 Cities", nullptr));
        currentCityLineEdit->setText(QCoreApplication::translate("user", "CURRENT CITY", nullptr));
        enterItemLineEdit->setText(QString());
        enterItemLineEdit->setPlaceholderText(QCoreApplication::translate("user", "Enter Item", nullptr));
        quantityItemLineEdit->setText(QString());
        quantityItemLineEdit->setPlaceholderText(QCoreApplication::translate("user", "Enter Quantity", nullptr));
        addItemPushButton->setText(QCoreApplication::translate("user", "Add item", nullptr));
        nextCityPushButton->setText(QCoreApplication::translate("user", "Next City", nullptr));
        label_5->setText(QCoreApplication::translate("user", "Current City", nullptr));
        label_6->setText(QCoreApplication::translate("user", "Receipt Tab", nullptr));
        label_7->setText(QCoreApplication::translate("user", "Total Amount Spent Per City", nullptr));
        totalAmountSpentLabel->setText(QCoreApplication::translate("user", "Total Amount Spent:", nullptr));
        totalDistanceTraveledLabel->setText(QCoreApplication::translate("user", "Total Distance Traveled:", nullptr));
        label_10->setText(QCoreApplication::translate("user", "Paris Trip", nullptr));
        parisBeginTrip->setText(QCoreApplication::translate("user", "Begin Trip", nullptr));
        parisWrongError->setText(QString());
        numberOfCitiesLineEdit->setText(QString());
        numberOfCitiesLineEdit->setPlaceholderText(QCoreApplication::translate("user", "Enter Number of Cities", nullptr));
        addParisCitiesPushButton->setText(QCoreApplication::translate("user", "Add Number of Cities", nullptr));
        label_12->setText(QCoreApplication::translate("user", "Cities Available", nullptr));
        label_13->setText(QCoreApplication::translate("user", "Trip Selections", nullptr));
        customTripErrorLabel->setText(QString());
        addCustomCityPushButton->setText(QCoreApplication::translate("user", "Add City", nullptr));
        finalizeTripCustomCityPushButton->setText(QCoreApplication::translate("user", "Finalize Trip", nullptr));
        beginTripCustomCityPushButton->setText(QCoreApplication::translate("user", "Begin Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
