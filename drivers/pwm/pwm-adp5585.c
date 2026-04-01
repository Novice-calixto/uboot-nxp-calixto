// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright 2023 NXP
 */

#include <common.h>
#include <div64.h>
#include <dm.h>
#include <log.h>
#include <pwm.h>
#include <asm/io.h>
#include <adp5585.h>

struct adp5585_pwm_priv {
    struct pwm_regs *regs;
    bool invert;
};

static int adp5585_pwm_set_invert(struct udevice *dev, uint channel,
                  bool polarity)
{
    debug("%s\n", __func__);

    return 0;
}

static int adp5585_pwm_set_enable(struct udevice *dev, uint channel, bool enable)
{
    debug("%s\n", __func__);

    return 0;
}

static int adp5585_pwm_set_config(struct udevice *dev, uint channel,
                  uint period_ns, uint duty_ns)
{
    debug("%s\n", __func__);

    return 0;
}

static int adp5585_pwm_of_to_plat(struct udevice *dev)
{
    uint8_t id;
    int ret;
    debug("%s\n", __func__);

    ret = adp5585_i2c_read_reg(ADP5585_ID, &id);
    debug("adp5585 id is %d\n",id);
    if (ret){
        printf("read version failed\n");
        return ret;
    }

    return 0;
}

static int adp5585_pwm_probe(struct udevice *dev)
{
    debug("%s\n", __func__);
    return 0;
}

static const struct pwm_ops adp5585_pwm_ops = {
    .set_invert    = adp5585_pwm_set_invert,
    .set_config    = adp5585_pwm_set_config,
    .set_enable    = adp5585_pwm_set_enable,
};

static const struct udevice_id adp5585_pwm_ids[] = {
    { .compatible = "adp5585pwm" },
    { }
};

U_BOOT_DRIVER(adp5585_pwm) = {
    .name    = "adp5585_pwm",
    .id    = UCLASS_PWM,
    .of_match = adp5585_pwm_ids,
    .ops    = &adp5585_pwm_ops,
    .of_to_plat    = adp5585_pwm_of_to_plat,
    .probe        = adp5585_pwm_probe,
    .priv_auto    = sizeof(struct adp5585_pwm_priv),
};
