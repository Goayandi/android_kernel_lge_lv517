
#ifndef _LGE_MDSS_DSI_PANEL_H
#define _LGE_MDSS_DSI_PANEL_H

int lge_mdss_panel_parse_dt_extra(struct device_node *np,
                        struct mdss_dsi_ctrl_pdata *ctrl_pdata);

void lge_mdss_dsi_panel_extra_cmds_send(struct mdss_dsi_ctrl_pdata *ctrl, const char *name);

#if defined(CONFIG_LGE_HIGH_LUMINANCE_MODE)
void lge_mdss_panel_parse_dt_blmaps(struct device_node *np,
				   struct mdss_dsi_ctrl_pdata *ctrl_pdata);
#endif
#if IS_ENABLED(CONFIG_LGE_DISPLAY_EXTERNAL_DSV)
typedef enum {
	DSV_DW8768,
	DSV_SM5107,
	INVALED_DSV,
} dsv_type;
#endif

#if IS_ENABLED(CONFIG_LGE_MIPI_DSI_LGD_K7J_FHD_VIDEO_INCELL_LCD_PANEL)
enum external_api_type {
	VDDI_CTRL,
	AVDD_AVEE_CTRL,
	LCD_RESET_CTRL,
	LCD_INIT_CMD_TRANSFER,
#if IS_ENABLED(CONFIG_LGE_DISPLAY_RECOVERY_ESD)
	LCD_ESD_RESET,
#endif
	NONE,
};

int lge_mdss_dsi_panel_power_vddio_ctrl(struct mdss_dsi_ctrl_pdata *ctrl_pdata, int enable);
int lge_mdss_dsi_panel_power_labibb_ctrl(struct mdss_dsi_ctrl_pdata *ctrl_pdata, int enable);
int lge_mdss_dsi_panel_reset_ctrl(struct mdss_dsi_ctrl_pdata *ctrl_pdata, int enable);
#endif
#endif
