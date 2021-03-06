# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	gspiceui
PORTVERSION=	1.0.00
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/gSpiceUI/${PORTNAME}-v${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GUI frontend to gnucap and ngspice circuit simulators

LICENSE=	GPLv2

RUN_DEPENDS=	# none if no options are set

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_GROUP=	BACKEND VIEWER

OPTIONS_GROUP_BACKEND=	GNUCAP NGSPICE
OPTIONS_GROUP_VIEWER=	GWAVE

GNUCAP_DESC=	Depend on gnucap as a simulation backend
NGSPICE_DESC=	Depend on ngspice as a simulation backend
GWAVE_DESC=	Depend on gwave waveform viewer

OPTIONS_DEFAULT=	NGSPICE GWAVE

USE_WX=		2.6+
WX_UNICODE=	yes
USE_GCC=	4.6+
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES=	"GSpiceUI" "Circuit Simulator GUI" \
			"${PREFIX}/share/pixmaps/gspiceui-48x48.xpm" \
			"gspiceui" "Science;Electronics;" false

MAN1=		gspiceui.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gspiceui share/pixmaps/gspiceui-48x48.xpm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUCAP}
RUN_DEPENDS+=	gnucap:${PORTSDIR}/cad/gnucap
.endif

.if ${PORT_OPTIONS:MNGSPICE}
RUN_DEPENDS+=	ngspice:${PORTSDIR}/cad/ngspice_rework
.endif

.if ${PORT_OPTIONS:MGWAVE}
RUN_DEPENDS+=	gwave:${PORTSDIR}/cad/gwave
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|:= -Ofast -pipe|+= -I.|g ; \
		 s|^INCLUDES |#INCLUDES |g ; \
		 s|$$(WXCFG)|$$(WX_CONFIG)|g ; \
		 s|$$(CC)|$$(CXX)|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e \
		's|share/gspiceui|${DOCSDIR}|g' \
		${WRKSRC}/src/main/HelpTasks.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gspiceui ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/icons/gspiceui-48x48.xpm \
	    ${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/gspiceui.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for dir in html
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DOCSDIR} \
		"! -name Makefile")
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for dir in lib sch
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${EXAMPLESDIR} \
		"! -name Makefile")
.endfor
.endif

.include <bsd.port.mk>
