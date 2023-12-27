Import('env')
from os.path import join, realpath

defaul_rgb_orders = ['RGB', 'RBG', 'GRB', 'GBR', 'BRG', 'BGR']

defaul_data_pins = [
    'C111_ESP_DIFF_1_OR_SINGLE_ENDED_1', 
    'C111_ESP_DIFF_2_OR_SINGLE_ENDED_2', 
    'C111_ESP_SINGLE_ENDED_3', 
    'C111_ESP_SINGLE_ENDED_4', 
    'C111_ESP_SINGLE_ENDED_5', 
    'C111_ESP_SINGLE_ENDED_6'
]

defaul_led_controllers = [
    'NEOPIXEL',
    'SM16703',
    'TM1829',
    'TM1812',
    'TM1809',
    'TM1804',
    'TM1803',
    'UCS1903',
    'UCS1903B',
    'UCS1904',
    'UCS2903',
    'WS2812',
    'WS2852',
    'WS2812B',
    'GS1903',
    'SK6812',
    'SK6822',
    'APA106',
    'PL9823',
    'WS2811',
    'WS2813',
    'APA104',
    'WS2811_400',
    'GE8822',
    'GW6205',
    'GW6205_400',
    'LPD1886',
    'LPD1886_8BIT'
]

enabled_data_pins       = [str(x).strip() for x in (env.GetProjectOption("enabled_data_pins", ','.join(defaul_data_pins)) or "").split(",")]
enabled_rgb_orders      = [str(x).strip() for x in (env.GetProjectOption("enabled_rgb_orders", ','.join(defaul_rgb_orders)) or "").split(",")]
enabled_led_controllers = [str(x).strip() for x in (env.GetProjectOption("enabled_led_controllers", ','.join(defaul_led_controllers)) or "").split(",")]

no_rgb = [
    'NEOPIXEL'
]

f = open("src/LED_Factory-generated.cpp", "w")

f.write("#include \"LED_Factory.h\"\n")
f.write("#include \"C111_Pinout.h\"\n\n\n")


f.write("std::vector<uint8_t> getEnabledPins() {\n")
f.write("  std::vector<uint8_t> ret;\n")
for data_pin in enabled_data_pins:
    f.write("  ret.push_back({data_pin});\n".format(data_pin=data_pin))
f.write("  return ret;\n")
f.write("}\n\n")


f.write("std::vector<EOrder> getEnabledRGBOrders() {\n")
f.write("  std::vector<EOrder> ret;\n")
for rgb_order in enabled_rgb_orders:
    f.write("  ret.push_back({rgb_order});\n".format(rgb_order=rgb_order))
f.write("  return ret;\n")
f.write("}\n\n")


f.write("std::vector<PixelType> getEnabledControllers() {\n")
f.write("  std::vector<PixelType> ret;\n")
for led_controller in enabled_led_controllers:
    f.write("  ret.push_back(T_{led_controller});\n".format(led_controller=led_controller))
f.write("  return ret;\n")
f.write("}\n\n")


f.write("CLEDController* createController(uint8_t pin, EOrder rgbOrder, PixelType pixelType, uint16_t offset, uint16_t count, CRGB* leds) {\n")

for data_pin in enabled_data_pins:
    f.write("  /* DATA PIN: {data_pin} */\n".format(data_pin=data_pin))
    f.write("  if (pin == {data_pin}) {{\n".format(data_pin=data_pin))

    for rgb_order in enabled_rgb_orders:
        f.write("    /* RGB ORDER: {rgb_order} */\n".format(rgb_order=rgb_order))
        f.write("    if (rgbOrder == {rgb_order}) {{\n".format(rgb_order=rgb_order))
        f.write("      switch (pixelType) {\n")

        for led_controller in enabled_led_controllers:
            if led_controller in no_rgb:
                txt = "        case T_{led_controller}: return &FastLED.addLeds<{led_controller}, {data_pin}>(leds, offset, count);\n"
            else:
                txt = "        case T_{led_controller}: return &FastLED.addLeds<{led_controller}, {data_pin}, {rgb_order}>(leds, offset, count);\n"
            f.write(txt.format(led_controller=led_controller, data_pin=data_pin, rgb_order=rgb_order))
        f.write("        default: return nullptr;\n")
        f.write("      }\n")
        f.write("    }\n")
    f.write("  }\n")
    f.write("  return nullptr;\n")

f.write("}\n\n")

