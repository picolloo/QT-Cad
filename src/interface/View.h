#pragma once
#ifndef INCLUDED_VIEW_H
#define INCLUDED_VIEW_H

#include <QWidget>
#include "../data/Point.h"
#include <QPainter>

class Manager;
class Geometry;

class View : public QWidget
{
   Q_OBJECT

	Manager* manager;

   QPainter painter;
   QPixmap map;
   QTransform transform;

   int scale;
   bool draw;

   int x,y;

   void setShortcuts();
public:
   ~View() {}
	View(Manager* m, QWidget* parent = 0);	

   /////SCALE
   int getScale() const { return scale; }
   void setScale(const int s);
   
   void changeViewPort(Point point);
   void changeScale(double percent);
   Point getWorldPos(QPoint pos);

   /////SAVE
   std::string getSavePath();
   std::string getLoadPath();
   void saveFile(); 

   /////DRAW
   void clearMap();
   void setDraw(bool status) { draw = status; setMouseTracking(status); }

   void clearAllItems();
   void clearLastItem();

   void drawInScreen( Geometry& geo);
   void drawMap(Geometry& geo);

   QPainterPath getPath( Geometry& geo) const;

   /////CAST
   static Point qpointToPoint(QPoint p);
   static QPoint pointToQPoint(Point p1);

   /////START CMD MAIN
   void startLineCommand() const;
   void startBezierCommand() const;
   void startArchCommand() const;
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
   
   void paintEvent(QPaintEvent* event) override;
};

#endif