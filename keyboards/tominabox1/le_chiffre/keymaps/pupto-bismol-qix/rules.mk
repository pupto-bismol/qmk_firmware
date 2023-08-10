BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
MUSIC_ENABLE = no           # Music notes mode
ENCODER_ENABLE = yes
#ENCODER_MAP_ENABLE = yes    # Allows mapping encoders per layer
RGB_MATRIX_ENABLE = yes
LEADER_ENABLE = yes

DEBOUNCE_TYPE = sym_defer_g
#DEBOUNCE_TYPE = asym_eager_defer_pk

TAP_DANCE_ENABLE = no
SPACE_CADET_ENABLE = no     # Space Cadet shifting
GRAVE_ESCAPE_ENABLE = yes   # Grave/Escape thing
MAGIC_ENABLE = yes          # NKRO and Alt/GUI toggles, etc.
COMBO_ENABLE = yes          # Allows the use of combos
LTO_ENABLE = yes            # Makes compile longer for smaller file

# enable combo file
VPATH += keyboards/gboards
