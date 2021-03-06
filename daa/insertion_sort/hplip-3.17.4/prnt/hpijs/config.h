/*****************************************************************************\
  config.h : configuration include header

  Copyright (c) 1996 - 2015, HP Co.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
  3. Neither the name of HP nor the names of its
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
  NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
  TO, PATENT INFRINGEMENT; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\*****************************************************************************/

/* Do NOT edit this file. Commenting or uncommenting the macro #defines below
will not change the build options!
*/

/*! \addtogroup build_options Build Options
This exists primarily as documentation of build options. All build options are
documented here.  The actual #defines are only included if documentation is being built.
One can read though this file or the documentation to determine which options to include
as input to the build process. config.h also sets up internal macros for
including /excluding code based on compiler and defined public macros.
\since Version 3.00.01
@{
*/

#ifndef APDK_CONFIG_H
#define APDK_CONFIG_H

#ifdef APDK_INTERNAL_CREATE_DOCUMENTATION

/*! \addtogroup font_options Font Options
Define one or more of the font directive to enable device fonts.
These need to be defined to support hardware fonts in the printer.  Enabling fonts
is NOT recommended, however if ASCII text needs to be sent to the printer then define
the font(s) needed.  Only define the fonts that will be used, each font that is enabled
will make the code size larger.  See \ref devfonts for more information about fonts or
PrintContext::RealizeFont() to create a font.
@{
*/

#define APDK_CGTIMES        //!< Include support for CGTimes font - see \ref devfonts

#define APDK_COURIER        //!< Include support for Courier font - see \ref devfonts

#define APDK_LTRGOTHIC      //!< Include support for Letter Gothic font - see \ref devfonts

#define APDK_UNIVERS        //!< Include support for  Universe font - see \ref devfonts

/*! @} */  //end of Font Options group


/*!
Define this if build is for a little endian processor
\since Version 2.3.0
*/
#define APDK_LITTLE_ENDIAN


/*!
Compiles in code that allows for auto duplex on printers that support a duplexer.
On most inkjet printers, when the duplexer refeeds the paper, the back side will be
rotated 180 degrees with respect to the front side, resulting in tabelt mode duplexing
(stapled on the short edge). To print duplexed in booklet mode (stapled on the long edge),
the application must rotate the whole page image by 180 degrees before sending the rasters.
Call PrintContext::RoateteImageForBackPage () to determine if the selected printer needs
back page rotated.
*/
#define APDK_AUTODUPLEX

/*!
Compiles in code that allows for additional media size for large resource system
\since Version 3.6.0
*/
#define APDK_EXTENDED_MEDIASIZE


/*!
This makes several changes to the code path to ensure maximum speed:
\li First, speed optimization forces the use of matrix half toning instead of what the print mode
requests.  Typically matrix is used for draft modes because it is faster and not as good
of quality.  Speed optimization uses matrix for all print modes.
\li Second, speed optimization forces the use of open color matching instead of proprietary
color matching.  Open is faster and not as good.  Proprietary color matching is not included
in the open source code.
\li Third, it forces the use of open scaling which is quicker and not as good as proprietary
scaling. Proprietary scaling is not include in the open source code.
\since Version 2.4.0
*/
#define APDK_OPTIMIZE_FOR_SPEED


/*!
By default color filtering (Ernie code) is turned off.  Color filtering
helps with RLE compression (Bert) when sending data to the printer. Color filtering is
only used with VIP printers and should only be turned on when the DJ9xxVIP family of printers
is supported.  Turning on color filtering will help in the situation where there is
high CPU resources available and low I/O bandwidth.  Color filtering reduces the amount of
data sent to the printer by matching colors so that RLE compression is more effective.  If
CPU resources a low do not turn on color filtering.
\note APDK_VIP_COLORFILTERING has no effect unless \ref APDK_DJ9xxVIP is also defined.
\since Version 3.00.00
*/
#define APDK_VIP_COLORFILTERING


/*!
By default all APDK classes, types, variables, etc... belong to the apdk namespace.
This minimizes the conflicts when integrating with existing code.  The code that calls the APDK
driver code should include the line "using namespace APDK_NAMESPACE;".  If there are specific
conflicts with other names then the name should be specifically specified (i.e.
APDK_NAMESPACE::DRIVER_ERROR or APDK_NAMESPACE::Job, etc...).  Define APDK_NO_NAMESPACE to
eliminate the namespace definitions and all APDK names will be placed in the global namespace.
\since Version 3.00.01
*/
#define APDK_NO_NAMESPACE


/*!
For embedded devices the APDK defaults to lower (normal) resolution print modes.
This facilitates sending less data on lower end (low bandwidth / low CPU) devices.
On VIP printers this data is scaled up internally so the print quality is good.
For high end devices or OSs, such as Linux, defining APDK_HIGH_RES_MODES will cause
some VIP printer modes to send higher resolution data to the printer.  This will
cause higher CPU utilization and use more I/O bandwidth.  However, results could
be better if the input data is truly more then 300 DPI.  If the input data is not
significantly higher then 300 DIP then turning on APDK_HIGH_RES_MODES will unncessarily
burn CPU cycles and I/O bandwidth.
\note Currently this only effects VIP printers.
\since Version 3.00.02
*/
#define APDK_HIGH_RES_MODES


/*!
This turns on output buffering.  Without buffering the APDK sends out each byte
as it is ready.  With buffer send on the APDK buffers up output data and sends it to the
printer when the buffer is full.  To set the size of the buffer set the
SystemServicesa::iSendBufferSize variable in your derived SystemServices and define this
directive.  The default buffer size, if not specified, is 4096 bytes.
*/
#define APDK_BUFFER_SEND


/*
Usage Log: What does this do guys?
*/

// #define APDK_USAGE_LOG


/*!
Turn on capturing utility for debugging.  This creates script files that document
order of calls and state of APDK and PCL output.
*/
#define APDK_CAPTURE


/*
Prototype: Do NOT define APDK_PROTO.  It is for internal use only and facilitates testing
with HP's test harness.  The APDK will not successfully compile with APDK_PROTO defined.
*/

//#define APDK_PROTO


/*! \addtogroup printer_options Printer Options
Printer families:  Define one or more of these to support printer families.
@{
*/

/* Do NOT enable DJ400 or DJ540 - they are not supported, only legacy,
unsupported code exists for these two printers.
*/

/*!
Enable support for Apollo P-2200 and the Deskjet 656.
*/
#define APDK_APOLLO2XXX

/*!
enables support for the Apollo P-2100.
*/
#define APDK_APOLLO21XX

/*!
Enables support for the Apollo P-2500 and P-2600.
*/
#define APDK_APOLLO2560

/*!
Enables support for the Deskjet 350.
*/
#define APDK_DJ350

/*
Do NOT define this - the 400 is not supported
Enables support for the Deskjet 400.
*/
//#define APDK_DJ400

/*
Do NOT define this - the 540 is not supported
Enables support for the Deskjet 540.
*/
//#define APDK_DJ540

/*!
Enables support for the Deskjet 600.
*/
#define APDK_DJ600

/*!
Enables support for the Deskjet 630.
*/
#define APDK_DJ630

/*!
Enables support for the Deskjet 660, 670, 680, 6xx, e-printer.
*/
#define APDK_DJ6xx

/*!
Enables support for the Deskjet 610, 640, 690
*/
#define APDK_DJ6xxPhoto

/*!
Enables support for the Deskjet 810, 830, 840, 880, 895, 1125.
*/
#define APDK_DJ8xx

/*!
Enables support for the Deskjet 825, 845.
APDK_DJ8xx must also be defined
*/
#define APDK_DJ8x5

/*!
Enables support for the Deskjet 920, 930, 94x, 950, 970, 1220, 3816, 3820,
PhotoSmart P1000, P1100.
*/
#define APDK_DJ9xx

/*!
Enables support for the Deskjet 450, 960, 980, 990, 995, 6122, 6127,
PhotoSmart 1115, 1215, 1218, 1315
CP 1160, CP 1700
hp business inkjet 2200 series, hp business inkjet 1100
OfficeJet Pro K550, OfficeJet Pro K850 - Note: these two are in OJProKx50 class
*/
#define APDK_DJ9xxVIP

/*!
Enables support for
deskjet 5550, 5551 - Note: these two printers are in DJ55xx class
PhotoSmart 7150, 7350, 7550.
APDK_DJ9xxVIP must also be defined
*/
#define APDK_DJGENERICVIP

/*!
Enables support for the PhotoSmart 100, 130, 230, 240.
APDK_DJ9xxVIP must also be defined
*/
#define APDK_PSP100

/*!
Enables support for the non-hostbased Monochrome LaserJets.
*/
#define APDK_LJMONO

/*!
Enables support for the non-hostbased Color LaserJets.
*/
#define APDK_LJCOLOR

/*!
Enables support for the JetReady host based Color LaserJets.
*/
#define APDK_LJJETREADY

/*!
Enables support for the FastRaster host based LaserJets.
*/
#define APDK_LJFASTRASTER

/*!
Enables support for LaserJet 1000, 1005, 1018, 1020
*/
#define APDK_LJZJS_MONO

/*!
Enables support for the hp and non-hp Postscript Printers
*/
#define APDK_PSCRIPT

/*!
Enables support for DJ 3300, 3400, 3500, 3740 family, psc 1100 series, psc 1200 series, officejet 4100 and 4200.
*/
#define APDK_DJ3320

/*!
Enables support for DJ 3600, 3840 family, psc 1300 series, and officejet 5500 series.
*/
#define APDK_DJ3600

/*!
Enables support for specific Linux resolution requirements for 600 Series
*/
#define APDK_LINUX

/*!
Enables printer ready data compression for DJ3320 and DJ3600 class of printers. This
is beneficial where I/O bandwidth is low. May reduce performance on devices
that have low power CPUs.
*/
#define APDK_LDL_COMPRESS

/*! @} */  //end of Printer Options group
/*! @} */  //end of Build Options group

/*!
Enables support for HP-UX specific declarations
*/

#define APDK_HP_UX

#endif //APDK_INTERNAL_CREATE_DOCUMENTATION
/*
Now set up some stuff to make it easy in the main code and ensure conflicting
directives are not active.  Don't play with stuff beyond this point in the file.
*/

// Don't allow Ernie ColorFiltering if the VIP family printers are not being built.
// ColorFiltering is only useful for DJ9xxVIP and will just take up code space if
// that printer family is not defined.
#if !defined(APDK_DJ9xxVIP) && defined(APDK_VIP_COLORFILTERING)
    #undef APDK_VIP_COLORFILTERING
#endif


// This is make the #ifdefs in the code more readable since we need to know if any of the
// fonts are defined in a number of places.  If we ever add any other fonts to a printer
// then we can define it here rather then edit the #ifdefs all over the code base.
#if defined(APDK_CGTIMES) || defined(APDK_COURIER) || defined(APDK_LTRGOTHIC) || defined(APDK_UNIVERS)
    #define APDK_FONTS_NEEDED
#else
    #undef APDK_FONTS_NEEDED
#endif

/*!
\namespace apdk
All classes, types, global variables, functions, etc... are in the apdk namespace to avoid
collision with existing code the APDK is integrated with.
\since version 3.00.01
*/
// This will put all enums, typedefs, structs, classes, etc... in the apdk name space if
// APDK_NO_NAMESPACE is not defined.
#if !defined(APDK_NO_NAMESPACE)
    #define APDK_NAMESPACE          apdk
    #define APDK_BEGIN_NAMESPACE    namespace APDK_NAMESPACE {
    #define APDK_END_NAMESPACE      } //namespace apdk
    #define APDK_USING_NAMESPACE    using namespace APDK_NAMESPACE;
#else
    #define APDK_NAMESPACE
    #define APDK_BEGIN_NAMESPACE
    #define APDK_END_NAMESPACE
    #define APDK_USING_NAMESPACE
#endif

/*!
This define is useful for autoconf users who create "auto-include.h" on-the-fly. For example autoconf
can automatically determine the appropriate header file for uint32_t (ie: by storing "#include <stdint.h>" 
in "auto-include.h").
*/
//#define  APDK_AUTO_INCLUDE

#endif //APDK_CONFIG_H
