# New ports collection makefile for:	asclock-gtk
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asclock-gtk
PORTVERSION=	2.1.10
PORTREVISION=	7
CATEGORIES=	x11-clocks afterstep windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	${PORTNAME}-${PORTVERSION}beta

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	New flavor of asclock (GTK version)

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	asclock

USE_XORG=	x11 xt
USE_GNOME=	gtk12
HAS_CONFIGURE=	yes

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

.if defined(BATCH)
do-configure:
	@(cd ${WRKSRC}; \
	  ${RM} -rf default_theme; \
	  ${LN} -s themes/classic default_theme)
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/asclock

.include <bsd.port.mk>
