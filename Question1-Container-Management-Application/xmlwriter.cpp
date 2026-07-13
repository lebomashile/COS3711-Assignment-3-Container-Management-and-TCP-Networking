#include "xmlwriter.h"
#include "pallet.h"
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include "box.h"
#include "cylinder.h"

XmlWriter::XmlWriter() {}

QByteArray XmlWriter::generateXml(Pallet *pallets)
{
    QByteArray message;
    QXmlStreamWriter stream(&message);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("Pallets");
    stream.writeAttribute("NumberOfPallets", QString::number(pallets->getPallets().size()));

    int w = 0;
    int v = 0;
    int currentPalletNum = -1;

    for (int i = 0; i < pallets->getPallets().size(); ++i) {
        Container *c = pallets->getPalletAt(i);
        int tempNum = pallets->getPalletNumber(c->getCode());

        if (tempNum != currentPalletNum) {

            if (currentPalletNum != -1) {
                stream.writeEndElement();

            }

                currentPalletNum = tempNum;

            stream.writeStartElement("pallet");
            w += c->getWeight();
            v += c->calculateVolume();

            stream.writeAttribute("weight", QString::number(w));
            stream.writeAttribute("volume", QString::number(v));
            stream.writeAttribute("number", QString::number(currentPalletNum));

            w = 0;
            v = 0;

        } else {

            w += c->getWeight();
            v += c->calculateVolume();
        }

        const QMetaObject *metaObj = c->metaObject();
        QString className = metaObj->className();
        stream.writeStartElement(className);

        if (className == "Box") {
            Box *box = qobject_cast<Box *>(c);
            stream.writeTextElement("code", box->getCode());
            stream.writeTextElement("height", QString::number(box->getHeight()));
            stream.writeTextElement("weight", QString::number(box->getWeight()));
            stream.writeTextElement("length", QString::number(box->Length()));
            stream.writeTextElement("breadth", QString::number(box->Breadth()));
        } else if (className == "Cylinder") {
            Cylinder *cylinder = qobject_cast<Cylinder *>(c);
            stream.writeTextElement("code", cylinder->getCode());
            stream.writeTextElement("height", QString::number(cylinder->getHeight()));
            stream.writeTextElement("weight", QString::number(cylinder->getWeight()));
            stream.writeTextElement("diameter", QString::number(cylinder->Diameter()));
        }

        stream.writeEndElement();
    }


    if (currentPalletNum != -1) {
        stream.writeEndElement();
    }

    stream.writeEndElement();
    stream.writeEndDocument();

    return message;
}
