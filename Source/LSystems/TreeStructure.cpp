// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "TreeStructure.h"
#include "TreeStructureElement.h"

TreeStructure::TreeStructure()
{
}

TreeStructure::~TreeStructure()
{
}

void TreeStructure::init(FTransform seed)
{
	root = new TreeStructureElement(seed, 0, 0);
	current = root;
}

void TreeStructure::AddElement(FTransform transform)
{
	current->Children.Add(TreeStructureElement(transform, current));
	current = &current->Children.Last();
}
