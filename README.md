To install

    apt-get install librabbitmq-dev
    make
    make install
    make samples

Configure the file in /etc/asterisk/amqp.conf

Please restart asterisk before loading res_amqp.so for the documentation.

To load module

    CLI> module load res_amqp.so

There is an amqp CLI command to get the status.
