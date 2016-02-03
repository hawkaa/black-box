unit Hawk.Profiling.MemoryMeasurer;

interface

uses
  Generics.Collections;

type
  
  TResult = record
    m_strKey  : string;
    m_iMemory : Int64;
  end;
  
  CMemoryMeasurer = class
  strict private
    m_oMeasuresInProgress   : TDictionary<string, Int64>;
    m_lstMeasures           : TList<TResult>;
    function      GetCurrentMemoryUsage : Int64;
  public
    constructor   Create;
    destructor    Destroy;
    procedure     Before(i_strKey : string);
    procedure     After(i_strKey : string);
    procedure     Print;
  end;

implementation

uses
  SysUtils;

  constructor CMemoryMeasurer.Create;
  begin
    m_oMeasuresInProgress := TDictionary<string, Int64>.Create;
    m_lstMeasures := TList<TResult>.Create;
  end;

  destructor CMemoryMeasurer.Destroy;
  begin
    m_oMeasuresInProgress.Destroy;
    m_lstMeasures.Destroy;
    inherited;
  end;

  procedure CMemoryMeasurer.Before(i_strKey : string);
  begin
    m_oMeasuresInProgress.Add(i_strKey, GetCurrentMemoryUsage);
  end;

  procedure CMemoryMeasurer.After(i_strKey : string);
  var
    l_oRes : TResult;
    l_iPrevious : Int64;
  begin
    if (m_oMeasuresInProgress.TryGetValue(i_strKey, l_iPrevious)) then
    begin
      l_oRes.m_strKey := i_strKey;
      l_oRes.m_iMemory := GetCurrentMemoryUsage - l_iPrevious;
      m_lstMeasures.Add(l_oRes);
    end;
  end;

  procedure CMemoryMeasurer.Print;
  var
    res : TResult;
  begin
    WriteLn('-- MEMORY MEASURER RESULTS --');
    for res in m_lstMeasures do
    begin
      WriteLn(format('%s%s%d bytes', [res.m_strKey, #9, res.m_iMemory]));
    end;

  end;

  // from http://stackoverflow.com/questions/437683/how-to-get-the-memory-used-by-a-delphi-program 
  function CMemoryMeasurer.GetCurrentMemoryUsage : Int64;
  var
    l_state: TMemoryManagerState;
    l_blockTypeState: TSmallBlockTypeState;
  begin
    GetMemoryManagerState(l_state); 
    result := l_state.TotalAllocatedMediumBlockSize + l_state.TotalAllocatedLargeBlockSize;
    for l_blockTypeState in l_state.SmallBlockTypeStates do
    begin
      result := result + l_blockTypeState.UseableBlockSize * l_blockTypeState.AllocatedBlockCount;
    end;
  end;


end.
