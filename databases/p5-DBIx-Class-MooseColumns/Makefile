# New ports collection makefile for:	DBIx::Class::MooseColumns
# Date created:		2010-11-20
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-MooseColumns
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MENDEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Allow write DBIC add_column definitions as attribute options

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=1.24:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Path-Class>0.16:${PORTSDIR}/devel/p5-Path-Class \
		p5-MooseX-NonMoose>=0.17:${PORTSDIR}/devel/p5-MooseX-NonMoose \
		p5-IO-All>=0.41:${PORTSDIR}/devel/p5-IO-All
RUN_DEPENDS=	p5-Moose>=1.24:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Path-Class>0.16:${PORTSDIR}/devel/p5-Path-Class \
		p5-MooseX-NonMoose>=0.17:${PORTSDIR}/devel/p5-MooseX-NonMoose \
		p5-IO-All>=0.41:${PORTSDIR}/devel/p5-IO-All
TEST_DEPENDS=	p5-Test-Aggregate>=0.363:${PORTSDIR}/devel/p5-Test-Aggregate \
		p5-Test-Most>=0.21:${PORTSDIR}/devel/p5-Test-Most \
		p5-Test-Differences>=0.4801:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Deep>=0.103:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-DBIx-Class>=0.10:${PORTSDIR}/devel/p5-Test-DBIx-Class

PERL_CONFIGURE=	yes

MAN3=	\
	DBIx::Class::MooseColumns.3 \
	DBIx::Class::MooseColumns::Meta::Role::Attribute.3 \
	DBIx::Class::MooseColumns::Meta::Role::Attribute::DBICColumn.3 \
	DBIx::Class::MooseColumns::Meta::Role::Attribute::DBICColumn::Inflated.3

.include <bsd.port.mk>
