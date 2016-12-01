// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "Branch.h"

Branch::Branch()
{
}

Branch::Branch(FVector direction, FVector origin, float scale)
{
	Direction = direction;
	BranchParts.Add(origin);
	StartScale = scale;
	EndScale = scale - 0.1f;
}

Branch::~Branch()
{

}