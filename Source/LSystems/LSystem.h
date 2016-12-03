// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class LSYSTEMS_API LSystem
{
	TCHAR A;
	TCHAR B;
	FString Start;
	FString ARule;
	FString BRule;
	float angle;
	float length;
	FString EvolvedLS;

	FString perform_substitution(TCHAR);

public:
	LSystem();
	~LSystem();

	//set variables
	void init(FString FV, FString SV, FString Initiator, FString FR, FString SR);

	//evolve l_system
	FString evolve(int generations);

	//draw l-system
	void draw();
};
