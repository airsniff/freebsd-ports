# Created by: KANOU Hiroki <kanou@mil.allnet.ne.jp>
# $FreeBSD$

PORTNAME=	kochi
PORTVERSION=	20030809
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/efont/5411/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	${PORTNAME}-substitute-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Kochi Japanese TrueType font

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR} \
		DATADIR=share/font-${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

PORTDOCS=	README.ja COPYING docs

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${LN} -s -f \
		${DATADIR}/*.ttf ${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TTF
	${LN} -s -f \
		${DATADIR}/*.ttf ${PREFIX}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
		${FILESDIR}/62-fonts-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
