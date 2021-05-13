// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2021 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>

struct lgd_incell_m2db7400 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
	bool prepared;
};

static inline
struct lgd_incell_m2db7400 *to_lgd_incell_m2db7400(struct drm_panel *panel)
{
	return container_of(panel, struct lgd_incell_m2db7400, panel);
}

#define dsi_generic_write_seq(dsi, seq...) do {				\
		static const u8 d[] = { seq };				\
		int ret;						\
		ret = mipi_dsi_generic_write(dsi, d, ARRAY_SIZE(d));	\
		if (ret < 0)						\
			return ret;					\
	} while (0)

#define dsi_dcs_write_seq(dsi, seq...) do {				\
		static const u8 d[] = { seq };				\
		int ret;						\
		ret = mipi_dsi_dcs_write_buffer(dsi, d, ARRAY_SIZE(d));	\
		if (ret < 0)						\
			return ret;					\
	} while (0)

static void lgd_incell_m2db7400_reset(struct lgd_incell_m2db7400 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
}

static int lgd_incell_m2db7400_on(struct lgd_incell_m2db7400 *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	dsi_dcs_write_seq(dsi, MIPI_DCS_SET_ADDRESS_MODE, 0x00);
	dsi_dcs_write_seq(dsi, 0xb0, 0x00);
	dsi_generic_write_seq(dsi, 0xb1, 0x00, 0x46);
	dsi_generic_write_seq(dsi, 0xb2, 0x50, 0x00, 0x0c, 0x00, 0x00, 0x00);
	dsi_generic_write_seq(dsi, 0xb3, 0x4f, 0x80, 0x0a, 0x28);
	dsi_generic_write_seq(dsi, 0xb4, 0x05, 0x0c, 0x1f, 0x18, 0x11, 0x00);
	dsi_generic_write_seq(dsi, 0xb5,
			      0x19, 0x04, 0x1c, 0x22, 0x2f, 0x80, 0x2f, 0x1f,
			      0x04, 0x40, 0x05, 0x00, 0x20, 0x09, 0x04, 0x40,
			      0x05, 0x00, 0xa5, 0x0d, 0x2f, 0x2f, 0x3f, 0xff,
			      0x3f, 0xff, 0x01, 0x7c, 0x00, 0x02, 0x50, 0x23,
			      0x40, 0x15, 0x6c, 0xcb, 0xba, 0xa9, 0x97, 0x8d,
			      0x1f, 0x23, 0x40, 0x15, 0x6c, 0xcb, 0xba, 0xa9,
			      0x97, 0x8d, 0x1f);
	dsi_generic_write_seq(dsi, 0xb6, 0x01, 0x01);
	dsi_generic_write_seq(dsi, 0xb7, 0x00, 0x4b, 0x4b);
	dsi_generic_write_seq(dsi, 0xbb,
			      0x00, 0x90, 0x90, 0x30, 0x30, 0x00, 0x00, 0x00,
			      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13);
	dsi_generic_write_seq(dsi, 0xbd, 0x03, 0x33);
	dsi_generic_write_seq(dsi, 0xbe, 0x03);
	dsi_generic_write_seq(dsi, 0x95, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00);
	dsi_generic_write_seq(dsi, 0xcf, 0x03);
	dsi_generic_write_seq(dsi, 0xc6, 0x0a, 0x00);
	dsi_generic_write_seq(dsi, 0xd7,
			      0x00, 0x13, 0xff, 0x39, 0x0b, 0x04, 0x14, 0xf4,
			      0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01, 0x57,
			      0x57, 0x41, 0x28, 0x28, 0x3f, 0x00, 0x00, 0x00,
			      0x00, 0x00);
	dsi_generic_write_seq(dsi, 0xf5, 0x00, 0x06, 0x00, 0x00, 0x80);
	dsi_generic_write_seq(dsi, 0xf6, 0x06);
	dsi_generic_write_seq(dsi, 0xf0,
			      0x18, 0x00, 0x14, 0x14, 0x00, 0x0b, 0x0b, 0x16,
			      0x0b, 0x19, 0x41, 0x16, 0x17, 0x69, 0x6e, 0x73,
			      0x78, 0xbc, 0xc1, 0xc6, 0xb0, 0xb0, 0xaf, 0xb0,
			      0xad, 0x85, 0xb0, 0xb0, 0x5d, 0x58, 0x53, 0x4e,
			      0x0a, 0x05, 0x00);
	dsi_generic_write_seq(dsi, 0xd0,
			      0x53, 0x35, 0x66, 0x63, 0x01, 0x02, 0x70, 0x75,
			      0x04);
	dsi_generic_write_seq(dsi, 0xd0, 0x53, 0x35, 0x66, 0x63);
	dsi_generic_write_seq(dsi, 0xd1,
			      0x63, 0x35, 0x66, 0x63, 0x01, 0x02, 0x70, 0x75,
			      0x04);
	dsi_generic_write_seq(dsi, 0xd1, 0x63, 0x35, 0x66, 0x63);
	dsi_generic_write_seq(dsi, 0xd2,
			      0x53, 0x35, 0x66, 0x63, 0x01, 0x02, 0x70, 0x75,
			      0x04);
	dsi_generic_write_seq(dsi, 0xd2, 0x53, 0x35, 0x66, 0x63);
	dsi_generic_write_seq(dsi, 0xd3,
			      0x63, 0x35, 0x66, 0x63, 0x01, 0x02, 0x70, 0x75,
			      0x04);
	dsi_generic_write_seq(dsi, 0xd3, 0x63, 0x35, 0x66, 0x63);
	dsi_generic_write_seq(dsi, 0xd4,
			      0x53, 0x35, 0x66, 0x72, 0x01, 0x02, 0x70, 0x75,
			      0x04);
	dsi_generic_write_seq(dsi, 0xd4, 0x53, 0x35, 0x66, 0x72);
	dsi_generic_write_seq(dsi, 0xd5,
			      0x63, 0x35, 0x66, 0x72, 0x01, 0x02, 0x70, 0x75,
			      0x04);
	dsi_generic_write_seq(dsi, 0xd5, 0x63, 0x35, 0x66, 0x72);
	dsi_generic_write_seq(dsi, 0x85,
			      0x11, 0x6e, 0x22, 0x5a, 0x19, 0x44, 0x28, 0x7f,
			      0x38, 0xad, 0x85, 0x60, 0xa2, 0x9b, 0x8c, 0x65,
			      0x51, 0x97, 0x60, 0xb0, 0x9c, 0x65, 0x51, 0xa5,
			      0x62);
	dsi_generic_write_seq(dsi, 0x81, 0x98, 0x34, 0x00);

	ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to exit sleep mode: %d\n", ret);
		return ret;
	}
	msleep(120);

	ret = mipi_dsi_dcs_set_display_on(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display on: %d\n", ret);
		return ret;
	}

	return 0;
}

static int lgd_incell_m2db7400_off(struct lgd_incell_m2db7400 *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	return 0;
}

static int lgd_incell_m2db7400_prepare(struct drm_panel *panel)
{
	struct lgd_incell_m2db7400 *ctx = to_lgd_incell_m2db7400(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (ctx->prepared)
		return 0;

	lgd_incell_m2db7400_reset(ctx);

	ret = lgd_incell_m2db7400_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	ctx->prepared = true;
	return 0;
}

static int lgd_incell_m2db7400_unprepare(struct drm_panel *panel)
{
	struct lgd_incell_m2db7400 *ctx = to_lgd_incell_m2db7400(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (!ctx->prepared)
		return 0;

	ret = lgd_incell_m2db7400_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	ctx->prepared = false;
	return 0;
}

static const struct drm_display_mode lgd_incell_m2db7400_mode = {
	.clock = (720 + 82 + 4 + 120) * (1280 + 540 + 1 + 11) * 60 / 1000,
	.hdisplay = 720,
	.hsync_start = 720 + 82,
	.hsync_end = 720 + 82 + 4,
	.htotal = 720 + 82 + 4 + 120,
	.vdisplay = 1280,
	.vsync_start = 1280 + 540,
	.vsync_end = 1280 + 540 + 1,
	.vtotal = 1280 + 540 + 1 + 11,
	.width_mm = 66,
	.height_mm = 117,
};

static int lgd_incell_m2db7400_get_modes(struct drm_panel *panel,
					 struct drm_connector *connector)
{
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(connector->dev, &lgd_incell_m2db7400_mode);
	if (!mode)
		return -ENOMEM;

	drm_mode_set_name(mode);

	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	connector->display_info.width_mm = mode->width_mm;
	connector->display_info.height_mm = mode->height_mm;
	drm_mode_probed_add(connector, mode);

	return 1;
}

static const struct drm_panel_funcs lgd_incell_m2db7400_panel_funcs = {
	.prepare = lgd_incell_m2db7400_prepare,
	.unprepare = lgd_incell_m2db7400_unprepare,
	.get_modes = lgd_incell_m2db7400_get_modes,
};

static int lgd_incell_m2db7400_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct lgd_incell_m2db7400 *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_EOT_PACKET;

	drm_panel_init(&ctx->panel, dev, &lgd_incell_m2db7400_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to attach to DSI host: %d\n", ret);
		drm_panel_remove(&ctx->panel);
		return ret;
	}

	return 0;
}

static int lgd_incell_m2db7400_remove(struct mipi_dsi_device *dsi)
{
	struct lgd_incell_m2db7400 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);

	return 0;
}

static const struct of_device_id lgd_incell_m2db7400_of_match[] = {
	{ .compatible = "lgd,incell-m2db7400" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, lgd_incell_m2db7400_of_match);

static struct mipi_dsi_driver lgd_incell_m2db7400_driver = {
	.probe = lgd_incell_m2db7400_probe,
	.remove = lgd_incell_m2db7400_remove,
	.driver = {
		.name = "panel-lgd-incell-m2db7400",
		.of_match_table = lgd_incell_m2db7400_of_match,
	},
};
module_mipi_dsi_driver(lgd_incell_m2db7400_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for LGD M2 DONGBU HITEK INCELL HD video mode dsi panel");
MODULE_LICENSE("GPL v2");
