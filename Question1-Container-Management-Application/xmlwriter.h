#ifndef XMLWRITER_H
#define XMLWRITER_H

#include "pallet.h"
class XmlWriter
{
public:
    XmlWriter();
    QByteArray generateXml(Pallet *pallets);
};

#endif // XMLWRITER_H
