/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSE
 */

#include "ve_data.h"

#include <stdint.h>

static int32_t nstAgentModuleObject = 0;
static int32_t nstAgentSubagentObject = 0;
static int32_t nstAgentPluginObject = 0;

const int32_t *ve_get_nstAgentModuleObject( void )
{
	return &nstAgentModuleObject;
}

const int32_t *ve_get_nstAgentSubagentObject( void )
{
	return &nstAgentSubagentObject;
}

const int32_t *ve_get_nstAgentPluginObject( void )
{
	return &nstAgentPluginObject;
}

void ve_set_nstAgentModuleObject( int32_t val )
{
	nstAgentModuleObject = val;
}

void ve_set_nstAgentSubagentObject( int32_t val )
{
	nstAgentSubagentObject = val;
}

void ve_set_nstAgentPluginObject( int32_t val )
{
	nstAgentPluginObject = val;
}
