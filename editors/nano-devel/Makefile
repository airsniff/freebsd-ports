#
# $FreeBSD$

PORTNAME=	nano
PORTVERSION=	2.3.2
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v${PORTVERSION:R}/ \
		${MASTER_SITE_GNU}
PKGNAMESUFFIX=	-devel

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

CONFLICTS=	nano-2*

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
MANLANG=	"" fr
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	install_htmlmanDATA=install-htmlmanDATA
.else
MAKE_ARGS+=	install_htmlmanDATA=""
.endif

INFO=		nano
MAN1=		nano.1 rnano.1
MAN5=		nanorc.5

PORTSCOUT=	limitw:1,odd

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--enable-utf8

post-build:
	cd ${WRKSRC}/doc/man; ${REINPLACE_CMD} \
		-e 's:SYSCONFDIR:${PREFIX}/etc:g' \
		-e 's:EXAMPLESDIR:${EXAMPLESDIR}:g' \
		${MAN1} ${MAN5} ${WRKSRC}/doc/texinfo/${INFO:=.info}
	${REINPLACE_CMD} -e 's/\\</[[:<:]]/g' -e 's/\\>/[[:>:]]/g' \
		${WRKSRC}/doc/syntax/*.nanorc

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/nanorc.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
