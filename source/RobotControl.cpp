//! Selay Kocatüfek  09.01.24
#include "RobotControl.h"

RobotControl::RobotControl() {
    position = new Pose();  //! Pose sınıfından bir nesne oluşturdum
    list<SensorInterface*>sensorList=nullptr;
    robotOp("Selay","Kocatufek",1234,false);
}
RobotControl::~RobotControl() {
    delete position;  //! Bellekten Pose nesnesini serbest bıraktım
    delete sensorList;  //! Bellekten NaoRobotAPI nesnesini serbest bıraktım
}
    void RobotControl::turnLeft() { //! Sola dönüş için naoRabotINT üzerinden fonksiyonu çağırdım.
      if(control == true){
        naoRobotINT.turnLeft();
      }
    }
    void RobotControl::turnRight() { //! Sağa dönüş için naoRabotINT üzerinden fonksiyonu çağırdım.
       if(control == true){
        naoRobotINT.turnRight();
       }
    }
    void RobotControl::forward() { //! İleri gidiş için naoRabotINT üzerinden fonksiyonu çağırdım.
      if(control == true){
        naoRobotINT.forward();
       }
    }
    void RobotControl::backward() { //! Geri gidiş için naoRabotINT üzerinden fonksiyonu çağırdım.
      if(control == true){
        naoRobotINT.backward();
       }        
    }
    void RobotControl::moveLeft() { //! Sola hareket için naoRabotINT üzerinden fonksiyonu çağırdım.
      if(control == true){
        naoRobotINT.moveLeft();
       }      
    }
    void RobotControl::moveRight() { //! Sağa hareket için naoRabotINT üzerinden fonksiyonu çağırdım.
      if(control == true){
        naoRobotINT.moveRight();
       }        
    }
    void RobotControl::stop() { //! Durması için naoRabotINT üzerinden fonksiyonu çağırdım.
      if(control == true){
        naoRobotINT.stop();
       }        
    }
    bool RobotControl::addToPath(){ //! İzlenen yeni yolun güzergahını eklemek için
        path.addPos(position->getPose()); //! yeni pozisyon getpose fonk. üzerinden path classının addpos fonk. ile eklenecek
    }
    void RobotControl::clearPath(){ //! path'e kayıtlı tüm kaydedilmiş güzergahları silecek
      int listSize = path.getSize(); //! path'e kayıtlı son path'i silen fonk. döngü içerisinde tüm listeyi silecek şekilde kullanılmıştır.
      for(int i=0; i<listSize; i++){
        path.removePos(i);
      }
    }
    bool RobotControl::recordPathToFile(){ //! Belirlenen path'i dosyaya kaydedecek.
      rec.setFileName("yaz.txt"); //! Record classından dosyaya isim verir.
      if(rec.openFile()){ //! Record classından dosya açar
        int listSize = path.getSize();
        for(int i=0; i<listSize; i++){
        rec.writeLine(path.getPos(i).getPoseValue()); //! Record classından dosyaya yazar
        }
        rec.closeFile(); //! Record classından dosyayı kapatır.
      }
      else
        cout<<"DOSYAYA YAZMADI."<<endl;
    }
    bool RobotControl::openAccess(int sayi){ //! RobotOperator üzerinden giriş işlemleri düzenlenmiştir.
        if(robotOp.checkAccessCode(sayi)){ //! Olcay Gündoğdu ile birlikte hazırlanmıştır.
          control=true;
          return control;
        }
        else
        return control;
    }
    bool RobotControl::closeAccess(int sayi){ //! Olcay Gündoğdu ile birlikte hazırlanmıştır.
      if(robotOp.checkAccessCode(sayi)){ //! RobotOperator üzerinden çıkış işlemleri düzenlenmiştir.
          control=false;
          return control;
        }
        else{
          control=false;
          return control;
        }
    }
    bool RobotControl::recordSensor(string type){ //! Sensör seçmek ve kaydetmek için hazırlanmıştır.
       list<SensorInterface>::iterator it= sensorList.begin(); //! Ozan Çelikkol ile birlikte hazırlanmıştır.
         for(it=sensorList.begin(); it!=sensorList.end(); it++){
            if(type == it->getSensorType()){
              
            }
         }

         
    }
    void RobotControl::printSensor(string type){//! Ozan Çelikkol ile birlikte hazırlanmıştır.
        if(control == true){ //! Sensördeki verileri yazdırmak için hazırlanmıştır.
         list<SensorInterface>::iterator it= sensorList.begin();
         for(it=sensorList.begin(); it!=sensorList.end(); it++){
            if(type == it->getSensorType()){
                cout << it->getSensorType() << endl;
            }
         }
        }
    }
    void RobotControl::addSensor(SensorInterface* sensor){ //! Yeni sensörü sensorList listesine eklemek için hazırlanmıştır.
        sensorList.push_back(sensor);
    }

