#include "lidascene.h"

LidaScene::LidaScene()
{
    //    pixmap_item = new QGraphicsPixmapItem();
    rect_nums_row = 0;
    rect_nums_col = 0;
}

void LidaScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    int x = mouseEvent->scenePos().toPoint().y();
    int y = mouseEvent->scenePos().toPoint().x();

    bool contained = false;
//    cout << rect_stacks.size() << " " << rect_stacks_removed.size() << endl;
    for (int i = 0; i < rect_stacks.size(); i++) {
        QGraphicsRectItem* rect = rect_stacks.at(i);
        if(((rect->rect().y() <= x) && (x <= (rect->rect().y() + rect->rect().height()))) && ((rect->rect().x() <= y) && (y <= (rect->rect().x() + rect->rect().width())))){
            rect_stacks.remove(i);
            i--;
            this->removeItem(rect);
            rect_stacks_removed.push(rect);
            contained = true;
        }
    }

//    cout << rect_stacks.size() << " " << rect_stacks_removed.size() << endl;
    if(contained == false){
        for (int i = 0; i < rect_stacks_removed.size(); i++) {
            QGraphicsRectItem* rect = rect_stacks_removed.at(i);
            if(((rect->rect().y() <= x) && (x <= (rect->rect().y() + rect->rect().height()))) && ((rect->rect().x() <= y) && (y <= (rect->rect().x() + rect->rect().width())))){
                rect_stacks_removed.remove(i);
                i--;
                this->addItem(rect);
                rect_stacks.push(rect);
            }
        }
    }
}

void LidaScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    int x = mouseEvent->scenePos().toPoint().x();
//    int y = mouseEvent->scenePos().toPoint().y();

//    cout << "x: " << x << " "
//         << "y: " << y << " "
////         << "r: " << image->pixelColor(x,y).red() << " "
////         << "g: " << image->pixelColor(x,y).green() << " "
////         << "b: " << image->pixelColor(x,y).blue() << endl;
//         << "r: " << lidaimage->matrix3D[0][y][x] << " "
//         << "g: " << lidaimage->matrix3D[1][y][x] << " "
//         << "b: " << lidaimage->matrix3D[2][y][x] << endl;
////         << "r: " << std::abs(freq->frequency[0][x][y]) << " "
////         << "g: " << std::abs(freq->frequency[1][x][y]) << " "
////         << "b: " << std::abs(freq->frequency[2][x][y]) << endl;
}

void LidaScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    while (!rect_stacks.isEmpty()) {
//        QGraphicsRectItem* rect = rect_stacks.pop();
//        this->removeItem(rect);
//        delete rect;
//    }
}

void LidaScene::nonSmooth_detect_update(int rect_nums_row, int rect_nums_col, float Entropy_thresh)
{
    this->rect_nums_row = rect_nums_row;
    this->rect_nums_col = rect_nums_col;
    int rect_step_row = lidaimage->row / rect_nums_row;
    int rect_step_col = lidaimage->col / rect_nums_col;
//    cout << rect_step_row << " " << rect_step_col << endl;

//    cout << rect_stacks.size() << endl;
    while (!rect_stacks.isEmpty()) {
        QGraphicsRectItem* rect = rect_stacks.pop();
        this->removeItem(rect);
        delete rect;
    }
    while (!rect_stacks_removed.isEmpty()) {
        QGraphicsRectItem* rect = rect_stacks_removed.pop();
        delete rect;
    }

//    cout << rect_stacks.size() << endl;

    float histogram[256];
    for (int x = 0; (x+rect_step_row) < lidaimage->row; x += rect_step_row) {
        for (int y = 0; (y+rect_step_col) < lidaimage->col; y += rect_step_col) {
            for (int i = 0; i < 256; i++) {
                histogram[i] = 0;
            }

            for (int i = 0; i < rect_step_row; i++) {
                for (int j = 0; j < rect_step_col; j++) {
                    int I = (lidaimage->matrix3D[0][x+i][y+j] + lidaimage->matrix3D[1][x+i][y+j] + lidaimage->matrix3D[2][x+i][y+j])/3;
//                    cout << I << " ";
                    histogram[I]++;
                }
            }


            float Entropy = 0;
            for (int i = 0; i < 256; i++) {
                if(histogram[i] > 0.00001){
                    histogram[i] /= (rect_step_row * rect_step_col);
                    Entropy += histogram[i] * std::log2(histogram[i]);
                }
            }
            Entropy *= (-1);
//            cout << Entropy << " ";

            if(Entropy < Entropy_thresh){
                QGraphicsRectItem *rect = new QGraphicsRectItem();
                rect->setRect(y, x, rect_step_col, rect_step_row);
                rect->setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                this->addItem(rect);

                rect_stacks.push(rect);
            }
        }
    }
}
