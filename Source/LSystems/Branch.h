// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class LSYSTEMS_API Branch
{

public:
	//Transform property
	TArray<FVector> BranchParts;
	FVector Direction;
	float StartScale;
	float EndScale;

	Branch();

	Branch(FVector direction, FVector origin, float scale);

	~Branch();
};
