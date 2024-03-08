#pragma once
class Students
{
	char nume[256];
	float notamate;
	float notaeng;
	float notaist;
public:
	void SetName(char* nume);
	char *GetName();
	void SetNotaMate(float nota);
	float GetNotaMate();
	void SetNotaEng(float nota);
	float GetNotaEng();
	void SetNotaIst(float nota);
	float GetNotaIst();
	float Media();
};