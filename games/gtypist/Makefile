# $FreeBSD$

PORTNAME=	gtypist
PORTVERSION=	2.9.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS=no
CPPFLAGS=	-I${WRKDIR}/include
MAKE_JOBS_SAFE=	yes

INFO=		gtypist gtypist.cs gtypist.es
MAN1=		gtypist.1 typefortune.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# wide curses header expected at <ncursesw/ncurses.h>
pre-configure:
	@${MKDIR} ${WRKDIR}/include
	@${LN} -sf /usr/include ${WRKDIR}/include/ncursesw

.include <bsd.port.mk>
