# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	sisc
PORTVERSION=	1.16.6
PORTREVISION=	2
CATEGORIES=	lang scheme java
MASTER_SITES=	SF/${PORTNAME}/SISC/${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	An extensible Java-based Scheme interpreter

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
PORTDOCS=	COPYING README

post-patch:
	${REINPLACE_CMD} -e 's|\(SISC_HOME=\).*$$|\1${DATADIR}|' \
		-e 's|\(JAVA=\)java|\1"${LOCALBASE}/bin/java" ; export JAVA_VERSION="${JAVA_VERSION}"|' \
		${WRKSRC}/sisc
	${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' \
		${WRKSRC}/scheme-src/srfi-22/srfi-22.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sisc ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${WRKSRC}/*.shp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/scheme-src/*.scm ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scheme-src/srfi-22/srfi-22.sh ${PREFIX}/bin
.for i in r4rs r5rs srfi-0 srfi-7 ieee-1178-1900
	${LN} -sf ${PREFIX}/bin/srfi-22.sh ${PREFIX}/bin/scheme-${i}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README ${DOCSDIR}
.endif

.include <bsd.port.mk>
