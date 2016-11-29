// Fill out your copyright notice in the Description page of Project Settings.

#include "Branch.h"
#pragma once

/**
 * 
 */
class LSYSTEMS_API TreeStructure
{
	int elementNumber = 0;

	TArray<Branch> Hinges;
	Branch Root;

	TArray<Branch> Branches;
public:
	TreeStructure();
	~TreeStructure();

	void init(FTransform seed);

	void AddElement(FTransform transform, FString symbol);

	void NewBranch(FString symbol);

	FTransform GoBack();
};
