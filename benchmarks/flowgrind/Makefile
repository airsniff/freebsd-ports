# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	flowgrind
PORTVERSION=	0.5.9
CATEGORIES=	benchmarks
MASTER_SITES=	http://launchpad.net/flowgrind/trunk/${PORTNAME}-${PORTVERSION}/+download/

MAINTAINER=	lars@eggert.org
COMMENT=	Measure throughput and other metrics for TCP

LIB_DEPENDS=	xmlrpc++:${PORTSDIR}/net/xmlrpc-c \
		gsl:${PORTSDIR}/math/gsl
BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.so:${PORTSDIR}/net/libpcap

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
FETCH_ARGS=	-pRr

MAN1=		flowgrind-stop.1 \
		flowgrind.1 \
		flowgrindd.1

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
