#include<linux/kernel.h>
#include<linux/i2c.h>
#include<linux/module.h>
 
static int my_probe(struct i2c_client *client)
{
   pr_info("my i2c: device detected\n");
   return 0;
} 
static void my_remove(struct i2c_client *client)
{
  pr_info("my i2c: device removed\n");
  
}
static const struct i2c_device_id my_ids[]={
{"my_i2c_device",0},
{ }
};
MODULE_DEVICE_TABLE(i2c,my_ids);
static struct i2c_driver my_driver={
.driver={
.name="my_i2c",
.owner=THIS_MODULE,
},
.probe=my_probe,
.remove=my_remove,
.id_table=my_ids,
};
module_i2c_driver(my_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Priyadharshini A A");
MODULE_DESCRIPTION("Simple I2C driver example");

//Makefile

obj-m +=i2c.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

//Output
/*
[ 6321.034290] my i2c: device detected
[ 6321.034356] i2c i2c-1: new_device: Instantiated device my_i2c_device at 0x50
*/







