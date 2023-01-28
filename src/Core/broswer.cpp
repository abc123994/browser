#include"broswer.h"
#include"web.h"
#include"..\Tool\conf.hpp"
broswer::broswer(QWidget* parent) 
    :QWidget(parent)
    ,m_web_view(new web)
    ,m_toolBar(new QToolBar())
    ,is_pin(false)
    ,resizing(false)
    ,is_framless(false)
{
    this->setStyleSheet("background-color:black;");
    this->setContentsMargins(QMargins(0, 0, 0, 0));
    this->setMouseTracking(true);
   
   
    m_toolBar->setStyleSheet("color:white");
    m_toolBar->addAction(m_web_view->getView()->page()->action(QWebEnginePage::Back));
    m_toolBar->addAction(m_web_view->getView()->page()->action(QWebEnginePage::Forward));
    m_toolBar->addAction(m_web_view->getView()->page()->action(QWebEnginePage::Reload));
    m_toolBar->addAction(m_web_view->getView()->page()->action(QWebEnginePage::Stop));
    m_toolBar->addAction("PIN");
    connect(m_toolBar, &QToolBar::actionTriggered, [&](QAction* action) {
       
        if (action->text() == "PIN") {
            if (!is_pin) {
                
                qDebug() << "Action" << action->text() << "triggered!";
                this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
                is_pin = true;
            }
            else {
                this->setWindowFlags(this->windowFlags() & ~Qt::WindowStaysOnTopHint);
                is_pin = false;
            
            }
            
            
            this->show();
        }
    
    });
    
    m_web_view->setBroswer(this);

    QString mainpage = settings.value("main/page", "https://www.youtube.com").toString();
    m_web_view->setUrl(QUrl(mainpage));
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(m_toolBar);
    layout->addWidget(m_web_view->getView());
    this->setLayout(layout);
    this->show();
}
broswer::~broswer() {
    delete m_web_view;

}

void broswer::setFrameless(bool flag) {

    if (flag) {
        this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
        is_framless = true;
        m_toolBar->hide();
    }
    else {
        this->setWindowFlags(this->windowFlags() & (~Qt::FramelessWindowHint));
        is_framless = false;
        m_toolBar->show();
        
    }
    this->show();
}


void broswer::mousePressEvent(QMouseEvent* event)
{
    if(is_framless)
        if (event->button() == Qt::LeftButton) {
            pressPos = event->pos();
            if (event->pos().x() > width() - border &&
                event->pos().y() > height() - border) {
                resizing = true;
            }
        }
}

void broswer::mouseMoveEvent(QMouseEvent* event)
{
    if(is_framless)
        if (resizing) {
            int dx = event->x() - pressPos.x();
            int dy = event->y() - pressPos.y();
            pressPos = event->pos();
            setGeometry(x(), y(), width() + dx, height() + dy);
        }
}

void broswer::mouseReleaseEvent(QMouseEvent* event)
{
    if(is_framless)
        if (event->button() == Qt::LeftButton) {
            resizing = false;
        }
}