# New ports collection makefile for:	p5-Text-Unaccent
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Unaccent
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remove accents from a string

MAN3=	Text::Unaccent.3

USES=		iconv
PERL_CONFIGURE=	yes
CFLAGS+=	-DICONV_CONST=const

.include <bsd.port.mk>
