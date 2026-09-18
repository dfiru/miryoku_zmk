// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// No game layer. Build-time options (alphas, tap, nav, clipboard) are set in
// .github/workflows/build-corne-nice_nano.yml, not here.
//
// The single override below is insurance, not a feature. Stock TAP (layer 2)
// has plain thumbs, so it cannot reach NAV, MOUSE, MEDIA, NUM, SYM or FUN, and
// none of its own keys return to BASE. Land on it by accident, by double
// tapping W while holding a left thumb, and the board is stranded on plain
// QWERTY until you power cycle it. This puts miryoku's own double-tap-guarded
// &u_to_U_BASE on the right outer thumb, where DEL would be. A single stray
// tap does nothing; a deliberate double tap returns to BASE.
//
// Everything else is stock TAP_QWERTY, verbatim.
//
// For the record, since the commit that removed it (805e171) says otherwise:
// the earlier override here was a deliberate game layer, left hand entirely
// plain so WASD could be held, right hand keeping its mods and layer-taps. It
// was not broken, it was not typing Colemak-DH, and its right-thumb layer-taps
// gave it three routes back to BASE. Removed because gaming on a split 42-key
// with the right hand on a mouse leaves no reachable Shift or Ctrl, so a
// regular keyboard is the better tool. Recover it from `git show 75ac7be` if
// that ever changes.

#define MIRYOKU_LAYER_TAP \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
&kp A,             &kp S,             &kp D,             &kp F,             &kp G,             &kp H,             &kp J,             &kp K,             &kp L,             &kp SQT,           \
&kp Z,             &kp X,             &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         &kp DOT,           &kp SLASH,         \
U_NP,              U_NP,              &kp ESC,           &kp SPACE,         &kp TAB,           &kp RET,           &kp BSPC,          &u_to_U_BASE,      U_NP,              U_NP
