# New ports collection makefile for:	nagios-statd
# Date created:		2003-11-06
# Whom:			Jim Shewmaker
#
# $FreeBSD$
#

PORTNAME=	nagios-statd
PORTVERSION=	3.12
PORTREVISION=	1
CATEGORIES=	sysutils python net-mgmt
MASTER_SITES=	http://www.twoevils.org/files/netsaint_statd/

MAINTAINER=	jims@bluenotch.com
COMMENT=	Daemon/client to check remote host information for Nagios

USE_PYTHON=	yes
USE_RC_SUBR=	nagiosstatd

MAN1=		nagios-stat.1
MAN8=		nagios-statd.8

do-build:
	${REINPLACE_CMD} -e 's,/usr/bin/python,/usr/bin/env python,' \
		${WRKSRC}/bin/* ${WRKSRC}/sbin/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/nagios-stat ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/nagios-statd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/share/man1/nagios-stat.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/man8/nagios-statd.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
