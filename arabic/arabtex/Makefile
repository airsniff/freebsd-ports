# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	arabtex
PORTVERSION=	3.11
PORTREVISION=	5
CATEGORIES=	arabic print
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/${PORTNAME}/
DISTNAME=	arab${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TeX/LaTeX package to generate Arabic writing

USE_TEX=	base texmf
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

TEXMFLOCAL=	${LOCALBASE}/share/texmf-local
TEXMFLOCAL_LSR=	${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

FIND_DIRS=	-type d \! -empty
FIND_DATA=	-type f
FIND_HERE=	fonts tex

.if !defined(NOPORTDOCS)
FIND_HERE+=	doc
.endif

do-install:
	@cd ${WRKSRC}; \
	DIRS=$$(${FIND} ${FIND_HERE} ${FIND_DIRS}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${TEXMFLOCAL}/$${DIR}; \
	done; \
	FILES=$$(${FIND} ${FIND_HERE} ${FIND_DATA} ); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${TEXMFLOCAL}/$${FILE}; \
	done;

post-install:
	@${MKTEXLSR}

.include <bsd.port.mk>
