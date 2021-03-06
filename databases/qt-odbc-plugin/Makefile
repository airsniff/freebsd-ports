# Created by: Michael Nottebrock <lofi@freebsd.org>
# $FreeBSD$

PORTNAME=	qt-${DB}-plugin
PORTVERSION=	3.3.8
PORTREVISION=	10
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plugin for QT to connect to ODBC-compatible databases

DB=		odbc

LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC \
		qt-mt:${PORTSDIR}/x11-toolkits/qt33
BUILD_DEPENDS=	unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
PLUGIN=		plugins/src/sqldrivers/${DB}
DRIVER=		src/sql/drivers/${DB}
EXTRACT_AFTER_ARGS?=	${DISTNAME}/${PLUGIN} \
			${DISTNAME}/${DRIVER} ${DISTNAME}/src/sql/drivers/cache
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
