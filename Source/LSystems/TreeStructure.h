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


	TArray<Branch> Unfinished_Branches;
	TArray<Branch> Complete_Branches;

	float currentScale;
	float scaleStep;
	float initialScale;

public:
	TreeStructure();
	~TreeStructure();

	void init(FVector ActorLocation, FVector ModelDirection, float StartScale, float ScaleStep);

	void AddElement(FVector coordinates);

	void NewBranch(FVector direction, FVector BranchOrigin);

	FVector GetLastPosition();

	FVector GetLastDirection();

	Branch GetBranch(int i);

	int GetNumberOfBranches();

	void CloseBranch();
	void Clear();

	float GetBranchStartScale(int i);

	float GetBranchEndScale(int i);
};
