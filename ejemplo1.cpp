#include "ejemplo1.h"

 
ejemplo1::ejemplo1(): Ui_Counter()
{
  setupUi(this);
  show();
  num=0;
  
  mythread = std::move(std::thread(&hebras::run, hebras(),std::bind(&ejemplo1::doLCDnumber,this)));
  connect(button, SIGNAL(clicked()),this,SLOT(doButton()));
  connect(restart, SIGNAL(clicked()),this,SLOT(restartContador()));
 
}

ejemplo1::~ejemplo1(){
  mythread.detach();
}

void ejemplo1::doButton()
{
	
  if(!hilo.getparar()){
    hilo.setparar(true);
    button->setText("START");
  }
  else{
   hilo.setparar(false);
  button->setText("STOP");
  cv.notify_all();
  }
  
}

void ejemplo1::restartContador()
{
num=0;
lcdNumber->display(num);

}


 void ejemplo1::doLCDnumber()
{
    
   std::unique_lock<std::mutex> lk(cv_m); 
   
   while(hilo.getparar())
      cv.wait(lk);
   
   
   num++;
   lcdNumber->display(num);
   usleep(1000000);
 
    
    
}  




