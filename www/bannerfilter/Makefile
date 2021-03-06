# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	bannerfilter
PORTVERSION=	1.31
CATEGORIES=	www
MASTER_SITES=	http://phroggy.com/files/unix/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Squid redirect script for filtering web banners

LICENSE=	GPLv2

RUN_DEPENDS=	squid:${PORTSDIR}/www/squid

USES=		shebangfix
USE_PERL5=	yes
NO_BUILD=	yes

WWW_ROOT?=	www
PLIST_SUB+=	WWW_ROOT="${WWW_ROOT}"
CONFIG_FILES=	bannerfilter.conf banners.data banners.local.data \
		exceptions.data exceptions.local.data frames.data \
		frames.local.data popups.data popups.local.data

SHEBANG_FILES=	redirector.pl

post-patch:
	@${REINPLACE_CMD} -e \
		's|^;\ \(DATA\ =\ \).*|\1${PREFIX}/etc/${PORTNAME}/|' \
		${WRKSRC}/${PORTNAME}.conf
	@${REINPLACE_CMD} -e \
		's|^\(CONFIGDIR=\).*|\1"${PREFIX}/etc/${PORTNAME}"|' \
		${WRKSRC}/update.sh

do-install:
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/redirector.pl ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/update.sh \
		${PREFIX}/bin/update-bannerfilter-rules
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${PORTNAME}/${f}.default
.if !exists(${PREFIX}/etc/${PORTNAME}/${f})
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${PORTNAME}
.endif
.endfor
	${CP} -R ${WRKSRC}/www ${PREFIX}/${WWW_ROOT}/${PORTNAME}

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==========================================================================="
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please add the following redirector config directive to your squid.conf:"
	@${ECHO_MSG} "   redirect_program ${PREFIX}/libexec/bannerfilter/redirector.pl"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Make sure ${PREFIX}/${WWW_ROOT}/${PORTNAME} is available under"
	@${ECHO_MSG} "   http://localhost/${PORTNAME}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==========================================================================="
	@${ECHO_MSG} ""

.include <bsd.port.mk>
