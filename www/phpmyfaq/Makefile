# Created by: chinsan <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	phpmyfaq
PORTVERSION=	2.8.0
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	A multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	filter json mysql pcre pdf session xml xmlrpc xmlwriter zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

do-install:
	-${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}
.for i in ${FAQ_DIR}
	-@${MKDIR} ${WWWDIR}/${i}
	@${CHMOD} 777 ${WWWDIR}/${i}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
