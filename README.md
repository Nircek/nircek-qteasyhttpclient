# Nircek-QTEasyHTTPClient
Easy to use function qteasyhttpclient(QString uri, QObject *parent=nullptr).
When a HTTP Error occures, returns '/' and HTTP status. For example: "/500", "/404".
## Example
```c++
int main(int argc, char* argv[])
{
    QApplication qapp(argc,argv);//Why this is needed?
    qDebug()<<qteasyhttpclient("http://localhost/pop.php",&qapp);
    return 0;
}
```
