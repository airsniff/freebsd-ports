# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	thegrind
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/ld21/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A simple game about escaping from work

LICENSE=	GPLv2

LIB_DEPENDS=	radius:${PORTSDIR}/graphics/radius-engine \
		lua-5.1:${PORTSDIR}/lang/lua \
		png15:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USES=		pkgconfig
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl sound
USE_GL=		glu
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications

PORTDATA=	*
PORTDOCS=	ChangeLog

.include <bsd.port.options.mk>

post-install:
# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
