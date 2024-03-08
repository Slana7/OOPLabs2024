#include <iostream>
#include "Students.h"
#include "Global.h"

using namespace std;

int main()
{
	Students student, restantier;
	char nume1[256], nume2[256];

	strcpy(nume1, "Stefan");
	strcpy(nume2, "Paul");

	student.SetName(nume1);
	student.SetNotaMate(7.2f);
	student.SetNotaEng(8.0f);
	student.SetNotaIst(10.0f);

	restantier.SetName(nume2);
	restantier.SetNotaMate(7.0f);
	restantier.SetNotaEng(9.3f);
	restantier.SetNotaIst(5.4f);

	cout << "Student: " << student.GetName() << "\n";
	cout << "Nota Mate: " << student.GetNotaMate() << "\n";
	cout << "Nota Engleza: " << student.GetNotaEng() << "\n";
	cout << "Nota Istorie: " << student.GetNotaIst() << "\n";
	cout << "Media notelor: " << student.Media() << "\n";

	cout << "Student: " << restantier.GetName() << "\n";
	cout << "Nota Mate: " << restantier.GetNotaMate() << "\n";
	cout << "Nota Engleza: " << restantier.GetNotaEng() << "\n";
	cout << "Nota Istorie: " << restantier.GetNotaIst() << "\n";
	cout << "Media notelor: " << restantier.Media() << "\n";

	cout << "Comparatie dupa nume: " << CompNume(&student, &restantier) << "\n";
	cout << "Comparatie dupa mate: " << CompNotaMate(&student, &restantier) << "\n";
	cout << "Comparatie dupa engleza: " << CompNotaEng(&student, &restantier) << "\n";
	cout << "Comparatie dupa istorie: " << CompNotaIst(&student, &restantier) << "\n";
	cout << "Comparatie dupa medie: " << CompMedie(&student, &restantier) << "\n";
	system("pause");
	return 0;
}