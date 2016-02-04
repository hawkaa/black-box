program GenusStorage;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  FastMM4,
  System.SysUtils,
  Hawk.Profiling.Timer,
  Hawk.Profiling.MemoryMeasurer,
  Hawk.Column.IntegerColumn,
  Generics.Collections,
  SystemTypes;

var
  l_oTimer : CTimer;
  l_oMemoryMeasurer : CMemoryMeasurer;

  l_lstIntegers: TList<integer>;
  l_lstCGValues: TList<CGValue>;
  l_i: integer;

  l_currentValue : CGValue;
  l_oColumn : CIntegerColumn;
  l_oFile : TextFile;
  l_strLine : string;
  l_iSum : integer;
begin

  // init timer and memory measurer
  l_oTimer := CTimer.Create;
  l_oMemoryMeasurer := CMemoryMeasurer.Create;
  
  // read file contents into list
  AssignFile(l_oFile, 'numbers.txt');
  Reset(l_oFile);
  l_oMemoryMeasurer.Before('ORDINARY INTEGER LIST');
  l_lstIntegers := TList<integer>.Create;
  l_oTimer.Start('READ FILE');
  while not Eof(l_oFile) do
  begin
    ReadLn(l_oFile, l_strLine);
    l_lstIntegers.Add(StrToInt(l_strLine));
  end;
  l_oTimer.Stop('READ FILE');
  l_oMemoryMeasurer.After('ORDINARY INTEGER LIST');


  // Fill CG VALUE LIST
  l_oMemoryMeasurer.Before('CGVALUE LIST');
  l_lstCGValues := TList<CGValue>.Create;
  l_oTimer.Start('FILL CGVALUE LIST');
  for l_i in l_lstIntegers do
  begin
    l_currentValue := CGValue.CreateInteger(l_i);
    l_lstCGValues.Add(l_currentValue);
  end;
  l_oTimer.Stop('FILL CGVALUE LIST');
  l_oMemoryMeasurer.After('CGVALUE LIST');

  // Fill column
  l_oMemoryMeasurer.Before('INTEGER COLUMN');
  l_oColumn := CIntegerColumn.Create(10);
  l_oTimer.Start('FILL INTEGER COLUMN');
  for l_i in l_lstIntegers do
  begin
    l_currentValue := CGValue.CreateInteger(l_i);
    l_oColumn.Add(l_currentValue);
    l_currentValue.Destroy;
  end;
  l_oTimer.Stop('FILL INTEGER COLUMN');
  l_oMemoryMeasurer.After('INTEGER COLUMN');

  // calculate sum from cgvalue list
  l_oTimer.Start('SUM CGVALUE LIST');
  l_iSum := 0;
  for l_currentValue in l_lstCGValues do
  begin
    l_iSum := l_iSum + l_currentValue.AsInteger;
  end;
  l_oTimer.Stop('SUM CGVALUE LIST');
  WriteLn(l_iSum);

  // calculate sum in column
  l_oTimer.Start('SUM COLUMN NAIVE');
  l_iSum := 0;
  for l_i := 0 to l_oColumn.Count - 1 do
  begin
    l_currentValue := l_oColumn.Get(l_i);
    l_iSum := l_iSum + l_currentValue.AsInteger;
    l_currentValue.Destroy;
  end;
  l_oTimer.Stop('SUM COLUMN NAIVE');
  WriteLn(l_iSum);

  l_oTimer.Start('SUM COLUMN SMART');
  l_iSum := l_oColumn.Sum.AsInteger;
  l_oTimer.Stop('SUM COLUMN SMART');
  WriteLn(l_iSum);

  // print results
  l_oTimer.Print;
  l_oMemoryMeasurer.Print;

  // cleanup
  l_oColumn.Destroy;
  l_oTimer.Destroy;
  l_oMemoryMeasurer.Destroy;
  l_lstCGValues.Destroy;
  l_lstIntegers.Destroy;
  ReadLn;
end.
