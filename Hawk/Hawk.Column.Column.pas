unit Hawk.Column.Column;

interface

uses
  SysUtils,
  SystemTypes;

type
  
  CColumn = class abstract(TObject)
  public
    constructor   Create(distinctValues : integer); virtual; abstract;
    procedure     Add(value : CGValue); virtual; abstract;
    function      Get(index : integer) : CGValue; virtual; abstract;
    function      Count : integer; virtual; abstract;
    function      Sum : CGValue; virtual;
  end;

implementation
  
  function CColumn.Sum;
  begin
    Result := CGValue.CreateInteger(0);; // No effect, but removes a compiler hint
    raise Exception.Create('Not implemented');
  end;
end.
