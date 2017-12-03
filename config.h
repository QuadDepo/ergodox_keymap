#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#ifndef NO_DEBUG
  #define NO_DEBUG
#endif
#ifndef NO_PRINT
  #define NO_PRINT
#endif

#endif
