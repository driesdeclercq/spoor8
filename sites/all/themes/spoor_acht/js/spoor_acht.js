(function ($, Drupal) {

  /**
   * Initialize objects used later.
   */
  Drupal.breakpoints = {};
  Drupal.breakpoints.small = 480;
  Drupal.breakpoints.medium = 768;
  Drupal.breakpoints.large = 1024;

  Drupal.mobileToolbar = {};
  Drupal.mobileToolbar.loaded = false;
  Drupal.mobileToolbar.types = 'search navigation';

  Drupal.spoorAcht = {};
  Drupal.slideShow = {};
  Drupal.homeSessions = {};

  $(document).ready(function() {
    Drupal.homeSessions.initialize();

    Drupal.spoorAcht.setContactToggle();
    // Show or initialize the slideshow.
      Drupal.slideShow.enable();
    // Initialise the mobile toolbar.
    Drupal.mobileToolbar.initialise();

    // Function to hide ajax-loader on video iframe
    $('iframe').load(function () {
      $('.loading-image').hide();
    });


    // Check the current window width for mobile menu;
    if ($(window).width() < Drupal.breakpoints.medium) {
      Drupal.spoorAcht.setSessionBackground();
      if (Drupal.mobileToolbar.loaded && $("#mobile-toolbar").hasClass('loaded')) {
        Drupal.mobileToolbar.enable();
      }
    }
  });

  $(window).resize(function() {
    if ($(window).width() < Drupal.breakpoints.medium) {
      // Initialise or enable mobile menu.
      if (Drupal.mobileToolbar.loaded & $("#mobile-toolbar").hasClass('loaded')) {
        Drupal.mobileToolbar.enable();
      }
      Drupal.spoorAcht.setSessionBackground();
    }
    else {
      Drupal.homeSessions.initialize();

      Drupal.mobileToolbar.disable();
      if ($(window).width() < Drupal.breakpoints.large) {
        Drupal.spoorAcht.setSessionBackground();
      }
      else {
        // On session reset the green background.
        $("#content-wrapper").css({'background-position-y' : '0px'});
      }
    }
  }
);

/*
 * Add Infield labels to the contact form.
 */
  Drupal.behaviors.contactFieldLabels = {
    attach: function (context) {
      $("#contact label").inFieldLabels({
        fadeOpacity: 0.2,
        fadeDuration: 100
      });
    }
  };

  /*
   * Contact form toggle functionality.
   */
  Drupal.spoorAcht.setContactToggle = function() {
    var contact = $("#contact");
    var closeButton = $('<div id="contact-close">close</div>').click(function(){
      contact
        .toggleClass('toggled')
        .animate({'width': '30px'}
      );
    });
    $("#contact .block-webform .content").append(closeButton);
    // Toggle block.
    $("#contact .block-toggle-contact .content div").click(function(){
      if (contact.hasClass('toggled')) {
        contact.animate({'width': '30px'}).toggleClass('toggled');
      }
      else {
        contact.animate({'width': '530px'}).toggleClass('toggled');
      }
    });
  }

  // Background on session detail page. Move the background up, so the
  // bottom will match the shadow on the video.
  Drupal.spoorAcht.setSessionBackground = function() {
    var maxHeight = 304;
    var currentHeight = $(".field-session-video").height();
    var backgroundPosition = currentHeight - maxHeight;
    if (backgroundPosition > 0) {backgroundPosition = -13;}
    $("#content-wrapper").css({'background-position-y' : backgroundPosition + 'px'});
  }
  /*
   * Create the mobile toolbar buttons and content.
   */
  Drupal.mobileToolbar.initialise = function() {
    // Add the toggle buttons for search and menu to the toolbar.
    var typesArray = Drupal.mobileToolbar.types.split(' ');
    var type = '';
    var buttonDiv = '';
    var toolbarHtml = ''
    var contactToggle = $("<div>");
    contactToggle.addClass('clearfix mobile-visible')
      .attr('id', 'toggle-contact')
      .html('<div class="toolbar-button-wrapper"><a href="contact" id="contact-link">Contact</a></div></div>')
      .insertAfter("#toolbar div:first").hide();

    for (var i = 0; i < typesArray.length; i++) {
      type = typesArray[i];
      // Prepare toolbar button html.
      toolbarHtml += $('#' + type).html();
      // Create the toggle buttons for mobile layout and add to their respective
      // regions.
      buttonDiv = $("<div>")
        .addClass('toolbar-button-wrapper mobile-visible')
        .attr('id', 'toggle-' + type)
        .html('<div class="toolbar-button" id="btn-' + type + '">Toggle ' + type + '</div>');
         buttonDiv.appendTo($('#' + type)).hide();
    }

    // Fill mobile toolbar.
    $("#mobile-toolbar")
      .html(toolbarHtml)
      .addClass('loaded');

    // Add mobile toggle functionality.
    $('.toolbar-button').click(function() {
      // Add the current type as class-name.
      var currentToggle = $(this).attr('id');
      var className = currentToggle.substr(4);
      // The mobile toolbar is hidden, show it and set toggled type class.
      if ($("#mobile-toolbar").hasClass('hidden')) {
        $("#mobile-toolbar")
          .addClass(className)
          .removeClass('hidden');
      }
      else {
        // Toggled item is visible, hide the mobile toolbar.
        if ($("#mobile-toolbar").hasClass(className)) {
          $("#mobile-toolbar")
            .removeClass(Drupal.mobileToolbar.types)
            .addClass('hidden');
        }
        else {
          // Other item is visible, switch content.
          // Remove all type classes from mobile toolbar and set toggled type
          // class.
          $("#mobile-toolbar")
            .removeClass(Drupal.mobileToolbar.types)
            .addClass(className);
        }
      }
    });

    // Set loaded.
    Drupal.mobileToolbar.loaded = true;
  }

  /**
   * Enable slideshow
   **/
  Drupal.slideShow.enable = function() {
    if ($('#session-carousel').length) {
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
        circular: true,
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
        $('#session-carousel').trigger('slideTo', '#' + this.id.split('id-').pop());
        $('#session-thumbs a').removeClass('selected');
        $(this).addClass('selected');
        return false;
      });
    }
  }

  /**
   * Enable mobile navigation.
   */
  Drupal.mobileToolbar.enable = function() {
    // Show the mobile buttons.
    $(".mobile-visible").show();
    // Hide the desktop search and menu.
    $('#search .region-search').hide();
    $('#navigation .region-navigation').hide();
    // Hide the destop contact block.
    $('.region-contact').addClass('hidden');
    // Switch language switcher styling.
    $(".language-switcher-locale-url li").addClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").addClass('toolbar-button');
  }

  /**
   * Disable mobile navigation.
   */
  Drupal.mobileToolbar.disable = function() {
    // Hide mobile toolbar buttons.
    $(".mobile-visible").hide();
    // Show desktop elements.
    $('.region-contact').removeClass('hidden');
    $('#search .region-search').show();
    $('#navigation .region-navigation').show();
    // Switch language switcher styling.
    $(".language-switcher-locale-url li").removeClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").removeClass('toolbar-button');
    // Hide the mobile content.
    $("#mobile-toolbar").addClass('hidden');
  }

  Drupal.homeSessions.initialize = function() {
    if ($(window).width() >= Drupal.breakpoints.medium) {
      if (!$("#featured-session").hasClass('loaded')) {
        // If on homepage, load the featured session and session carousel.
        var ajaxUrl = new Array('featured', 'slideshow');
        var prefix = '/spoor_acht_custom-ajax/nojs/';

        for (i = 0; i < ajaxUrl.length; i++) {
          $.getJSON(prefix + ajaxUrl[i], function(response) {
            console.log(response[1]);
            if (response[1].data  && response[1].selector) {
              // Set the block.
              if (response[1].method =='append') {
                var sessions = $(response[1].selector)
                  .append(response[1].data)
                  .find('.slideshow-sessions-home .view-content');
              }
              else {
                var sessions = $(response[1].selector)
                  .html(response[1].data)
                  .find('.slideshow-sessions-home .view-content');
              }

              // If its the slideshow, apply caroufredsel.
              if (sessions.length) {
                sessions.parent().append('<div id="prev">Prev</div><div id="next">Next</div>');
                sessions.carouFredSel({
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
                    width: 211,
                    height: '72.2464454976%'
                  }
                });
              }
            }
          });
        }
        $("#featured-session").addClass('loaded');
      }
    }
  }
})(jQuery, Drupal);
