# Created by: Douglas Carmichael <dcarmich@dcarmichael.net>
# $FreeBSD$

PORTNAME=	kdevelop
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-pg-qt
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser-generator from KDevplatform

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_GCC=	4.6+
USE_BZIP2=	yes
USES=		bison
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USES+=		cmake:outsource
USE_QT4=	qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
