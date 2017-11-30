/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSE
 */

#include <assert.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "nstMIBObjects.h"
#include "ve_build.h"

#define VE_APP						"nstMIBObjects"

/**
 *	This has the standard signature for a SNMPCallback.
 *
 *	@param[in]	major_id	Same as when registered with snmp_register_callback(),
 *							should be SNMP_CALLBACK_LIBRARY.
 *	@param[in]	minor_id	Same as when registered with snmp_register_callback(),
 *							should be SNMP_CALLBACK_LOGGING.
 *	@param[in]	serverarg	Pointer to `struct snmp_log_message`.
 *	@param[in]	clientarg	Same as when registered with snmp_register_callback(),
 *							probably NULL?
 *
 *	@return	net-snmp does not care, what we return here.
 */
static int ve_log_callback(
		int		major_id,
		int		minor_id,
		void	*serverarg,
		void	*clientarg
);

static void ve_sigint_handler( int sig );
static void ve_sigterm_handler( int sig );

static bool ve_running;

int main( void )
{
	netsnmp_enable_subagent();
	netsnmp_ds_set_string(NETSNMP_DS_APPLICATION_ID,
						  NETSNMP_DS_AGENT_X_SOCKET,
						  VE_AGENTX_MASTER_SOCKET);

	/*
	 *	Register our own log function.
	 *
	 *	NOTE	For debug log level, you must create a config file
	 *			nstMIBObjects.conf with the following content:
	 *
	 *		[snmp]
	 *		doDebugging 1
	 */
	snmp_disable_log();
	snmp_enable_calllog();
	snmp_register_callback(SNMP_CALLBACK_LIBRARY,
						   SNMP_CALLBACK_LOGGING,
						   ve_log_callback,
						   NULL);

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

int ve_log_callback(
		int		major_id,
		int		minor_id,
		void	*serverarg,
		void	*clientarg )
{
	struct snmp_log_message *slm = (struct snmp_log_message *) serverarg;

	assert( serverarg );
	assert( major_id == SNMP_CALLBACK_LIBRARY );
	assert( minor_id == SNMP_CALLBACK_LOGGING );

	fprintf( stderr, "%i: %s\n", slm->priority, slm->msg );

	return SNMP_ERR_NOERROR;
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
