# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-XML-Feed
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl extension for Catalyst view for RSS, Atom, or other XML feeds

BUILD_DEPENDS=	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-XML-Feed>=0:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		Catalyst::View::XML::Feed.3

.include <bsd.port.mk>
