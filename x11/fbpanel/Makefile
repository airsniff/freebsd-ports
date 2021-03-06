# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	fbpanel
PORTVERSION=	6.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF
EXTRACT_SUFX=	.tbz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lightweight, NETWM compliant X11 desktop panel

LICENSE=	MIT

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes
USE_GNOME=	gtk20
USES=		pkgconfig

MAN1=		${PORTNAME}.1

PORTDOCS=	CHANGELOG CREDITS NOTES README

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="${PORTNAME}" "${PORTNAME} NETWM compliant X11 desktop panel" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "System;" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/scripts/install.sh
	@${REINPLACE_CMD} -e 's|@DATADIR@|${DATADIR}|' \
		${WRKSRC}/data/man/${MAN1}.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/data/man/${MAN1} ${MAN1PREFIX}/man/man1/
	${LN} -sf ${DATADIR}/images/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
