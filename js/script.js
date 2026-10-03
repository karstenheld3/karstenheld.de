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

  /*
   * "Go to project" button handlers
   * Each handler scrolls to #work and navigates the #full-view flexslider to a specific slide index (0-based).
   * The slide index corresponds to the position of the slide in the HTML (div.slide elements inside #full-view).
   *
   * HOW TO ADD A NEW "Go to project" BUTTON:
   * 1. In index.html, add: <a href="#work" id="btnShowXxx" class="btn btn-xs btn-primary-light btn-square">Go to project</a>
   * 2. Count the 0-based position of the target slide in the #full-view .slides div
   * 3. Add a handler here: $('#btnShowXxx').on('click', function(e) { ... fullView.flexslider(INDEX); })
   * 4. If you INSERT a new slide, increment ALL indices below that point by 1
   *
   * Current slide order (Aug 2026):
   * 0=GPT-Middleware, 1=VF-MOC, 2=VF-SiteProvisioning, 3=URLShortener, 4=PermissionCenter,
   * 5=VF-RESI, 6=TK-PIMS, 7=M-OnSite, 8=MEvents-Projects, 9=CryptoXL, 10=CarlGmbH,
   * 11=MEvents-Intranet, 12=ETT, 13=DT-Design, 14=Vescore-PM, 15=Vescore-MN,
   * 16=Vescore-FE, 17=BencerWeb2012, 18=BencerWeb2011, 19=BencerWeb2010,
   * 20=Vescore-FU, 21=Vescore-IC, 22=TODI, 23=WhizzyTools-CD
   */

  $('#btnShowGPTMiddleware').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(0);
    });
  })

  $('#btnShowVFMoc').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(1);
    });
  })

  $('#btnShowVFSiteProvisioning').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(2);
    });
  })

  $('#btnShowMOnSite').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(7);
    });
  })

  $('#btnShowMEventsProjects').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(8);
    });
  })

  $('#btnShowCryptoXL').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(9);
    });
  })

  $('#btnShowCarlGmbH').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(10);
    });
  })

  $('#btnShowMEventsIntranet').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(11);
    });
  })

  $('#btnShowEtt').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(12);
    });
  })

  $('#btnShowDt').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(13);
    });
  })

  $('#btnShowPm').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(14);
    });
  })

  $('#btnShowMn').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(15);
    });
  })

  $('#btnShowBencerWeb2012').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(17);
    });
  })

  $('#btnShowBencerWeb2011').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(18);
    });
  })

  $('#btnShowBencerWeb2010').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(19);
    });
  })

  $('#btnShowWhizzyToolsCd').on('click', function(e) {
    var fullView = $('#full-view');
    fullView.slideDown('slow', function() {
      fullView.flexslider(23);
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
      },
      after: function(slider){
        var slideEl = slider.slides.eq(slider.currentSlide);
        if (slideEl.hasClass('clone')) { return; }
        var slideId = slideEl.attr('id');
        if (slideId) {
          history.replaceState(null, null, '#' + slideId);
        }
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

  //Hash-based deep linking to work samples
  //Enables URLs like karstenheld.de#sharepoint-gpt-middleware to open that slide directly
  var workHash = window.location.hash;
  if (workHash) {
    var targetSlide = $(workHash + '.slide');
    if (targetSlide.length) {
      var fullView = $('#full-view');
      setTimeout(function() {
        var slider = fullView.data('flexslider');
        var slideIndex = slider ? slider.slides.index(targetSlide) : $('#full-view .slide').index(targetSlide);
        fullView.slideDown('slow');
        fullView.flexslider(slideIndex);
        $('html, body').animate({
          scrollTop: $('#work').offset().top - ($('.navbar .container').height() + 5)
        }, 500);
        fullView.trigger("resize");
      }, 500);
    }
  }
});