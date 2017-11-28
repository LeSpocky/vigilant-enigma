/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSE
 */

#ifndef VE_DATA_H
#define VE_DATA_H

#include <stdint.h>

const int32_t *ve_get_nstAgentModuleObject( void );

const int32_t *ve_get_nstAgentSubagentObject( void );

const int32_t *ve_get_nstAgentPluginObject( void );

void ve_set_nstAgentModuleObject( int32_t val );

void ve_set_nstAgentSubagentObject( int32_t val );

void ve_set_nstAgentPluginObject( int32_t val );

#endif /* VE_DATA_H */
