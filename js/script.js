/********************************************************
 *
 * Custom Javascript code for Curri Bootstrap theme
 * Written by Themelize.me (http://themelize.me)
 *
 *******************************************************/
/*global jRespond */
$(document).ready(function() {
  "use strict";
  
  // Custom code
  // --------------------------------
  
  //IE placeholders
  $('[placeholder]').focus(function() {
    var input = $(this);
    if (input.val() === input.attr('placeholder')) {
      if (this.originalType) {
        this.type = this.originalType;
        delete this.originalType;
      }
      input.val('');
      input.removeClass('placeholder');
    }
  }).blur(function() {
    var input = $(this);
    if (input.val() === '') {
      input.addClass('placeholder');
      input.val(input.attr('placeholder'));
    }
  }).blur();
  
  //fix main nav on scroll
  var navBarYOffset = $("#navigation").offset().top;
  $(window).scroll(function() {
    if ($(window).scrollTop() > navBarYOffset) {
      $('body').addClass('navbar-fixated');
    } else {
      $('body').removeClass('navbar-fixated');
    }
  });
  
  //Scroll Top link
  $(window).scroll(function(){
    if ($(this).scrollTop() > 100) {
      $('[data-js=scroll-show]').addClass('scroll-show');
    } else {
      $('[data-js=scroll-show]').removeClass('scroll-show');
    }
  });
  
  //background & colour switch
  $('a.colour').click(function() {
    var c = $(this).data('colour');
    $('html').toggleClass(c);
    $(this).toggleClass('on');
  });
  
  // Plugins
  // --------------------------------
  //scrollTo
  if(jQuery().onePageNav) {
    $('body').onePageNav({
      filter: 'a[href^="#"]',
      scrollOffset: 100
    });
  }
  
  //setup jPanel Menu
  if($.jPanelMenu) {
    var jPM = $.jPanelMenu({
      menu: '.mobile-toggle',
      direction: 'right',
      trigger: '.mobile-toggle-trigger',
      afterOpen: function() {
        $('.mobile-toggle-trigger').addClass('open');
        $('html').addClass('jpanel-menu-open');
        
        //refresh onePageNav
        $('body').onePageNav({
          filter: 'a[href^="#"]',
          scrollOffset: 0
        });
      },
      afterClose: function() {
        $('.mobile-toggle-trigger').removeClass('open');
        $('html').removeClass('jpanel-menu-open');
      }
    });
    
    //jRespond settings
    var jRes = jRespond([
      {
        label: 'small',
        enter: 0,
        exit: 990
      }
    ]);
    
    //turn jPanel Menu on/off as needed
    jRes.addFunc({
        breakpoint: 'small',
        enter: function() {
          jPM.on();
          
          //add help mobile classes
          $('html').addClass('breakpoint-mobile');
        },
        exit: function() {
          jPM.off();
          $('html').removeClass('breakpoint-mobile');
        }
    });
  }

    $('#btnShowVFProjects').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(3);
    });
  })

    $('#btnShowMOnSite').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(6);
    });
  })


    $('#btnShowMEventsProjects').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(7);
    });
  })
  
    $('#btnShowCryptoXL').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(8);
    });
  })
  
    $('#btnShowCarlGmbH').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(9);
    });
  })

    $('#btnShowMEventsIntranet').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(10);
    });
  })
  
    $('#btnShowEtt').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(11);
    });
  })


  $('#btnShowDt').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(12);
    });
  })

  $('#btnShowPm').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(13);
    });
  })

  $('#btnShowMn').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(14);
    });
  })

  $('#btnShowBencerWeb2012').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(16);
    });
  })

  $('#btnShowBencerWeb2011').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(17);
    });
  })

  $('#btnShowBencerWeb2010').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(18);
    });
  })

  $('#btnShowWhizzyToolsCd').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(22);
    });
  })
  
  $('#btnShowBencerFlyer').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(24);
    });
  })

  $('#btnShowSt').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(25)
    });
  })

  $('#btnShowSj').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(26)
    });
  })

  //flexslider carousels
  $('.flexslider-carousel').each(function() {
    var carouselSettings =  {
      animation: $(this).data('transition') || "slide",
      animationLoop: false,
      selector: ".items > .item",
      itemWidth: $(this).data('item-width'),
      itemMargin: $(this).data('item-margin'),
      move: 1,
      controlNav: typeof $(this).data('item-controls-on') !== 'undefined' ? true : false,
      slideshow: false,
      minItems: $(this).data('min-items') || 1,
      maxItems: $(this).data('max-items') || 5
    };
    
    var navFor = $(this).data('navfor');
    if (navFor !== '') {
      carouselSettings = $.extend({}, carouselSettings, {
        asNavFor: '#'+ navFor
      });
    }
    
    $(this).flexslider(carouselSettings);
  });
  
  //flexslider
  $('.flexslider').each(function(i) {
    //passable settings
    var sliderNav = $(this).data('slidernav') || 'auto';
    var autoStartOff = $(this).data('autostartoff') || false;
    var animation = $(this).data('transition') || 'fade';
    $(this).addClass('flexslider-animation-'+ animation);
 
    var sliderSettings =  {
      id: 'flexslider-'+ i,
      animation: animation,
      selector: ".slides > .slide",
      controlNav: $(this).data('controlnav'),
      directionNav: $(this).data('directionnav'),
      smoothHeight: $(this).data('smoothheight'),
      minItems: $(this).data('min-items') || 1,
      maxItems: $(this).data('max-items') || 1,
      multipleKeyboard: true,
      start: function(slider){
        slider.addClass('slider-safe-hide'); //slider loaded to safe to hide
        
        //load first image
        slider.slides.eq(0).find("img[data-js=unveil]").each(function () {
          $(this).unveil();
        });

        if (autoStartOff === true) {
          slider.flexslider("stop");
        }
      },
      before: function(slider){
        // lazy load
        slider.slides.eq(slider.animatingTo).find("img[data-js=unveil]").each(function () {
          $(this).unveil();
        });
      }
    };

    if (sliderNav !== 'auto') {
      sliderSettings = $.extend({}, sliderSettings, {
        manualControls: sliderNav +' li a',
        controlsContainer: '.flexslider-wrapper'
      });
    }

    $(this).flexslider(sliderSettings);
  });
  
  //projects display
  var fullView = $('#full-view');
  if (fullView.size() > 0) {
    var fullViewParent = fullView.parent();
    fullView.prepend('<a class="close">Close</a>');

    //pager navigation show/hide flexslider
    var workItems = $('#work .item a');
    workItems.removeClass('flex-active');
    workItems.on('click touchstart', function(e) {
      var index = workItems.index($(this));
      
      fullView.slideDown('slow', function() {
        //advance to clicked slide, 2.0 API
        fullView.flexslider(index);
      });
      
      $(this).addClass('flex-active'); // if same slide is clicked that was last open

      $('html, body').animate({
         scrollTop: fullViewParent.offset().top - ($('.navbar .container').height() + 5) //navbar height
      }, 500);
      
      //refresh slider incase full-view is hidden
      fullView.trigger("resize");
      e.preventDefault();
    });
    
    //close link
    fullView.find('.close').on('click touchstart', function() {
      fullView.slideUp('slow');
      $('html, body').animate({
         scrollTop: $('#work').offset().top - ($('.navbar .container').height() + 5) //navbar height
      }, 500);
      $('#work .item a').removeClass('flex-active');
    });
  }
  
  //unveil plugin
  $("img[data-js=unveil-auto]").addClass('unveil-loading');
  $("img[data-js=unveil-auto]").unveil(0, function() {
    $(this).load(function() {
      $(this).removeClass('unveil-loading').addClass('unveil-loaded');
    });
  });
});