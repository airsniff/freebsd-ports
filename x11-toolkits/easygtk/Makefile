# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easygtk
PORTVERSION=	1.2
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
EXTRACT_SUFX=	.tar

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A wrapper library for GTK+ which provides simplified GUI API

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnomelibs
USE_LDCONFIG=	yes
MAKE_ENV=	MKDIR="${MKDIR}" \
		LN="${LN}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libeasygtk.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/easygtk.h ${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/libeasygtk.so.1 ${PREFIX}/lib/
	${LN} -sf ${PREFIX}/lib/libeasygtk.so.1 ${PREFIX}/lib/libeasygtk.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/manual.html ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
