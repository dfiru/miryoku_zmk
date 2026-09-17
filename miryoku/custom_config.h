// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Build-time options (alphas, tap, nav, clipboard) live in
// .github/workflows/build-corne-nice_nano.yml, not in this file.


// ---------------------------------------------------------------------------
// TAP layer (layer 2), with a way back out.
//
// Background on the three alpha layers:
//
//   BASE  (layer 0) the layer you type on. Home row mods, every thumb a
//                   layer-tap.
//   EXTRA (layer 1) an alternate alphas layout.
//   TAP   (layer 2) the escape hatch. Deliberately plain: no home row mods and
//                   no layer-taps anywhere. Useful for gaming, for screen
//                   sharing, and for proving that a key fault is the switch
//                   rather than a mistimed hold-tap.
//
// Two things were wrong with TAP before:
//
//   1. Its alphas are chosen by the `tap` workflow option, which is SEPARATE
//      from `alphas` and defaults to colemak-dh. That option was never set, so
//      TAP typed Colemak-DH while BASE typed QWERTY. Now set to qwerty in the
//      workflow.
//
//   2. Stock TAP has no layer-switching key at all, so once you switch to it
//      the only way back to BASE is a reset. Upstream documents this and
//      leaves the fix to the user.
//
// This override is MIRYOKU_ALTERNATIVES_TAP_QWERTY verbatim with exactly one
// key changed: the right outer thumb goes from `&kp DEL` to `&u_to_U_BASE`.
// DEL is the most expendable of the six thumbs, and `u_to_U_BASE` is miryoku's
// own double-tap-guarded switch, so a single stray tap does nothing and a
// deliberate double tap returns you to BASE.
//
// Because this override is present, the `tap` workflow option no longer has any
// effect on the result. Change the alphas here if you change it there.
//
// To change the layer you actually type on, override MIRYOKU_LAYER_BASE
// instead, starting from MIRYOKU_ALTERNATIVES_BASE_QWERTY in
// miryoku/miryoku_babel/miryoku_layer_alternatives.h. Keep one thumb each for
// NAV, MOUSE and MEDIA or you lose those layers, and with MEDIA you lose
// bluetooth profile switching and the bootloader.
// ---------------------------------------------------------------------------

#define MIRYOKU_LAYER_TAP \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
&kp A,             &kp S,             &kp D,             &kp F,             &kp G,             &kp H,             &kp J,             &kp K,             &kp L,             &kp SQT,           \
&kp Z,             &kp X,             &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         &kp DOT,           &kp SLASH,         \
U_NP,              U_NP,              &kp ESC,           &kp SPACE,         &kp TAB,           &kp RET,           &kp BSPC,          &u_to_U_BASE,      U_NP,              U_NP
