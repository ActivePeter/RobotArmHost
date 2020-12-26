#include "StrConv.h"

namespace StrConv
{

    QString str2qstr(const std::string str)
    {
        return QString::fromLocal8Bit(str.data());
    }

    std::string qstr2str(const QString qstr)
    {
        QByteArray cdata = qstr.toLocal8Bit();
        return std::string(cdata);
    }
}