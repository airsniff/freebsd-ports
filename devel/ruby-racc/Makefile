# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	racc
PORTVERSION=	1.4.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://i.loveruby.net/archive/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-all
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An LALR(1) parser generator for Ruby

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	racc-runtime

CONFIGURE_ARGS=	--with=racc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-all
WRKDIR_RACC=	${WRKSRC}/packages/racc

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR_RACC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKDIR_RACC}/doc.en/*.html ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKDIR_RACC}/doc.ja/*.html ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	Builds but does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
