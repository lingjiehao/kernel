#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/device.h>
#include <linux/sysfs.h>


static ssize_t at24c256_data_dump(struct device *dev,
		struct device_attribute *attr, char *buf)
{

	return 0;
}
DEVICE_ATTR(dump, S_IRUGO, at24c256_data_dump, NULL);

static ssize_t at24c256_reg_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{

	return 0;
}

static ssize_t at24c256_reg_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{

	return 0;
}
DEVICE_ATTR(reg, S_IRUGO|S_IWUSR, at24c256_reg_show, at24c256_reg_store);

static ssize_t at24c256_data_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	
	return 0;
}
static ssize_t at24c256_data_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	return 0;

}
DEVICE_ATTR(data, S_IRUGO|S_IWUSR, at24c256_data_show, at24c256_data_store);

static ssize_t at24c256_address_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{

	return 0;
}
DEVICE_ATTR(address, S_IRUGO, at24c256_address_show, NULL);

static struct attribute *at24c256_attrs[] = {
	&dev_attr_dump.attr,
	&dev_attr_reg.attr,
	&dev_attr_data.attr,
	&dev_attr_address.attr,
	NULL,
};

static struct attribute_group at24c256_group = {
	.attrs = at24c256_attrs,
};

static int at24c256_probe(struct i2c_client *i2c,
		const struct i2c_device_id *dev_id)
{
	int ret;

	ret = sysfs_create_group(&i2c->dev.kobj, &at24c256_group);
	if (ret) {
		printk("Failed to create at24c256 attr group\n");
		return ret;
	}

	printk("HLJ: driver for at24c256 probed!\n");
	return 0;
}

static int at24c256_remove(struct i2c_client *i2c)
{
	printk("HLJ: driver for at24c256 removed!\n");

	sysfs_remove_group(&i2c->dev.kobj, &at24c256_group);
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
