// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Nothing is overridden here right now, and that is deliberate - see below.
// Build-time options (alphas, nav, clipboard) are set in
// .github/workflows/build-corne-nice_nano.yml, not in this file.


// ---------------------------------------------------------------------------
// DISABLED. This block overrode MIRYOKU_LAYER_TAP. It was not doing what it
// looked like it was doing.
//
// miryoku has three alpha layers:
//
//   BASE  (layer 0) the layer you actually type on. Home row mods, and every
//                   thumb is a layer-tap.
//   EXTRA (layer 1) an alternate alphas layout.
//   TAP   (layer 2) the escape hatch. Deliberately plain: no home row mods and
//                   no layer-taps anywhere. Reached with &u_to_U_TAP from the
//                   NAV, MOUSE and MEDIA layers.
//
// The override below edited TAP, so it never touched daily typing on BASE.
// What it did do was put hold-taps back into the one layer whose whole purpose
// is having none - which removed the best tool for telling a dead switch apart
// from a mistimed hold-tap. That is exactly the distinction worth drawing right
// now, so TAP is back to stock.
//
// It also dropped the NAV, MOUSE and MEDIA thumb keys, so from TAP there was no
// way back to BASE and no way to reach bluetooth profile switching or the
// bootloader, both of which live on MEDIA.
//
// To change the layer you type on, override MIRYOKU_LAYER_BASE instead. Copy
// MIRYOKU_ALTERNATIVES_BASE_QWERTY out of
// miryoku/miryoku_babel/miryoku_layer_alternatives.h and edit only what you
// mean to. Keep one thumb each for NAV, MOUSE and MEDIA or you lose those
// layers entirely.

#if 0
#define MIRYOKU_LAYER_TAP\
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
&kp A,             &kp S,             &kp D,             &kp F,             &kp G,             &kp H,             U_MT(LSHFT, J),    U_MT(LCTRL, K),    U_MT(LALT, L),     U_MT(LGUI, SQT),   \
&kp Z,             &kp X,             &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         U_MT(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              &kp ESC,           &kp SPACE,         &kp TAB,           U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP
#endif
