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

 // Drupal.slideShow = {};
  $(document).ready(function() {
    Drupal.spoorAcht.setContactToggle();

  //  Drupal.slideShow.element = $('.html-carousel .view-content');

//var trimmedText =+ $(this).text().substr(0, 800).lastIndexOf(" ");
//      var shortText = $(this).text().trim().substring(0, sumMotherfukkentext).split(" ").slice(0, -1).join(" ") + "...";


/* Start carousel */
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
/* End carousel */

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

/*
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
*/
  $(window).resize(function() {
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

          if ($(window).width() < Drupal.breakpoints.large) {
            // Background on session detail page. Move the background up, so the
            // bottom will match the shadow on the video.
            var maxHeight = 304;
            var currentHeight = $(".field-session-video").height();
            var backgroundPosition = (currentHeight - maxHeight) + 'px';
            $("#content-wrapper").css({'background-position-y' : backgroundPosition});

           // Trim text on session detail.
            var maxWidth = 399;
            var maxHeight = 160;
            var currentWidth = $(".node-session .field-name-title").width();
            var maxLength = 800;  // width = 1024
            var theLength = 0;
            var trimmedText = '';
            // 1 line = 16px &&  chars;

            $(".node-session .field-name-body p").each( function () {
              theLength = theLength + $(this).text().length;
              trimmedText = trimmedText + $(this).text();
            });

            maxLength = $(window).width() / Drupal.breakpoints.large * 0.6 * maxLength;
            if (theLength > maxLength) {
              position = trimmedText.substr(0, Math.round(maxLength)).lastIndexOf(" ");
              var trimmedText = trimmedText.trim().substring(0, position).split(" ").slice(0, -1).join(" ") + "...";
              $(".node-session .field-name-body").html('<p>' + trimmedText + '</p>');
            }
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

})(jQuery, Drupal);
