# Nircek-QTEasyHTTPClient
Easy to use function qteasyhttpclient(QString uri, QObject *parent=nullptr).
When a HTTP Error occures, returns '/' and HTTP status. For example: "/500", "/404".
## Example
```c++
#include "nircek-qteasyhttpclient/nircek-qteasyhttpclient.h"
using namespace GitHub::Nircek;
int main(int argc, char* argv[])
{
    QApplication qapp(argc,argv);
    qDebug()<<qteasyhttpclient("http://localhost/pop.php",&qapp);
    return 0;
}
```
