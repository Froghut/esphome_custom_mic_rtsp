import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

CONF_VOL = "volume"

custom_mic_rtsp_ns = cg.esphome_ns.namespace("custom_mic_rtsp")
custom_mic_rtsp = custom_mic_rtsp_ns.class_("custom_mic_rtsp", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(custom_mic_rtsp),
        cv.Required(CONF_VOL): cv.float_range(0,30),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add(var.set_vol(config[CONF_VOL]))
