(function ($, Drupal) {

  /**
   * Initialize objects used later.
   */
  Drupal.breakpoints = {};
  Drupal.breakpoints.small = 480;
  Drupal.breakpoints.medium = 768;
  Drupal.breakpoints.large = 960;

  Drupal.mobileToolbar = {};
  Drupal.mobileToolbar.loaded = false;
  Drupal.mobileToolbar.types = 'search navigation contact';

 // Drupal.slideShow = {};


  $(document).ready(function() {
  //  Drupal.slideShow.element = $('.html-carousel .view-content');


    $('#session-carousel').carouFredSel({
      responsive: true,
      circular: false,
      auto: false,
      items: {
        visible: 1,
        width: 560,
        height: '56.25%'
      },
      scroll: {
        fx: 'directscroll'
      }
    });

    $('#session-thumbs').carouFredSel({
      responsive: true,
      circular: false,
      infinite: false,
      auto: false,
      prev: '#prev',
      next: '#next',
      items: {
        visible: {
          min: 2,
          max: 5
        },
        width: 90,
        height: '55.5555556%'
      }
    });

    $('#session-thumbs div.thumb-toggle').click(function() {
      console.log($(this));
      console.log(this.id.split('id-').pop());
      $('#session-carousel').trigger('slideTo', '#' + this.id.split('id-').pop());
      $('#session-thumbs a').removeClass('selected');
      $(this).addClass('selected');
      return false;
    });


    var closeButton = $('<div id="contact-close">close</div>').click(function(){
      $(this)
        .parents(".block-webform")
        .animate({'margin-right': '-500px'}
      );
    });
    $("#contact .block-webform .content").append(closeButton);
    $("#contact .block-toggle-contact .content div").click(function(){
        $(this)
          .parents(".block-toggle-contact")
          .next()
          .animate({'margin-right': 0}
        );
    });

    // Initialise the mobile toolbar.
    Drupal.mobileToolbar.initialise();

    // Check the current window width for mobile menu;
    if ($(window).width() < Drupal.breakpoints.medium) {
      if (Drupal.mobileToolbar.loaded && $("#mobile-toolbar").hasClass('loaded')) {
        Drupal.mobileToolbar.enable();
      }
    }
    else {
      // Show or initialize the slideshow.
   //   Drupal.slideShow.enable();
    }
  });

  $(window).resize(
    function() {
      if ($(window).width() < Drupal.breakpoints.medium) {
        // Initialise or enable mobile menu.
        if (Drupal.mobileToolbar.loaded & $("#mobile-toolbar").hasClass('loaded')) {
          Drupal.mobileToolbar.enable();
        }
        // Hide the slideshow.
  //      Drupal.slideShow.disable();
      }
      else {
        Drupal.mobileToolbar.disable();
        // Show or initialize the slideshow.
  //      Drupal.slideShow.enable();
      }
    }
  );

/*
 * Inlfield labels;
 */
  Drupal.behaviors.contactFieldLabels = {
    attach: function (context) {
      $("#contact label").inFieldLabels({
        fadeOpacity: 0.2,
        fadeDuration: 100
      });
    }
  };

  Drupal.mobileToolbar.initialise = function() {
    // Add the toggle buttons for search and menu to the toolbar.
    var typesArray = Drupal.mobileToolbar.types.split(' ');
    var type = '';
    var buttonDiv = '';
    var toolbarHtml = '';

    for (var i = 0; i < typesArray.length; i++) {
      type = typesArray[i];
      // Prepare toolbar button html. Do not add contact-html.
      // Contact cannot be duplicate tor it will brake functionality.
      if (type != 'contact') {
        toolbarHtml += $('#' + type).html();
      }

      // Create the toggle buttons for mobile layout and add to their respective
      // regions.
      buttonDiv = $("<div>")
        .addClass('toolbar-button-wrapper')
        .attr('id', 'toggle-' + type)
        .html('<div class="toolbar-button" id="btn-' + type + '">Toggle ' + type + '</div>');
      if (type != 'contact') {
         buttonDiv.appendTo($('#' + type)).hide();
      }
      else {
        buttonDiv.appendTo($('#toolbar')).hide();
      }
    }

    // Fill mobile toolbar.
    $("#mobile-toolbar")
      .html(toolbarHtml)
      .addClass('loaded');

    // Add menu toggle functionality.
    $('.toolbar-button').click(function() {
      var currentToggle = $(this).attr('id');
      var className = currentToggle.substr(4);
      // The mobile toolbar is hidden, show it and set toggled type class.
      if ($("#mobile-toolbar").hasClass('hidden')) {
        $("#mobile-toolbar").addClass(className)
          .removeClass('hidden');
        // If type == contact: show.
        if(className == 'contact') {
          $("#contact").show();
        }
      }
      else {
        // Toggled item is visible, hide the mobile toolbar.
        if ($("#mobile-toolbar").hasClass(className)) {
          $("#mobile-toolbar")
            .removeClass(Drupal.mobileToolbar.types)
            .addClass('hidden');
          // if  type == contact: hide.
          if(className == 'contact') {
            $("#contact").hide();
          }
        }
        else {
          // Switch what is visible.
          // Remove all type classes from mobile toolbar and set toggled type
          // class.
          $("#mobile-toolbar").removeClass(Drupal.mobileToolbar.types)
            .addClass(className);
          if(className == 'contact') {
            $("#contact").show();
          }
          else {
            $("#contact").hide();
          }
        }
      }
    });

    // Set loaded.
    Drupal.mobileToolbar.loaded = true;
  }


  /**
   * Enable mobile navigation.
   */
  Drupal.mobileToolbar.enable = function() {
    // Show the mobile buttons.
    $('#search .region-search').hide();
    $('#navigation .region-navigation').hide();
    $('#contact').hide();
    $('#contact .block-webform').css({'margin-right': 0});
    $('#toggle-search').show();
    $('#toggle-navigation').show();
    $('#toggle-contact').show();
    $(".language-switcher-locale-url li").addClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").addClass('toolbar-button');
  }

  Drupal.mobileToolbar.disable = function() {
    // Toggle toolbar elements.
    $('#contact').show();
    $('#contact .block-webform').css({'margin-right': '-500px'});
    $('#search .region-search').show();
    $('#navigation .region-navigation').show();
    $('#toggle-search').hide();
    $('#toggle-navigation').hide();
    $('#toggle-contact').hide();
    $(".language-switcher-locale-url li").removeClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").removeClass('toolbar-button');
    // Hide the mobile navigation.
    $("#mobile-toolbar").addClass('hidden');
  }

  $(window).resize(function() {
    if ($(window).width() >= Drupal.breakpoints.medium) {
      // Show or initialize the slideshow.
  //    Drupal.slideShow.enable();
    }
    else {
      // Hide the slideshow.
  //    Drupal.slideShow.element.hide();
    }
  });

})(jQuery, Drupal);
