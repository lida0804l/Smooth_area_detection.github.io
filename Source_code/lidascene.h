#ifndef LIDASCENE_H
#define LIDASCENE_H

#include <QGraphicsView>
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QStack>
#include <lidaimage.h>
#include <math.h>
//#include <fouriertransform.h>
//#include <lida.h>

using namespace std;

class LidaScene : public QGraphicsScene
{
public:
    LidaScene();

    QImage* image;
//    FourierTransform* freq;

    LidaImage* lidaimage;
    QGraphicsPixmapItem* pixmap_item;
    QStack<QGraphicsRectItem*> rect_stacks;
    QStack<QGraphicsRectItem*> rect_stacks_removed;

    int rect_nums_row;
    int rect_nums_col;
    void nonSmooth_detect_update(int rect_nums_row = 100, int rect_nums_col = 200, float Entropy_thresh = 2.5);

//private:


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);

    void mouseMoveEvent(QGraphicsSceneMouseEvent*);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
};

#endif // LIDASCENE_H
