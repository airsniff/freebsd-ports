# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	Graphics-ColorNames
PORTVERSION=	2.11
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl class that defines RGB values for common color names

BUILD_DEPENDS=	p5-Module-Load>=0.10:${PORTSDIR}/devel/p5-Module-Load \
		p5-Module-Loaded>=0:${PORTSDIR}/devel/p5-Module-Loaded
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_MODBUILD=	yes

MAN3=	Graphics::ColorNames.3 \
	Graphics::ColorNames::HTML.3 \
	Graphics::ColorNames::Netscape.3 \
	Graphics::ColorNames::Windows.3 \
	Graphics::ColorNames::X.3

.include <bsd.port.mk>
