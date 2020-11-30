(function($){  //This functions first parameter is named $
    $(document).ready(function() {

			if($('#edit-menu-enabled').length) { //if a content type has menu settings available prompt user if they haven't set a menu item
        $('#edit-submit').bind('click', function(e){
            if($('#edit-menu-enabled').is(':not(:checked)') && !confirm("You are saving without having set a menu link, this page will not appear in site navigation.\n\nAre you sure you wish to continue?")){return false;}
        })
			}

			if($('#project-node-form').length) { //project content types do not require area of work set but it is a very rare case where this wouldn't be completed
        $('#edit-submit').bind('click', function(e){
						var bAreaSet = false;
						$('#edit-field-area-of-work-und').find('input').each(function(index, value) {
							if($(this).is(':checked')) {bAreaSet = true;}
						});
            if(!bAreaSet && !confirm("You are saving without having set a parent Area of Work.\nThis will prevent the project being included on the Experience page\n\nAre you sure you wish to continue?")){return false;}
        })
			}

    });
})(jQuery);