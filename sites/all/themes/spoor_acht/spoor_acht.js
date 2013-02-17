(function ($, Drupal) {
  /**
   * Initialize objects used later.
   */
  Drupal.breakpoints = {};
  Drupal.breakpoints.small = 480;
  Drupal.breakpoints.medium = 603;
  Drupal.breakpoints.large = 960;

  Drupal.mobileToolbar = {};
  Drupal.mobileToolbar.loaded = false;
  Drupal.mobileToolbar.types = 'search navigation';

  $(document).ready(function() {
    // Initialise the mobile toolbar.
    Drupal.mobileToolbar.initialise();

    // Check the current window width;
    if ($(window).width() <= Drupal.breakpoints.medium) {
      if (Drupal.mobileToolbar.loaded && $("#mobile-toolbar").hasClass('loaded')) {
        Drupal.mobileToolbar.enable();
      }
    }
  });

  $(window).resize(  // Use debounce to rate-limit function.
    function() {
      if ($(window).width() < Drupal.breakpoints.medium) {
        // Initialise or enable mobile menu.
        if (Drupal.mobileToolbar.loaded & $("#mobile-toolbar").hasClass('loaded')) {
          Drupal.mobileToolbar.enable();
        }
      }
      if ($(window).width() >= Drupal.breakpoints.medium) {
          Drupal.mobileToolbar.disable();
      }
    }
  );

  Drupal.mobileToolbar.initialise = function() {
    // Fill mobileToolbar container.
    $("#mobile-toolbar")
      .html($('#navigation').html() + $('#search').html())
      .addClass('loaded');
    Drupal.mobileToolbar.loaded = true;

    // Create the toggle buttons for mobile layout and add to their respective
    // regions.
    var typesArray = Drupal.mobileToolbar.types.split(' ');
    for (var i = 0; i < typesArray.length; i++) {
      var type = typesArray[i];
      var buttonDiv = $("<div>")
        .addClass('toolbar-button-wrapper')
        .attr('id', 'toggle-' + type)
        .html('<div class="toolbar-button" id="btn-' + type + '">Toggle ' + type + '</div>')
        .appendTo($('#' + type)).hide();
    }

    // Add menu toggle functionality.
    $('.toolbar-button').click(function() {
      var currentToggle = $(this).attr('id');
      var className = currentToggle.substr(4);
      if ($("#mobile-toolbar").hasClass('hidden')) {
        $("#mobile-toolbar").removeClass(Drupal.mobileToolbar.types);
        $("#mobile-toolbar").addClass(className);
        $("#mobile-toolbar").removeClass('hidden');
        $("#content-wrapper").removeClass('l-move-under');
        $("#mobile-toolbar").addClass('l-move-under');
      }
      else {
        if ($("#mobile-toolbar").hasClass(className)) {
          $("#mobile-toolbar").addClass('hidden');
          $("#content-wrapper").addClass('l-move-under');
          $("#mobile-toolbar").removeClass('l-move-under');
        }
        else {
          $("#mobile-toolbar").removeClass(Drupal.mobileToolbar.types);
          $("#mobile-toolbar").addClass(className);
        }
      }
    });
  }


  /**
   * Enable mobile navigation.
   */
  Drupal.mobileToolbar.enable = function() {
    // Show the mobile buttons.
    $('#search .region-search').hide();
    $('#navigation .region-navigation').hide();
    $('#toggle-search').show();
    $('#toggle-navigation').show();
    $(".language-switcher-locale-url li").addClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").addClass('toolbar-button');
  }

  Drupal.mobileToolbar.disable = function() {
    // Toggle toolbar elements.
    $('#search .region-search').show();
    $('#navigation .region-navigation').show();
    $('#toggle-search').hide();
    $('#toggle-navigation').hide();
    $(".language-switcher-locale-url li").removeClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").removeClass('toolbar-button');

    // Hide the mobile navigation.
    $("#mobile-toolbar").addClass('hidden');
    // Ensure content moves under header.
    if (!$("#content-wrapper").hasClass('l-move-under')) {
      $("#content-wrapper").addClass('l-move-under');
    }
  }

  /**
   * Enable mobile navigation.
   *
  Drupal.mobileToolbar.language.enable = function() {
    // Initialise.
    $(".language-switcher-locale-url li").addClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").addClass('toolbar-button');
  }

  Drupal.mobileToolbar.language.disable = function() {
    $(".language-switcher-locale-url li").removeClass('toolbar-button-wrapper');
    $(".language-switcher-locale-url li a").removeClass('toolbar-button');
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
