# New ports collection makefile for:	schedutils
# Date created:		2012-03-12
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	schedutils
PORTVERSION=	0.7.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of realtime scheduling tools

LICENSE=	BSD

GNU_CONFIGURE=	yes
MANCOMPRESSED=	no

MAN8=		sched.8
MLINKS=		sched.8 resched.8

post-patch:
	${REINPLACE_CMD} -e '/ctype.h/d' ${WRKSRC}/isnumber.c

.include <bsd.port.mk>
