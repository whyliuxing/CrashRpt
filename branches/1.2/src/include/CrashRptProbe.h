/*! \file   CrashRptProbe.h
 *  \brief  Defines the interface for the CrashRptProbe.DLL.
 *  \date   2009
 *  \author zexspectrum@gmail.com
 */

#ifndef __CRASHRPT_PROBE_H__
#define __CRASHRPT_PROBE_H__

#ifdef CRASHRPTPROBE_EXPORTS
#define CRASHRPTPROBE_API __declspec(dllexport)
#else
#define CRASHRPTPROBE_API __declspec(dllimport)
#endif


/*! \defgroup CrashRptProbeAPI CrashRptProbe Functions*/


/*! \ingroup CrashRptProbeAPI
 *  \brief Opens a zipped crash report file.
 *
 *  \return This function returns zero on success, else non-zero.
 *
 *  \param[in] lpszFileName Zipped report file name.
 *  \param[out] lpuHandle Handle to the opened crash report.
 *
 *  \remarks
 *
 *  The crpOpenCrashReportW() and crpOpenCrashReportA() are wide character and multibyte 
 *  character versions of crpOpenCrashReport(). 
 */

CRASHRPTPROBE_API int
crpOpenCrashReportW(
  LPCWSTR lpszFileName,
  LPUINT lpuHandle
);

/*! \ingroup CrashRptProbeAPI
 *  \copydoc crpOpenCrashReportW
 *
 */

CRASHRPTPROBE_API int
crpOpenCrashReportA(
  LPCSTR lpszFileName,
  LPUINT lpuHandle
);

/*! \brief Character set-independent mapping of crpOpenCrashReportW() and crpOpenCrashReportA() functions. 
 *  \ingroup CrashRptProbeAPI
 */

#ifdef UNICODE
#define crpOpenCrashReport crpOpenCrashReportW
#else
#define crpOpenCrashReport crpOpenCrashReportA
#endif //UNICODE

/*! 
 *  \brief Closes the crash report.
 *  \return This function returns zero if successful, else non-zero.
 *  \param[in] uHandle Handle to the crash report.
 *
 *  \remarks
 *
 */

CRASHRPTPROBE_API int
crpCloseCrashReport(
  UINT uHandle  
);

/* Property names passed to crpGetStrProperty() and crpGetIntProperty() */
#define CRP_PROPS_CRASHRPT_VERSION    1 //! Version of CrashRpt library that generated the report (string)
#define CRP_PROPS_CRASH_GUID          2 //! Globally unique identifier of the error report (string)
#define CRP_PROPS_APP_NAME            3 //! Application name (string)
#define CRP_PROPS_APP_VERSION         4 //! Application version (string)
#define CRP_PROPS_IMAGE_NAME          5 //! Path to the executable file (string)
#define CRP_PROPS_OPERATING_SYSTEM    6 //! Opration system name, including build number and service pack (string)
#define CRP_PROPS_SYSTEM_TIME_UTC     7 //! Time (UTC) when the crash had occured (string)
#define CRP_PROPI_EXCEPTION_TYPE      8 //! Code of exception handler that cought the exception (long)
#define CRP_PROPI_EXCEPTION_CODE      9 //! Exception code; for the structured exceptions only (long)
#define CRP_PROPS_INVPARAM_FUNCTION   10 //! Function name; for invalid parameter errors only (string)
#define CRP_PROPS_INVPARAM_EXPRESSION 11 //! Expression; for invalid parameter errors only (string)
#define CRP_PROPS_INVPARAM_FILE       12 //! Source file name; for invalid parameter errors only (string)
#define CRP_PROPI_INVPARAM_LINE       13 //! Source line; for invalid parameter errors only (long)
#define CRP_PROPI_FPE_SUBCODE         14 //! Subcode of floating point exception; for FPE exceptions only (long)
#define CRP_PROPS_USER_EMAIL          15 //! Email of the user who sent this report (string)
#define CRP_PROPS_PROBLEM_DESCRIPTION 16 //! User-provided problem description (string)
#define CRP_PROPI_FILE_COUNT          17 //! Number of files contained in th error report (long)
#define CRP_PROPS_FILE_ITEM_NAME      256 //! Name of the first file contained in the report (string)

/*! \ingroup CrashRptProbeAPI
 *  \brief Retrieves a string property from crash report.
 *  \return This function returns zero on success, otherwize non-zero.
 */

CRASHRPTPROBE_API int
crpGetStrPropertyW(
  UINT uHandle,
  LPCWSTR lpszPropName,
  LPWSTR lpszBuffer,
  UINT uBuffSize
);

/*! \ingroup CrashRptProbeAPI
 *  \copydoc crpGetStrPropertyW
 *
 */

CRASHRPTPROBE_API int
crpGetStrPropertyA(
  UINT uHandle,
  LPCSTR lpszPropName,
  LPSTR lpszBuffer,
  UINT uBuffSize
);

/*! \brief Character set-independent mapping of crpGetStrPropertyW() and crpGetStrPropertyA() functions. 
 *  \ingroup CrashRptProbeAPI
 */

#ifdef UNICODE
#define crpGetStrProperty crpGetStrPropertyW
#else
#define crpGetStrProperty crpGetStrPropertyA
#endif //UNICODE

/*! \ingroup CrashRptProbeAPI
 *  \brief Retrieves a long property from the crash report.
 *  \param[in] uHandle Handle to the crash report.
 *  \param[in] lpszPropName Name of the
 */

CRASHRPTPROBE_API int
crpGetLongPropertyW(
  UINT uHandle,
  LPCWSTR lpszPropName,
  PLONG lpnPropVal
);

/*! \ingroup CrashRptProbeAPI
 *  \brief
 *
 */

CRASHRPTPROBE_API int
crpGetLongPropertyA(
  UINT uHandle,
  LPCSTR lpszPropName,
  PLONG lpnPropVal
);

/*! \brief Character set-independent mapping of crpGetLongPropertyW() and crpGetLongPropertyA() functions. 
 *  \ingroup CrashRptProbeAPI
 */

#ifdef UNICODE
#define crpGetLongProperty crpGetLongPropertyW
#else
#define crpGetLongProperty crpGetLongPropertyA
#endif //UNICODE

/*! \ingroup CrashRptProbeAPI
 *  \brief
 *
 */

CRASHRPTPROBE_API int
crpExtractFileW(
  UINT uHandle,
  LPCWSTR lpszFileName,
  LPCWSTR lpszFileSaveAs
);

/*! \ingroup CrashRptProbeAPI
 *  \copydoc crpExtractFileW 
 */

CRASHRPTPROBE_API int
crpExtractFileA(
  UINT uHandle,
  LPCSTR lpszFileName,
  LPCSTR lpszFileSaveAs
);

/*! \brief Character set-independent mapping of crpExtractFileW() and crpExtractFileA() functions. 
 *  \ingroup CrashRptProbeAPI
 */

#ifdef UNICODE
#define crpExtractFile crpExtractFileW
#else
#define crpExtractFile crpExtractFileA
#endif //UNICODE



#endif __CRASHRPT_PROBE_H__