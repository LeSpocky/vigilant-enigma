/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSE
 */

#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "nstMIBObjects.h"
#include "ve_build.h"

#define VE_APP						"nstMIBObjects"

static void ve_sigint_handler( int sig );
static void ve_sigterm_handler( int sig );

static bool ve_running;

int main( void )
{
	netsnmp_enable_subagent();
	netsnmp_ds_set_string(NETSNMP_DS_APPLICATION_ID,
						  NETSNMP_DS_AGENT_X_SOCKET,
						  VE_AGENTX_MASTER_SOCKET);

	snmp_disable_log();
	snmp_enable_stderrlog();

	init_agent( VE_APP );

	init_nstMIBObjects();
	init_snmp( VE_APP );

	ve_running = true;
	signal( SIGINT, ve_sigint_handler );
	signal( SIGTERM, ve_sigterm_handler );

	while ( ve_running )
	{
		agent_check_and_process( 1 );
	}

	snmp_shutdown( VE_APP );
	shutdown_agent();

	return EXIT_SUCCESS;
}

void ve_sigint_handler( int sig )
{
	if ( sig != SIGINT ) exit( EXIT_FAILURE );

	signal( SIGINT, SIG_IGN );

	ve_running = false;

	signal( SIGINT, ve_sigint_handler );
}

void ve_sigterm_handler( int sig )
{
	if ( sig != SIGTERM ) exit( EXIT_FAILURE );

	signal( SIGTERM, SIG_IGN );

	ve_running = false;

	signal( SIGTERM, ve_sigint_handler );
}
