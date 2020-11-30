jQuery(document).ready(function($){
var mm_duration = 0;
$('.t3-megamenu').each (function(){
if ($(this).data('duration')) {
mm_duration = $(this).data('duration');
}
});
var mm_timeout = mm_duration ? 100 + mm_duration : 500;
$('.nav > li, li.mega').hover(function(event) {
console.log("okay");
var $this = $(this);
if ($this.hasClass('mega')) {
$this.addClass('animating');
clearTimeout($this.data('animatingTimeout'));
$this.data('animatingTimeout', setTimeout(function() {
$this.removeClass('animating')
}, mm_timeout));
clearTimeout($this.data('hoverTimeout'));
$this.data('hoverTimeout', setTimeout(function() {
$this.addClass('open')
}, 100));
} else {
clearTimeout($this.data('hoverTimeout'));
$this.data('hoverTimeout',
setTimeout(function() {
$this.addClass('open')
}, 100));
}
},
function(event) {
var $this = $(this);
if ($this.hasClass('mega')) {
$this.addClass('animating');
clearTimeout($this.data('animatingTimeout'));
$this.data('animatingTimeout',
setTimeout(function() {
$this.removeClass('animating')
}, mm_timeout));
clearTimeout($this.data('hoverTimeout'));
$this.data('hoverTimeout', setTimeout(function() {
$this.removeClass('open')
}, 100));
} else {
clearTimeout($this.data('hoverTimeout'));
$this.data('hoverTimeout',
setTimeout(function() {
$this.removeClass('open')
}, 100));
}
});
})