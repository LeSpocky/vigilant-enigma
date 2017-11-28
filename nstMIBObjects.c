/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <stdbool.h>

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "nstMIBObjects.h"

#include "ve_data.h"

/** Initializes the nstMIBObjects module */
void
init_nstMIBObjects(void)
{
    const oid       nstAgentModuleObject_oid[] =
        { 1, 3, 6, 1, 4, 1, 8072, 2, 4, 1, 1, 1 };
    const oid       nstAgentSubagentObject_oid[] =
        { 1, 3, 6, 1, 4, 1, 8072, 2, 4, 1, 1, 2 };
    const oid       nstAgentPluginObject_oid[] =
        { 1, 3, 6, 1, 4, 1, 8072, 2, 4, 1, 1, 3 };

    DEBUGMSGTL(("nstMIBObjects", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("nstAgentModuleObject",
                             handle_nstAgentModuleObject,
                             nstAgentModuleObject_oid,
                             OID_LENGTH(nstAgentModuleObject_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("nstAgentSubagentObject",
                             handle_nstAgentSubagentObject,
                             nstAgentSubagentObject_oid,
                             OID_LENGTH(nstAgentSubagentObject_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("nstAgentPluginObject",
                             handle_nstAgentPluginObject,
                             nstAgentPluginObject_oid,
                             OID_LENGTH(nstAgentPluginObject_oid),
                             HANDLER_CAN_RWRITE));
}

int
handle_nstAgentModuleObject(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *reqinfo,
                            netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 ve_get_nstAgentModuleObject(),
                                 sizeof(int32_t));
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
		ve_set_nstAgentModuleObject(*(requests->requestvb->val.integer));
        break;

    case MODE_SET_COMMIT:
        break;

    case MODE_SET_UNDO:
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_nstAgentModuleObject\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_nstAgentSubagentObject(netsnmp_mib_handler *handler,
                              netsnmp_handler_registration *reginfo,
                              netsnmp_agent_request_info *reqinfo,
                              netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 ve_get_nstAgentSubagentObject(),
                                 sizeof(int32_t));
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        ret = netsnmp_check_vb_type_and_size(requests->requestvb,
											 ASN_INTEGER, sizeof(long));
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
		ve_set_nstAgentSubagentObject(*(requests->requestvb->val.integer));
        break;

    case MODE_SET_COMMIT:
        break;

    case MODE_SET_UNDO:
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_nstAgentSubagentObject\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_nstAgentPluginObject(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *reqinfo,
                            netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 ve_get_nstAgentPluginObject(),
                                 sizeof(int32_t));
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
		ve_set_nstAgentPluginObject(*(requests->requestvb->val.integer));
        break;

    case MODE_SET_COMMIT:
        break;

    case MODE_SET_UNDO:
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_nstAgentPluginObject\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
