# New ports collection makefile for:	AnyEvent::SCGI
# Date created:		16 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-SCGI
PORTVERSION=	1.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Event based SCGI server

RUN_DEPENDS=	\
	p5-AnyEvent>=5.2:${PORTSDIR}/devel/p5-AnyEvent
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::SCGI.3

.include <bsd.port.mk>
