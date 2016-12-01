// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "TreeStructure.h"
#include "Branch.h"

TreeStructure::TreeStructure()
{
}

TreeStructure::~TreeStructure()
{
}

void TreeStructure::init(FVector ActorLocation, FVector ModelDirection, float StartScale, float ScaleStep)
{
	Unfinished_Branches.Add(Branch(ModelDirection, ActorLocation,currentScale));
	currentScale = StartScale;
	initialScale = StartScale;
	scaleStep = ScaleStep;
}

//"A" or "B" symbol
void TreeStructure::AddElement(FVector coordinates)
{	
	Unfinished_Branches.Last().BranchParts.Add(coordinates);
}

//"[" symbol
void TreeStructure::NewBranch(FVector BranchDirection, FVector BranchOrigin)
{
	Unfinished_Branches.Add(Branch(BranchDirection, BranchOrigin,currentScale));
	currentScale -= scaleStep;
}

FVector TreeStructure::GetLastPosition()
{
	Branch CurrentBranch = Unfinished_Branches.Last();
	
	int branch_id = Unfinished_Branches.Num() - 1;

	for (int i = Unfinished_Branches.Num() - 1; i >= 0; i--)
	{
		if (Unfinished_Branches[i].BranchParts.Num() != 0)
			return Unfinished_Branches[i].BranchParts.Last();
	}

	return (FVector(0, 0, 0));
}

FVector TreeStructure::GetLastDirection()
{
	CloseBranch();

	return Unfinished_Branches.Last().Direction;
}

Branch TreeStructure::GetBranch(int i)
{
	return Complete_Branches[i];
}

int TreeStructure::GetNumberOfBranches()
{
	return Complete_Branches.Num();
}

void TreeStructure::CloseBranch()
{
	Branch Popped = Unfinished_Branches.Pop();
	Complete_Branches.Add(Popped);
	currentScale += scaleStep;
}

void TreeStructure::Clear()
{
	Complete_Branches.Empty();
	currentScale = initialScale;
}

float TreeStructure::GetBranchEndScale(int i)
{
	return Complete_Branches[i].EndScale;
}

float TreeStructure::GetBranchStartScale(int i)
{
	return Complete_Branches[i].StartScale;
}
