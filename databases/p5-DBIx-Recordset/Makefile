# New ports collection makefile for:	DBIx::Recordset
# Date created:		29 Apr 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Recordset
PORTVERSION=	0.26
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for abstraction and simplification of database access

BUILD_DEPENDS+=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=		DBIx::Compat.3 DBIx::Database.3 DBIx::Intrors.3 \
		DBIx::Recordset.3 DBIx::Recordset::DBSeq.3 \
		DBIx::Recordset::FileSeq.3

post-configure:
# bad DBIx::Intrors.3
		@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 -lax/;' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
