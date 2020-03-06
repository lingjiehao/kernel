#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>

static int at24c256_probe(struct i2c_client *i2c,
		const struct i2c_device_id *dev_id)
{
	printk("HLJ: driver for at24c256 probed!\n");
	return 0;
}

static int at24c256_remove(struct i2c_client *i2c)
{
	printk("HLJ: driver for at24c256 removed!\n");
	return 0;
}

// #define LEGACY_DEVICE_ID

#ifdef LEGACY_DEVICE_ID
static const struct i2c_device_id at24c256_id[] = {
	{ "at24c256", 0 },
	{ },
};
MODULE_DEVICE_TABLE(i2c, at24c256_id);
#endif

static const struct of_device_id at24c256_of_match_table[] = {
	{ .compatible = "atmel,at24c256", },
	{ },
};
MODULE_DEVICE_TABLE(of, at24c256_of_match_table);

static struct i2c_driver at24c256_driver = {
	.driver = {
		.name = "at24c256",
		.owner = THIS_MODULE,
		.of_match_table = at24c256_of_match_table,
	},
	.probe = at24c256_probe,
	.remove = at24c256_remove,
#ifdef LEGACY_DEVICE_ID
	.id_table = at24c256_id,
#endif
};

module_i2c_driver(at24c256_driver);

MODULE_AUTHOR("Hao Lingjie");
MODULE_DESCRIPTION("EEPROM AT24C256 I2C Driver");
MODULE_LICENSE("GPL v2");
