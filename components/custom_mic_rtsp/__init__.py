from esphome import automation
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

CONF_VOL = "volume"

custom_mic_rtsp_ns = cg.esphome_ns.namespace("custom_mic_rtsp")
custom_mic_rtsp = custom_mic_rtsp_ns.class_("custom_mic_rtsp", cg.Component)

DoInitAction = custom_mic_rtsp_ns.class_(
    "DoInitAction", automation.Action
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(custom_mic_rtsp),
        cv.Required(CONF_VOL): cv.float_range(0,30),
    }
).extend(cv.COMPONENT_SCHEMA)

ACTION_SCHEMA = cv.maybe_simple_value(
    {
        cv.Required(CONF_ID): cv.use_id(custom_mic_rtsp),
    },
)

@automation.register_action(
    "custom_mic_rtsp.doInit",
    DoInitAction,
    ACTION_SCHEMA,
)
async def custom_mic_rtsp_do_init_to_code(config, action_id, template_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    var = cg.new_Pvariable(action_id, template_arg, paren)
    return var

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add(var.set_volume(config[CONF_VOL]))
