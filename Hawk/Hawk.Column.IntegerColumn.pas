unit Hawk.Column.IntegerColumn;

interface

uses
  Hawk.Column.Column,
  Generics.Collections,
  SystemTypes;
type
  
  CIntegerColumn = class(CColumn)
  private
    m_lstValues : TList<integer>;
  public
    constructor   Create(distinctValues : integer); override;
    destructor    Destroy; override;
    procedure     Add(value : CGValue); override;
    function      Get(index : integer) : CGValue; override;
    function      Count : integer; override;
    function      Sum : CGValue; override;
  end;

implementation

  constructor CIntegerColumn.Create(distinctValues : integer);
  begin
    m_lstValues := TList<integer>.Create;
  end;

  destructor CIntegerColumn.Destroy;
  begin
    m_lstValues.Destroy;
    inherited;
  end;

  procedure CIntegerColumn.Add(value : CGValue);
  begin
    m_lstValues.Add(value.AsInteger);
  end;

  function CIntegerColumn.Get(index : integer) : CGValue;
  begin
    Result := CGValue.CreateInteger(m_lstValues[index]);
  end;

  function CIntegerColumn.Count : integer;
  begin
    Result := m_lstValues.Count;
  end;

  function CIntegerColumn.Sum : CGValue;
  var
    l_i, l_iSum: integer;
  begin
    l_iSum := 0;
    for l_i in m_lstValues do
    begin
      l_iSum := l_iSum + l_i;
    end;
    Result := CGValue.CreateInteger(l_iSum);
  end;

end.
