# Created by: Tom Carrick <knyghtmare@knyghtmare.com>
# $FreeBSD$

PORTNAME=	dosbox
PORTVERSION=	0.74
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	knyght@gmail.com
COMMENT=	Emulator of a PC with DOS

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_SDL=	sdl net sound
PLIST_FILES=	bin/dosbox
PORTDOCS=	NEWS README

MAN1=		dosbox.1
PKGMESSAGE=	${WRKDIR}/pkg-message

CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-core-inline

DESKTOP_ENTRIES="DOSBox" "${COMMENT}" \
		"" "dosbox" \
		"System;Emulator;" "true"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#\/usr\/share\/doc\/dosbox#${DOCSDIR}#g' \
		${WRKSRC}/docs/dosbox.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox ${PREFIX}/bin/dosbox
	${INSTALL_MAN} ${WRKSRC}/docs/dosbox.1 ${MAN1PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
