# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easytag
PORTVERSION=	2.1.8
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK2 Tag editor for MP3 and OGG files

LIB_DEPENDS=	id3:${PORTSDIR}/audio/id3lib \
		id3tag:${PORTSDIR}/audio/libid3tag \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		mp4v2:${PORTSDIR}/multimedia/mp4v2

MAN1=		easytag.1
CONFLICTS=	easytag-devel-[0-9]*

USE_XZ=		yes
USES=		gettext
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 desktopfileutils
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GTK
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_WAVPACK)
LIB_DEPENDS+=		wavpack:${PORTSDIR}/audio/wavpack
CONFIGURE_ARGS+=	--enable-wavpack
.else
CONFIGURE_ARGS+=	--disable-wavpack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<mp4\.h>|<mp4v2/mp4v2.h>|g' \
		${WRKSRC}/src/mp4_header.c \
		${WRKSRC}/src/mp4_tag.c

.include <bsd.port.mk>
