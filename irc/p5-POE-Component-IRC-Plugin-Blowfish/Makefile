# New ports collection makefile for:	POE-Component-IRC-Plugin-Blowfish
# Date created:	   June 05 2010
# Whom:		   Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC-Plugin-Blowfish
PORTVERSION=	0.01
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLU
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin tthat provides blowfish encryption

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=0.37:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-IRC>=5.07:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-Crypt-Blowfish_PP>=1.12:${PORTSDIR}/security/p5-Crypt-Blowfish_PP
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC::Plugin::Blowfish.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
