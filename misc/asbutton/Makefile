# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asbutton
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asbutton/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays 4 or 9 buttons to run apps of your choice

USE_XORG=	x11 xpm
ALL_TARGET=	asbutton
MAKE_ARGS=	INCLUDES="-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include" \
		LIBINC="-L${LOCALBASE}/lib" LIBS="-lm -lX11 -lXpm -lXext" \
		CCFLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's:gcc :${CC} :' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asbutton ${PREFIX}/bin
	@${ECHO} "===>   Installing icons in ${PREFIX}/share/asbutton"
	@${MKDIR} ${PREFIX}/share/asbutton && ${CHMOD} a+rx ${PREFIX}/share/asbutton
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/share/asbutton

post-install:
	@${ECHO} "===>   Installing sample asbuttonrc in ${PREFIX}/share/examples/asbutton"
	@${ECHO} "===>   Copy to ~/.asbuttonrc and modify to desired config."
	@${MKDIR} ${PREFIX}/share/examples/asbutton && ${CHMOD} a+rx ${PREFIX}/share/examples/asbutton
	${INSTALL_DATA} ${WRKSRC}/.asbuttonrc ${PREFIX}/share/examples/asbutton/asbuttonrc && ${CHMOD} u+rw ${PREFIX}/share/examples/asbutton/asbuttonrc
	@${ECHO} "===>   Use 'asbutton -h' for help."

.include <bsd.port.post.mk>
