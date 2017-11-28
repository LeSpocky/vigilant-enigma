/*
 * Copyright 2017 Alexander Dahl <post@lespocky.de>
 *
 * SPDX-License-Identifier: 0BSD
 * License-Filename: LICENSE
 */

#ifndef VE_DATA_H
#define VE_DATA_H

const long *ve_get_nstAgentModuleObject( void );

const long *ve_get_nstAgentSubagentObject( void );

const long *ve_get_nstAgentPluginObject( void );

void ve_set_nstAgentModuleObject( long val );

void ve_set_nstAgentSubagentObject( long val );

void ve_set_nstAgentPluginObject( long val );

#endif /* VE_DATA_H */
