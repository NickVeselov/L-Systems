// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class LSYSTEMS_API Branch
{

public:
	//Transform property
	FTransform Value;

	//Parent
	Branch *Parent;
	TArray<FTransform> Elements;
	FString Id;
	bool Fictive;



	Branch();

	Branch(FTransform value);

	Branch(FTransform value, Branch parent, FString ID);

	~Branch();
};
