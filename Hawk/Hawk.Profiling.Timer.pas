unit Hawk.Profiling.Timer;

interface

uses
  Generics.Collections;

type

  TResult = record
    m_strKey    : string;
    m_iTime     : integer;
  end;

  CTimer = class
  strict private
    m_oTimings    : TDictionary<string, TDateTime>;
    m_lstResults  : TList<TResult>;
  public
    constructor   Create;
    destructor    Destroy;
    procedure     Start   (i_strKey : string);
    procedure     Stop    (i_strKey : string);
    procedure     Print;
  end;

implementation

uses
  SysUtils, DateUtils;

  constructor CTimer.Create;
  begin
    Self.m_oTimings := TDictionary<string, TDateTime>.Create;
    Self.m_lstResults := TList<TResult>.Create;
  end;

  destructor CTimer.Destroy;
  begin
    m_oTimings.Destroy;
    m_lstResults.Destroy;
    inherited;
  end;

  procedure CTimer.Start(i_strKey: string);
  begin
    m_oTimings.Add(i_strKey, Now);
  end;

  procedure CTimer.Stop(i_strKey: string);
  var
    l_oRes : TResult;
    l_dStart : TDateTime;
  begin
    if (m_oTimings.TryGetValue(i_strKey, l_dStart)) then
    begin
      l_oRes.m_strKey := i_strKey;
      l_oRes.m_iTime := DateUtils.MilliSecondsBetween(Now, l_dStart);
      m_lstResults.Add(l_oRes);
    end;
  end;

  procedure CTimer.Print;
  var
    res : TResult;
  begin
    WriteLn('-- TIMER RESULTS --');
    for res in m_lstResults do
    begin
      WriteLn(format('%s%s%d', [res.m_strKey, #9, res.m_iTime]));
    end;

  end;

end.
