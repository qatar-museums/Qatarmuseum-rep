/**
 * jQuery function to set position of cursor to end of text field.
 */
jQuery.fn.setCursorEnd = function() {
  this.setCursorPos(this.val().length);
}

/**
 * jQuery function to set position of cursor in text field.
 */
jQuery.fn.setCursorPos = function(pos) {
  if (this.get(0).setSelectionRange) {
    this.get(0).setSelectionRange(pos, pos);
  }
  else if (this.get(0).createTextRange) {
    var range = this.get(0).createTextRange();
    range.collapse(true);

    if (pos < 0) {
      pos = $(this).val().length + pos;
    }

    range.moveEnd('character', pos);
    range.moveStart('character', pos);
    range.select();
  }
}
