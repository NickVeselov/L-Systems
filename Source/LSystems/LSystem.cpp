// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "LSystem.h"

FString LSystem::perform_substitution(TCHAR current_symb)
{
	if (current_symb == A)
		return ARule;
	else if (current_symb == B && !OneVariable)
		return BRule;
	return FString().AppendChar(current_symb);
}

LSystem::LSystem()
{
}

LSystem::~LSystem()
{
}

void LSystem::init(FString FV, FString SV, FString Initiator, FString FR, FString SR)
{
	A = FV[0];
	if (SV != "")
	{
		B = SV[0];
		OneVariable = false;
	}
	else
		OneVariable = true;

	ARule = FR;
	if (!OneVariable)
		BRule = SR;

	Start = Initiator;
}

FString LSystem::evolve(int generations)
{
	EvolvedLS = Start;

	for (int i = 0; i < generations; i++)
	{
		FString Current = "";
		TArray<TCHAR> Previous = EvolvedLS.GetCharArray();
		for (int j = 0; j < Previous.Num(); j++)
		{
			Current.Append(perform_substitution(Previous[j]));
		}
		EvolvedLS = Current;
	}
	return EvolvedLS;
}

void LSystem::draw()
{

}
