# New ports collection makefile for:	xfree86_xkb_xml
# Date created:				31 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfree86_xkb_xml
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	SF/gswitchit/OldFiles

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A little set of XML files useful for dealing with XKB rules

USES=		gettext iconv
USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--with-xkb-base=${LOCALBASE}/lib/X11/xkb
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
