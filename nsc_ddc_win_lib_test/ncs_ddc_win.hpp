#pragma once

#ifndef _INC_STDIO
#include <stdio.h>
#endif

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#pragma warning( disable : 4091 )
#pragma comment(lib, "ncs_ddc_win.lib")

#ifndef __cplusplus
#error The header file must be compiled in C++ mode!
#endif

#define DLL_IMPORT_API __declspec(dllimport) 

enum eDDC_ERROR;
class CGenericCalibrator;
struct dYxy;
struct dXYZ;
struct dRGB;

DLL_IMPORT_API class Cncs_ddc_win
{
private:
  bool GetRGBGains(short);
  bool MeasureAndSettle(dYxy *, double);
  FILE* OpenLogFile(wchar_t *);
  bool PreCalibrateCheck(void);
  bool RGBCalibrationMethod(short, double, double);
  bool SetRGBGains(short);
  void XYZ2RGB_NOSCALING(dXYZ *, dRGB *);
  void dumpEnumerationData(void);

public:
  BYTE data[132704];

  Cncs_ddc_win(void);
  ~Cncs_ddc_win(void);

  Cncs_ddc_win & operator= (Cncs_ddc_win const &);
  bool CheckingEnumerationState(void);
  bool GetCurrentDisplay(short);
  bool GetDisplayArray(void);
  short GetDisplayIndex(short *, ULONG, ULONG);
  bool GetEnumerationStatus(void);
  eDDC_ERROR GetError(void);
  bool GetMonitorData(short);
  short GetNumberOfDisplays(void);
  bool GetVCPFeature(short, short, short *, short *);
  bool PreCalibrate(CGenericCalibrator *, short, double, double, double);
  bool ResetDisplayState(void);
  bool SaveMonitorData(short);
  bool SetColorTemperature(short, double, double);
  bool SetLuminance(short, double);
  bool SetSaturationContrast(short);
  bool SetVCPFeature(short, short, short);
  bool ddc_CleanUp(void);
  bool ddc_Init(void);

  inline bool __GetRGBGains(short i16)
  {
    return this->GetRGBGains(i16);
  }

  inline bool __MeasureAndSettle(dYxy * t_yxy, double dbl)
  {
    return this->MeasureAndSettle(t_yxy, dbl);
  }

  inline FILE* __OpenLogFile(wchar_t * file)
  {
    return OpenLogFile(file);
  }

  inline bool __PreCalibrateCheck(void)
  {
    return this->PreCalibrateCheck();
  }

  inline bool __RGBCalibrationMethod(short i16, double dbl1, double dbl2)
  {
    return this->RGBCalibrationMethod(i16, dbl1, dbl2);
  }

  inline bool __SetRGBGains(short i16)
  {
    return this->SetRGBGains(i16);
  }

  inline void __XYZ2RGB_NOSCALING(dXYZ * xyz, dRGB * rgb)
  {
    return this->XYZ2RGB_NOSCALING(xyz, rgb);
  }

  inline void __dumpEnumerationData(void)
  {
    return this->dumpEnumerationData();
  }


};

