/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSE
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "nstMIBObjects.h"

int main( void )
{
	init_nstMIBObjects();

	return 0;
}
