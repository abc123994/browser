#include<qobject.h>
#include <QWebEngineView>
#include<QWebEngineProfile>
#include<QWebEngineSettings>
#include<qwebenginepage.h>
#include<QWebEngineFullScreenRequest>
#include<qurl.h>
class broswer;
class web:public QObject {
	Q_OBJECT
public:
	web(QObject* parent = nullptr);
	~web();
	QWebEngineView*  getView();
	void setBroswer(broswer* b);
	void setUrl(QUrl url);
private:
	void init();
	QWebEngineView* m_web_engine; 
	QWebEngineProfile* m_web_profile;

	broswer* m_broswer;
};