#include"web.h"
#include <QApplication>
#include"broswer.h"
web::web(QObject* paraent)
    :QObject(paraent)
    , m_web_engine(new QWebEngineView)
    , m_web_profile(new QWebEngineProfile(qApp->applicationName()))
{
    this->init();
    connect(m_web_engine->page(), &QWebEnginePage::fullScreenRequested, [&]
    (QWebEngineFullScreenRequest fullScreenRequest) {
            fullScreenRequest.accept();
            if (fullScreenRequest.toggleOn() == true) {
                m_broswer->setFrameless(true);
            }
            else {
                m_broswer->setFrameless(false);
            }
            qDebug() << "UI: fullScreenRequested: " << fullScreenRequest.toggleOn();
    });
    

}
web::~web() {


}

QWebEngineView*  web::getView() {

    return m_web_engine;
}
void web::setBroswer(broswer* b) {
    m_broswer = b;
}
void web::setUrl(QUrl url) {
    m_web_engine->load(url);

}
void web::init() {

    m_web_profile->setPersistentCookiesPolicy(QWebEngineProfile::AllowPersistentCookies);
    m_web_profile->setHttpCacheType(QWebEngineProfile::MemoryHttpCache);
    m_web_engine->setPage(new QWebEnginePage(m_web_profile));
    QWebEngineSettings* defaultSettings = m_web_engine->settings();
    defaultSettings->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
    defaultSettings->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    defaultSettings->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows, true);
}
