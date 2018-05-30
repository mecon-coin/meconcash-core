#include "uritests.h"
#include "../guiutil.h"
#include "../walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 1000);

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 1001000);

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?amount=10000&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("meconcash://MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz"));
    QVERIFY(rv.label == QString());

    // We currently don't implement the message parameter (ok, yea, we break spec...)
    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?req-message=Wikipedia Example Address"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("meconcash:MSUcMhFaPcGu29nya53ByYhqBWAtb3xcKz?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
