#include "CmdSave.h"
#include <fstream>
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"

//#include <QMessageBox>
//#include <QFileDialog>
//#include <QMap>

void CmdSave::execute(Data& d, MainScreen& s)
{
   
   std::string fileName = s.getFileName();

   std::ofstream stream;

   std::deque<Geometry*> itens = d.getGeometries();

   stream.open(fileName, std::ios::out | std::ios::binary);

   if ( stream.is_open())
   {
      stream.seekp(0);

      for ( int i= 0; i < itens.size(); i++)
      {
         Geometry* geo = itens.at(i);

         int form;

         if (Line* line = dynamic_cast<Line*>(geo))
            form = 0;

         else if (Bezier* bezier= dynamic_cast<Bezier*>(geo))
            form = 1;

         else
            form = 2;

         stream.write((char*)&form,sizeof(int));
                  

         for (int j= 0; i < geo->getPoints().size(); j++) {

            stream.write((char*)&geo->getP1().x,sizeof(int));
            stream.write((char*)&geo->getP1().y,sizeof(int));

            stream.write((char*)&geo->getP2().x,sizeof(int));
            stream.write((char*)&geo->getP2().y,sizeof(int));

            if ( form > 0 )
            {
               if (Bezier* bezier= dynamic_cast<Bezier*>(geo))
               {
                  stream.write((char*)bezier->getP3().x,sizeof(int));
                  stream.write((char*)bezier->getP3().y,sizeof(int));
               }
               else if (Arch* arch= dynamic_cast<Arch*>(geo))
               {
                  stream.write((char*)arch->getP3().x,sizeof(int));
                  stream.write((char*)arch->getP3().y,sizeof(int));
               }
            }
         }
      }
   }



  /* const QString fileName = QFileDialog::getSaveFileName(s.getView(),QString("Save File"),"",QString("Dat files (*.dat)"));

   QFile file(fileName);

   QMap<qint64,int> mapX;
   QMap<qint64,int> mapY;

   
      
   if ( file.open(QIODevice::WriteOnly))
   {  
      if (s.getView()->getScene()->items().isEmpty())
         return;

      for ( int i= 0; i < itens.size(); i++)
      {
         std::vector<Point> points = itens.at(i)->getPoints();

         for (int j = 0; j < points.size(); j++) {
            mapX.insert(j,points.at(j).x);
            mapY.insert(j,points.at(j).y);           
         }
      }

      QDataStream out(&file);
      out.setVersion(QDataStream::Qt_5_9);

      out << mapX;
      out << mapY;

      file.flush();
      file.close();
   }
   else
      QMessageBox::information(s.getView(),QString("Unable to open file"), file.errorString()); */
}
