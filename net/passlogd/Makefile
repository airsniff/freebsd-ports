# New ports collection makefile for:	passlogd
# Date Created:				10 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	passlogd
PORTVERSION=	0.1f
CATEGORIES=	net
MASTER_SITES=	http://www.morphine.com/void/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Intercept and dump syslog remote log packets

PLIST_FILES=	sbin/passlogd

post-patch:
	${REINPLACE_CMD} -e "s|.(CXX)|${CC} ${CFLAGS}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/passlogd ${PREFIX}/sbin

.include <bsd.port.mk>
