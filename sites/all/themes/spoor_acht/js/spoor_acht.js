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

  $(document).ready(function() {
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
  });

  $(window).resize(
    function() {
      if ($(window).width() < Drupal.breakpoints.medium) {
        // Initialise or enable mobile menu.
        if (Drupal.mobileToolbar.loaded & $("#mobile-toolbar").hasClass('loaded')) {
          Drupal.mobileToolbar.enable();
        }
      }
      else {
        Drupal.mobileToolbar.disable();
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

  /**
   * Initialize objects used later.
   *

  $(document).ready(function() {
    // Initialize the slideshow element when the page has loaded.
    Drupal.slideShow.element = $('.view-slideshow');

    if ($(window).width() >= Drupal.breakpoints.large) {
      if ($('.carousel-container .view-content').length > 0) {
        $('.carousel-container .view-content').setBlogCarousel();
      }
    }
    if ($(window).width() >= Drupal.breakpoints.medium) {
      if ($('.carousel-container .view-content').length > 0) {
        $('.carousel-container .view-content').addClass('wide-layout');
      }

      $('.front .panel-3col-33-stacked .center-wrapper .panel-panel').equalHeights();

      // Show or initialize the slideshow.
      Drupal.slideShow.enable();
    }
  });

  $(window).resize(function() {
    if ($('.carousel-container .view-content').length > 0) {
      if ($(window).width() >= Drupal.breakpoints.medium) {
        $('.carousel-container .view-content').addClass('wide-layout');
      }
      if ($(window).width() >= Drupal.breakpoints.large) {
        if ($('#carousel').length <= 0) { // Avoid loading multiple times.
          $('.carousel-container .view-content').setBlogCarousel();
        }
      }
      else {
        // Reload the page to hide the caroussel and show the normal list
        // instead. It is too hard to undo the carousel plugin code on resize.
        if ($('.carousel-container .view-content').hasClass('wide-layout')) {
          window.location.reload();
        }
      }
    }

    if ($(window).width() >= Drupal.breakpoints.medium) {
      $('.front .panel-3col-33-stacked .center-wrapper .panel-panel').height('auto').equalHeights();

      // Show or initialize the slideshow.
      Drupal.slideShow.enable();
      // Set a height so the pager feels responsive.
      Drupal.slideShow.setHeight();
    }
    else {
      $('.front .panel-3col-33-stacked .center-wrapper .panel-panel').height('auto');

      // Hide the slideshow.
      Drupal.slideShow.element.hide();
    }
  });

  /**
   * Show or initialize the slideshow.
   *
  Drupal.slideShow.enable = function() {
    if (!Drupal.slideShow.element.hasClass('loaded')) {
      // Create the pager.
      Drupal.slideShow.element.append('<div class="pager"></div>');

      // Create the slideshow.
      Drupal.slideShow.element.show().find('.view-content').carouFredSel({
        responsive: true,
        items: {
          visible: 1,
          width: 940
        },
        scroll: {
          items: 1,
          easing: 'quadratic',
          duration: 1000,
          pauseOnHover: true
        },
        auto: {
          timeoutDuration: 4000
        },
        pagination: '.view-slideshow .pager',
        onCreate: function(options) {
          // Set a height so the pager feels responsive.
          Drupal.slideShow.setHeight();
          // Add a class so we do not load the slideshow twice.
          Drupal.slideShow.element.addClass('loaded');
        }
      });
    }
    else {
      Drupal.slideShow.element.show();
    }
  }

  /**
   * Set a height so the pager feels responsive.
   *
  Drupal.slideShow.setHeight = function() {
    // We use the height of an img because its height is automatically adjusted
    // by the browser. See the img style in base.css.
    var width = Drupal.slideShow.element.width(),
        height = width * (250 / 940);
    console.log(height);
    Drupal.slideShow.element.height(height);
  }

  /**
   * Enable the carousel on the blog page.
   *
  $.fn.setBlogCarousel = function() {
    // Plugin needs an ID.
    this.attr('id', 'carousel');
    this.parent().append('<div id="carousel-left">left</div><div id="carousel-right">right</div>');
    $('#carousel .group_publish_info, #carousel .field-name-body').hide();
    $('#carousel').featureCarousel({
      autoPlay: 0,
      preload: false,
      largeFeatureWidth: 538,
      largeFeatureHeight: 146,
      smallFeatureWidth: 240,
      smallFeatureHeight: 86,
      topPadding: 60,
      sidePadding: 0,
      smallFeatureOffset: -54,
      trackerIndividual: false,
      leavingCenter: function($feature) {
        $feature
          .removeClass('center-feature')
          .find('.group_publish_info, .field-name-body')
          .hide();
      },
      movedToCenter: function($feature) {
        $temp = $feature
          .addClass('center-feature')
          .find('.group_publish_info, .field-name-body')
          .show();
      }
    });
  }

  /**
   * Give multiple elements the same height.
   *
  $.fn.equalHeights = function() {
    tallest = 0;
    this.each(function() {
      if ($(this).height() > tallest) {
        tallest = $(this).height();
      }
    });
    return this.each(function() {
      $(this).height(tallest);
    });
  }*/

})(jQuery, Drupal);
