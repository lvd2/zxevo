
��室���� ����� ��� http://john.ccac.rwth-aachen.de:8000/ftp/as/source/c_version/asl-current.tar.gz

���������:
- ��। ᡮમ� ��� Win32 ��������� 䠩� Makefile.def � ����� ��室�����.
- ��। ᡮમ� � ����� ��室����� ��������� make.exe
- 䠩� codez80.c � �㭪樨 CodeEnd() ��ப� "else Type = UInt16;" �������� �� "else Type = UInt32;"
  ��� ���������� ᮡ���� ����୨�� � ࠧ��஬ ����� 64�.
- 䠩� datatypes.h 㢥��祭 STRINGSIZE �� 1024 ���� (����� ��ப� ��室���� ⥪��).

��� ᤥ���� � makefile �� ࠧ��ࠫ��, ��⮬� ᤥ��� �१ ��⭨�.
�ᯮ�짮����� gcc 8.1.0 � make 3.81 (����� ����� make ����� ᮡ���� �⪠�뢠���� ��-�� �訡��).
