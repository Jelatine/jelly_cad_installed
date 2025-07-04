#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    // 创建应用程序对象
    QApplication app(argc, argv);
    
    // 设置字符编码（Qt5中处理中文）
    // QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    
    // 创建主窗口
    QWidget window;
    window.setWindowTitle(QString::fromUtf8("我的第一个Qt5程序"));
    window.resize(300, 200);
    
    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout;
    
    // 创建标签
    QLabel *label = new QLabel(QString::fromUtf8("Hello, Qt5!"));
    label->setAlignment(Qt::AlignCenter);
    
    // 创建按钮
    QPushButton *button = new QPushButton(QString::fromUtf8("点击我"));
    
    // 连接按钮点击事件
    QObject::connect(button, &QPushButton::clicked, [&]() {
        QMessageBox::information(&window, QString::fromUtf8("消息"), QString::fromUtf8("按钮被点击了！"));
    });
    
    // 将控件添加到布局中
    layout->addWidget(label);
    layout->addWidget(button);
    
    // 设置窗口的布局
    window.setLayout(layout);
    
    // 显示窗口
    window.show();
    
    // 运行应用程序事件循环
    return app.exec();
}