# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	mousepad
PORTVERSION=	0.3.0
CATEGORIES=	editors xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=	desktop-file-utils gettext pathfix pkgconfig
USE_GNOME=	glib20 gtk20 intltool intlhack gtksourceview2
USE_XFCE=	configenv
USE_PERL5=	yes

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=	DBUS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.include <bsd.port.mk>
