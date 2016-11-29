// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "Branch.h"

Branch::Branch()
{
	this->Children.SetNumUninitialized(0);
}

Branch::Branch(FTransform value)
{
	this->Value = value;
	this->Parent = NULL;
	this->Children.SetNumUninitialized(0);
	this->Id = "Seed";
}

Branch::Branch(FTransform value, Branch parent, FString ID)
{
	this->Value = value;
	this->Children.SetNumUninitialized(0);
	this->Parent = &parent;
	this->Id = ID;
}

Branch::~Branch()
{
}