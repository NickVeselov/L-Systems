// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "LSystem.h"

FString LSystem::perform_substitution(TCHAR current_symb)
{
	if (current_symb == A)
		return ARule;
	else if (current_symb == B)
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
	//if (!FV.IsEmpty() && !SV.IsEmpty() && !FR.IsEmpty() && !SR.IsEmpty() && Initiator.IsEmpty())
	{
		A = FV[0];	
		B = SV[0];

		ARule = FR;
		BRule = SR;

		Start = Initiator;
	}
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
