#include "asterisk/astobj2.h"
#include "asterisk/stasis.h"
#include "sub_stasis.h"


static void send_message_to_amqp(void *data, struct stasis_subscription *sub,
    struct stasis_topic *topic, struct stasis_message *message)
{
    RAII_VAR(struct ast_str *, metric, NULL, ast_free);
    if (stasis_subscription_final_message(sub, message)) {
        /* Normally, data points to an object that must be cleaned up.
         * The final message is an unsubscribe notification that's
         * guaranteed to be the last message this subscription receives.
         * This would be a safe place to kick off any needed cleanup.
         */
        return;
    }
    /* For no good reason, count message types */
    metric = ast_str_create(80);
    if (metric) {
        ast_str_set(&metric, 0, "stasis.message.%s",
            stasis_message_type_name(stasis_message_type(message)));
        /*ast_statsd_log(ast_str_buffer(metric), AST_STATSD_METER, 1);*/
    }
}
