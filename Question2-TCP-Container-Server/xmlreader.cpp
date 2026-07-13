#include "xmlreader.h"
#include <QDebug>
#include <QRegularExpression>
XmlReader::XmlReader() {
}

bool XmlReader::checkCode(const QString &c) const
{
    qDebug() << c ;
    QRegularExpression re(R"(^(20[0-9]{2})\/(0[1-9]|1[0-2])\/([BC])([1-9][0-9]{0,3})$)");

    QRegularExpressionMatch match = re.match(c);

    return match.hasMatch();


}

void XmlReader::parseXml(const QByteArray &xmlData)
{

    QDomDocument doc;
    if (!doc.setContent(xmlData)) {
        qDebug() << "Failed to parse XML";
        return;
    }

    QDomElement root = doc.documentElement(); // <pallets>
    QDomNodeList palletNodes = root.elementsByTagName("pallet");

    for (int i = 0; i < palletNodes.count(); ++i) {
        QDomElement palletElem = palletNodes.at(i).toElement();
        QString palletNumber = palletElem.attribute("number");
        QString palletWeight = palletElem.attribute("weight");
        QString palletVolume = palletElem.attribute("volume");

        QDomNode containerNode = palletElem.firstChild();
        while (!containerNode.isNull()) {
            QDomElement containerElem = containerNode.toElement();
            QString type = containerElem.tagName(); // Box or Cylinder
            qDebug() << "Type" << type;

            QString code = containerElem.firstChildElement("code").text();
            QString weight = containerElem.firstChildElement("weight").text();
            QString height = containerElem.firstChildElement("height").text();
            QString length, breadth, diameter;
            if (type == "Box") {
                length = containerElem.firstChildElement("length").text();
                breadth = containerElem.firstChildElement("breadth").text();
            }
            else if (type == "Cylinder") {
                diameter = containerElem.firstChildElement("diameter").text();
            }

            QStringList list;

            list.append(palletNumber);
            list.append(type);

            if(checkCode(code))
                list.append(code);
            else
                list.append("****");

            list.append(height);

            if(type == "Box")
            list.append(breadth);
            else
                list.append(diameter);

            list.append(length);
            list.append(weight);

            emit sendItems(list);
            containerNode = containerNode.nextSibling();


        }
    }

}

