#include "stdafx.h"


int main()
{
  short i16;
  Cncs_ddc_win *winddc = new Cncs_ddc_win();
  Cncs_ddc_win ddc2;

  winddc->ddc_Init();
  winddc->__OpenLogFile(NULL);
  winddc->GetDisplayIndex(&i16, 0, 0);

  ddc2 = *winddc;

  return 0;
}

