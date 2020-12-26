#ifndef __STRCONV_H__
#define __STRCONV_H__
#include <QString>
#include <QByteArray>

namespace StrConv
{
    QString str2qstr(const std::string str);

    std::string qstr2str(const QString qstr);
} // namespace StrConv
#endif // __STRCONV_H__