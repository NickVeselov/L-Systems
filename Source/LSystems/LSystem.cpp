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

void LSystem::init(FString A, FString B, FString Start, FString FirstRule, FString SecondRule, float Angle, float Length)
{
	if (!A.IsEmpty() && !B.IsEmpty())
	{
		this->A = A[0];	this->B = B[0];
	}
	this->Start = Start;
	this->ARule = FirstRule;	this->BRule = SecondRule;
	this->length = Length;		this->angle = Angle;
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
