# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#   $MCom: ports-stable/math/gnumeric/Makefile,v 1.5 2010/06/29 11:24:22 kwm Exp $
# When updating, remember to update pkg-plist of gchemutils.

PORTNAME=	gnumeric
PORTVERSION=	1.10.17
PORTREVISION=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNOME 2 spreadsheet

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	goffice-0.8:${PORTSDIR}/devel/goffice \
		psiconv:${PORTSDIR}/converters/psiconv
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_XZ=		yes
USE_GMAKE=	yes
USES=		pathfix gettext
USE_GNOME=	gnomeprefix intlhack gnomehier pygtk2 \
		desktopfileutils libgsf
USE_PYTHON=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome=no --disable-silent-rules
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}" \
		python_prog=${PYTHON_VERSION}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
MAKE_JOBS_SAFE=	yes

GLIB_SCHEMAS=	org.gnome.gnumeric.dialogs.gschema.xml \
		org.gnome.gnumeric.gschema.xml \
		org.gnome.gnumeric.plugin.gschema.xml

MAN1=		gnumeric.1 ssconvert.1 ssindex.1 ssgrep.1

PLIST_SUB=	VERSION=${PORTVERSION} GOFFICE=0.8.17

OPTIONS_DEFINE=	PERL
OPTIONS_DEFAULT=PERL
PERL_DESC=	Support Perl as extension language

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		PERL="@comment "
.endif

#.if defined(WITH_GNOMEDB)
#USE_GNOME+=		libgnomedb
#CONFIGURE_ARGS+=	--with-gda
#PLIST_SUB+=		GNOMEDB=""
#.else
CONFIGURE_ARGS+=	--without-gda
PLIST_SUB+=		GNOMEDB="@comment "
#.endif

post-patch:
	@${RM} -f ${WRKSRC}/GNOME_Gnumeric.server.in
	@${REINPLACE_CMD} -e 's|gda-3.0 >= 3.1.1|gda-3.0 >= 3.0.1|g' \
		-e 's|gnomedb-3.0 >= 3.0.1|gnomedb-3.0 >= 3.0.0|g' \
		-e 's|gnumeric_with_gconf=true|gnumeric_with_gconf=false|g' \
			${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnumeric.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gnumeric.mime ${PREFIX}/share/mime-info
	@-update-desktop-database
.for dir in share lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.mk>
