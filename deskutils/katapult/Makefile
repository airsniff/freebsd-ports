# New ports collection makefile for:	katapult
# Date created:				11 October 2006
# Whom:					Yu-Xi Lim <yuxi@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	katapult
PORTVERSION=	0.3.2.2
PORTREVISION=	5
CATEGORIES=	deskutils kde
MASTER_SITES=	SF

MAINTAINER=	yuxi@gmx.net
COMMENT=	Fast, extensible launcher for KDE similar to Quicksilver on OSX

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${PREFIX}/lib/ ${PREFIX}/lib/kde3/
USES=		gettext
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
