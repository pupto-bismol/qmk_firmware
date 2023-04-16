switch (combo_index) {
  case clrline:
    if (pressed) {
      //SEND_STRING(SS_LCTL("a")"\b");
      break;
    }
  case brackets:
    if (pressed) {
     // SEND_STRING("()"SS_TAP(X_LEFT));
      break;
    }
}
