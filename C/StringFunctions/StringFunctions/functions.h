#pragma once
int _length_string(char* _transmitted_string); // �������� ������� ����������� ������ ������
int _length_string(const char* _transmitted_string); // �������� ������� ����������� ������ ����������� ������
bool _string_matching(char* _current_string, char* _transmitted_string); // �������� ������� �������� ���������� �����
char* _reverse_string(char* _transmitted_string); // �������� ������� ��� ���������� (��������) ������
bool _balance_brackets(char* _transmitted_string); // �������� ������� �������� ������� ������ ������
int _occurence_substring(char* _current_string, char* _transmitted_string); // �������� ������� ������ ������� ��������� ��������� � ������, ������� ������ ���������� ������� ������� ��������� ���������
char* _insert_n_string(char* _current_string, char* _transmitted_string, int position); // �������� ������� ������� ������ �� ������ ������ � ��������� �������
char* _�ut_string (char* _transmitted_string, int length, int position); // �������� ������� ���������� k �������� ������� ������, ������� � ������� N