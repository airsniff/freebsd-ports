# Created by: chinsan
# $FreeBSD$

PORTNAME=	POE-Component-Pluggable
PORTVERSION=	1.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for creating plugin enabled POE Components

BUILD_DEPENDS=	p5-POE>=1.004:${PORTSDIR}/devel/p5-POE \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Pluggable.3 POE::Component::Pluggable::Pipeline.3 \
		POE::Component::Pluggable::Constants.3

.include <bsd.port.mk>
