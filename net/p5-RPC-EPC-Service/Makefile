# New ports collection makefile for:	RPC::EPC::Service
# Date created:		19 Mar 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	RPC-EPC-Service
PORTVERSION=	0.0.7
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for asynchronous remote procedure stack

RUN_DEPENDS=	\
	p5-AnyEvent>=6.1:${PORTSDIR}/devel/p5-AnyEvent \
	p5-Data-SExpression>=0.41:${PORTSDIR}/devel/p5-Data-SExpression
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	RPC::EPC::Service.3

.include <bsd.port.mk>
