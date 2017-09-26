#ifndef ejemplo1_H
#define ejemplo1_H
#include <QtGui>
#include "ui_counterDlg.h"
#include "hebras.h"
#include <thread>
#include <functional>
#include <condition_variable>


class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT

private:
    hebras hilo;
    std::thread mythread;
    std::condition_variable cv;
    std::mutex cv_m;
   
    
public:
    int num;
    ejemplo1();
    virtual ~ejemplo1();
    
public slots:
    void doButton();
    void doLCDnumber();
     void restartContador();
};

#endif // ejemplo1_H
