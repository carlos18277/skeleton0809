object GLForm2D: TGLForm2D
  Left = 296
  Top = 146
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Rebotes '
  ClientHeight = 500
  ClientWidth = 500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MMenu
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MMenu: TMainMenu
    Left = 440
    object MInicio: TMenuItem
      Caption = '&Inicio'
      OnClick = MInicioClick
    end
    object MSalir: TMenuItem
      Caption = '&Salir'
      OnClick = MSalirClick
    end
  end
  object reloj: TTimer
    Interval = 30
    OnTimer = relojTimer
    Left = 472
  end
end
