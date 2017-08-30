#include "asterisk/stasis.h"

static void send_message_to_amqp(void *data, struct stasis_subscription *sub, struct stasis_topic *topic, struct stasis_message *message);
