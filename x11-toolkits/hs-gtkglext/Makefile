# $FreeBSD$

PORTNAME=	gtkglext
PORTVERSION=	0.12.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GTK+ OpenGL Extension

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext

LICENSE=	LGPL21

USE_CABAL=	glib>=0.12 gtk>=0.12 mtl pango>=0.12

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
