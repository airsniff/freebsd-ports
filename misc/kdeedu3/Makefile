# Created by: will@cvs.kde.org
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	6
CATEGORIES?=	misc kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Collection of entertaining, educational programs for KDE

LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs

CONFLICTS+=	kwordquiz-[0-9]* kgeography-[0-9]*

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_XORG=	xpm
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool

CONFIGURE_ARGS+=--enable-libusb=${LOCALBASE} \
		--disable-ocamlsolver

USE_LDCONFIG=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} \
	-e 's|pylibdir in.*|pylibdir in "${LOCALBASE}/lib" \\|g' \
	${WRKSRC}/configure

.include <bsd.port.post.mk>
