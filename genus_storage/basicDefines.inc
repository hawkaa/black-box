{$IFDEF CLR}
  {$UNSAFECODE ON}
{$ENDIF}

{$IFDEF VER180}
  {$DEFINE __BASIC_DELPHI_2007__}
  {$DEFINE __BASIC_DELPHI_2007_UP__}
{$ENDIF}

{$IFDEF VER240}
  {$DEFINE __BASIC_DELPHI_XE3__}
  {$DEFINE __BASIC_DELPHI_2007_UP__}
  {$DEFINE __BASIC_DELPHI_XE3_UP__}
{$ENDIF}

{$IFDEF VER290}
  {$DEFINE __BASIC_DELPHI_XE8__}
  {$DEFINE __BASIC_DELPHI_2007_UP__}
  {$DEFINE __BASIC_DELPHI_XE3_UP__}
  {$DEFINE __BASIC_DELPHI_XE8_UP__}
{$ENDIF}

{$IFDEF VER300}
  {$DEFINE __BASIC_DELPHI_10__}
  {$DEFINE __BASIC_DELPHI_2007_UP__}
  {$DEFINE __BASIC_DELPHI_XE3_UP__}
  {$DEFINE __BASIC_DELPHI_XE8_UP__}
  {$DEFINE __BASIC_DELPHI_10_UP__}
{$ENDIF}

{$DEFINE __BASIC_USE_FASTMM4__}

{$IFDEF __BASIC_BASICDEFINES__}
   {$Message Fatal 'Just one of basicDefines.inc and genmDefines.inc are to be included!}
{$ELSE}
  {$DEFINE __BASIC_BASICDEFINES__}
{$ENDIF}

////////////////////////////////////////////////////////////////////////////////
// Include the project define file.
// The projectr define file should be in the project directory and belong to one project only.
{$I basicProjectDefines.inc}
////////////////////////////////////////////////////////////////////////////////

{$DEFINE __GDEF_EVENT_TRACE__}

////////////////////////////////////////////////////////////////////////////////
// Include the personal define file.
// The personal define file must contain a {$DEFINE __PRJ_EBL__} (replace with
// your initials) and any other defines which you consider personal.
// The personal define file is NOT included in Perforce. Make an empty one
// if you do not have any personal defines. Place the file in the same directory as basicDefines.
{$I myBasicDefines.inc}

////////////////////////////////////////////////////////////////////////////////

//
// Personal flags with their implications, set by myBasicDefines.inc
//
{$IFDEF __PRJ_THA__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_THA__}
{$ENDIF}
{$IFDEF __PRJ_JPB__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_JPB__}
{$ENDIF}
{$IFDEF __PRJ_HMJ__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_HMJ__}
{$ENDIF}
{$IFDEF __PRJ_OAB__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_OAB__}
{$ENDIF}
{$IFDEF __PRJ_BAL__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_BAL__}
{$ENDIF}
{$IFDEF __PRJ_EBL__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_EBL__}
{$ENDIF}
{$IFDEF __PRJ_JAN__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_JAN__}
{$ENDIF}
{$IFDEF __PRJ_THE__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_THE__}
{$ENDIF}
{$IFDEF __PRJ_MJA__}
  {$DEFINE __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_MJA__}
{$ENDIF}

//
// __PRJ_PRE_ALPHA__ is set by ReleaseTool (no personal flag set in myBasicDefines.inc)
//
{$IFDEF __PRJ_PRE_ALPHA__}
  {$DEFINE __BASIC_PRE_ALPHA__}
  {$DEFINE __BASIC_VERSION_GIVEN__}
{$ENDIF}

//
// __PRJ_ALPHA__ is set by ReleaseTool (no personal flag set in myBasicDefines.inc)
//
{$IFDEF __PRJ_ALPHA__}
  {$DEFINE __BASIC_ALPHA__}
  {$DEFINE __BASIC_VERSION_GIVEN__}
{$ENDIF}

//
// __PRJ_BETA__ is set by ReleaseTool (no personal flag set in myBasicDefines.inc)
//
{$IFDEF __PRJ_BETA__}
  {$DEFINE __BASIC_BETA__}
  {$DEFINE __BASIC_VERSION_GIVEN__}
{$ENDIF}

{$IFDEF __PRJ_CANDIDATE__}
  {$DEFINE __BASIC_CANDIDATE__}
  {$DEFINE __BASIC_VERSION_GIVEN__}
{$ENDIF}

{$IFDEF __PRJ_RELEASE__}
  {$DEFINE __BASIC_RELEASE__}
  {$DEFINE __BASIC_VERSION_GIVEN__}
{$ENDIF}

{$IFDEF __BASIC_VERSION_GIVEN__}
{$ELSE}
  {$DEFINE __BASIC_PRE_ALPHA__}
{$ENDIF}

{$IFDEF __PRJ_DISABLE_TIMERS__}
  {$DEFINE __BASIC_DISABLE_TIMERS__}
{$ENDIF}

//
//  If pre alpha, then include alpha
//
{$IFDEF __BASIC_PRE_ALPHA__}
  {$DEFINE __BASIC_SYMBOL_LIB__}
  {$DEFINE __BASIC_ALPHA__}
{$ENDIF}

//
//  If alpha, then include beta
//
{$IFDEF __BASIC_ALPHA__}
  {$DEFINE __BASIC_BETA__}
{$ENDIF}

//
// If development then include
//
{$IFDEF __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_DEBUG__}
  {$DEFINE __BASIC_ALTERNATE_EXEC_PATH__}
  {$ASSERTIONS ON}
{$ENDIF}

{$IFDEF __BASIC_BETA__}
  {$DEFINE __BASIC_ALTERNATE_EXEC_PATH__}
  {$ASSERTIONS ON}
{$ENDIF}

{$IFDEF __BASIC_DEBUG__}
  {$DEFINE __BASIC_TRACE__}
{$ENDIF}

////////////////////////////////////////////////////////////////////////////////

// Defines based on presence of .NET assemblies
////////////////////////////////////////////////////////////////////////////////
{$I myBasicDefines.inc}

{$IFDEF __NET_GENUS_LOGIX_COMMON__}
  {$DEFINE __BASIC_ENABLE_DOTNETSYMBOLLIBRARY__}
{$ENDIF}

{$IFDEF __PRJ_VERSION_INTERACTIVE__}
  {$IFDEF __PRJ_VERSION_NON_INTERACTIVE__}
    {$Message Fatal 'Just one of __PRJ_VERSION_INTERACTIVE__ and __PRJ_VERSION_NON_INTERACTIVE__ may be defined!}
  {$ENDIF}
  {$DEFINE __BASIC_USE_CLIPBOARD__}
  {$DEFINE __BASIC_VERSION_INTERACTIVE__}
{$ENDIF}
{$IFDEF __PRJ_VERSION_NON_INTERACTIVE__}
  {$IFDEF __PRJ_VERSION_INTERACTIVE__}
    {$Message Fatal 'Just one of __PRJ_VERSION_INTERACTIVE__ and __PRJ_VERSION_NON_INTERACTIVE__ may be defined!}
  {$ENDIF}
{$ENDIF}

{$IFDEF __PRJ_VERSION_NON_INTERACTIVE__}
{$ELSE}
  {$IFDEF __PRJ_VERSION_INTERACTIVE__}
  {$ELSE}
    {$Message Fatal '__PRJ_VERSION_INTERACTIVE__ or __PRJ_VERSION_NON_INTERACTIVE__ must be defined!}
  {$ENDIF}
{$ENDIF}

(*
{$IFDEF __PRJ_CORE_SERVICE__}
  {$DEFINE __BASIC_ENABLE_DOTNETSYMBOLLIBRARY__}
  {$DEFINE __BASIC_ENABLE_DOTNET_GENUSINTEGRATION__}
{$ENDIF}

{$IFDEF __PRJ_CONFIG_TOOL__}
  {$DEFINE __BASIC_ENABLE_DOTNETSYMBOLLIBRARY__}
  {$DEFINE __BASIC_ENABLE_DOTNET_GENUSINTEGRATION__}
{$ENDIF}

{$IFDEF __PRJ_OFFICE__}
  {$DEFINE __BASIC_ENABLE_DOTNETSYMBOLLIBRARY__}
  {$DEFINE __BASIC_ENABLE_DOTNET_GENUSINTEGRATION__}
{$ENDIF}

{$IFDEF __PRJ_ENABLE_DOTNETSYMBOLLIBRARY__}
  {$DEFINE __BASIC_ENABLE_DOTNETSYMBOLLIBRARY__}
{$ENDIF}
*)

//{$IFDEF __BASIC_PRE_ALPHA__}
//  {$IFDEF __PRJ_FASTMM_FULLDEBUGMODE__}
//    // If this is included, you must distribute the special fastmm DLL (FastMM_FullDebugMode.dll).
//    {$DEFINE __BASIC_FASTMM_FULLDEBUGMODE__}
//  {$ENDIF}
//{$ENDIF}

// Always full debug mode for the developers.
{$IFDEF __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_FASTMM_FULLDEBUGMODE__}
{$ENDIF}

// Make it possible for developers to turn off full debug mode, ie used when profiling. 
{$IFDEF __PRJ_PROFILING__}
  {$UNDEF __BASIC_FASTMM_FULLDEBUGMODE__}
{$ENDIF}


// __BASIC_KEEP_CALLSTACK__: To get correct callstacks by the Jcl library, some switches are needed
{$IFDEF __BASIC_DEVELOPER_VERSION__}
  {$DEFINE __BASIC_KEEP_CALLSTACK__}
{$ENDIF}

//
// Compile with optimizations off in pre-alpha, alpha and beta
//
{$IFDEF __BASIC_BETA__}
  {$DEFINE __BASIC_KEEP_CALLSTACK__}
{$ENDIF}

{$IFDEF __BASIC_KEEP_CALLSTACK__}

  {$INLINE OFF}

  // The $W (STACKFRAMES) directive controls the generation of stack frames for procedures and functions. In the {$W+} state, stack frames are always generated for procedures and functions,
  // even when they're not needed. In the {$W-} state, stack frames are only generated when they're required, as determined by the routine's use of local variables.
  // Some debugging tools require stack frames to be generated for all procedures and functions, but other than that you should never have a need to use the {$W+} state.
  {$STACKFRAMES ON}

  // The $O directive controls code optimization. In the {$O+} state, the compiler performs a number of code optimizations, such as placing variables in CPU registers,
  // eliminating common subexpressions, and generating induction variables. In the {$O-} state, all such optimizations are disabled.
  // Other than for certain debugging situations, you should never have a need to turn optimizations off. All optimizations performed by the Delphi compiler
  // are guaranteed not to alter the meaning of a program. In other words, the compiler performs no "unsafe" optimizations that require special awareness by the programmer.
  // Note: Note: The $O directive can only turn optimization on or off for an entire procedure or function. You can't turn optimization on or off for a single line or group of lines within a routine.
  {$OPTIMIZATION OFF}

  //##EBL20090528 There used to be an else here, but the compiler crashes if there is a {$OPTIMIZATION ON} here.

{$ENDIF}

// Only one exeption handler can be defined
{$DEFINE __BASIC_EXCEPTION_HANDLER_MAD__}
{$DEFINE _madExcept} // This is needed by madExcept

{$IFDEF VER290}
{$DEFINE __BASIC_XE8_UP__}
{$DEFINE __BASIC_XE8_STILL_DOES_NOT_COMPILE__}
{$ENDIF}

{$IFDEF VER300}
  {$DEFINE __BASIC_DELPHI_10__}
  {$DEFINE __BASIC_XE8_UP__}
  {$DEFINE __BASIC_XE8_STILL_DOES_NOT_COMPILE__}
  {$DEFINE __BASIC_DELPHI_10_UP__}
{$ENDIF}

{$DEFINE __BASIC_USE_XE8_JSON_OBJECT__}


{xxx$DEFINE __GDEF_VERSION_GENUS_UPDATE__}
