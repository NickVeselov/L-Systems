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

void TreeStructure::init(FTransform seed)
{
	Root = Branch(seed);
	Hinges.Push(Root);
}

void TreeStructure::AddElement(FTransform transform, FString symbol)
{	
	FString id = symbol + FString::FromInt(elementNumber++);

	Branch NewElement;

	NewElement.Value = transform;
	NewElement.Parent = &Hinges.Last();
	NewElement.Id = id;

	Hinges.Last().Children.Add(NewElement);
}

void TreeStructure::NewBranch(FString symbol)
{
	if (Hinges.Last().Children.Num() != 0)
		AddElement(Hinges.Last().Children.Last().Value, symbol);
	else
		AddElement(Hinges.Last().Value, symbol);

	Branch NewHinge = Hinges.Last().Children.Last();
	NewHinge.Fictive = true;
	Hinges.Push(NewHinge);
}

FTransform TreeStructure::GoBack()
{
	if (Hinges.Num() > 1)
	{
		Hinges.Pop();
	}
	return Hinges.Last().Value;
}
