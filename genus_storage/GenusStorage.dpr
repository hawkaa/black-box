program GenusStorage;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  FastMM4,
  System.SysUtils,
  Hawk.Profiling.Timer,
  Hawk.Profiling.MemoryMeasurer,
  SystemTypes;

var
  l_oTimer : CTimer;
  l_oMemoryMeasurer : CMemoryMeasurer;
begin
  // init timer and memory measurer
  l_oTimer := CTimer.Create;
  l_oMemoryMeasurer := CMemoryMeasurer.Create;



  l_oMemoryMeasurer.Before('Program');
  l_oTimer.Start('Program');
  WriteLn('My program starts now.');
  l_oTimer.Stop('Program');
  l_oMemoryMeasurer.After('Program');
  l_oTimer.Print;
  l_oMemoryMeasurer.Print;

  // cleanup
  l_oTimer.Destroy;
  l_oMemoryMeasurer.Destroy;
  ReadLn;
end.
