# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Thread-Queue
PORTVERSION=	3.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Perl5 thread-safe queues

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=	Thread::Queue.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-threads-shared>=1.21:${PORTSDIR}/devel/p5-threads-shared
RUN_DEPENDS:=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
