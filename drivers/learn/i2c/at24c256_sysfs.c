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

int at24c256_sysfs_create(struct kobject *kobj)
{
    int ret;

    ret = sysfs_create_group(kobj, &at24c256_group);
    if (ret) {
		pr_err("Failed to create at24c256 attr group\n");
		return ret;
	}

    return 0;
}
EXPORT_SYMBOL(at24c256_sysfs_create);

int at24c256_sysfs_remove(struct kobject *kobj)
{
	sysfs_remove_group(kobj, &at24c256_group);
    return 0;
}
EXPORT_SYMBOL(at24c256_sysfs_remove);