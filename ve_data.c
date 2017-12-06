/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSES/0BSD.txt
 */

#include "ve_data.h"

static long nstAgentModuleObject = 1;
static long nstAgentSubagentObject = 2;
static long nstAgentPluginObject = 3;

const long *ve_get_nstAgentModuleObject( void )
{
	return &nstAgentModuleObject;
}

const long *ve_get_nstAgentSubagentObject( void )
{
	return &nstAgentSubagentObject;
}

const long *ve_get_nstAgentPluginObject( void )
{
	return &nstAgentPluginObject;
}

void ve_set_nstAgentModuleObject( long val )
{
	nstAgentModuleObject = val;
}

void ve_set_nstAgentSubagentObject( long val )
{
	nstAgentSubagentObject = val;
}

void ve_set_nstAgentPluginObject( long val )
{
	nstAgentPluginObject = val;
}
