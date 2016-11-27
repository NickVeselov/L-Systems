// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "TreeStructureElement.h"

TreeStructureElement::TreeStructureElement()
{
}

TreeStructureElement::TreeStructureElement(TreeStructureElement parent, FTransform value, int directionId, int elementId)
{
	TreeStructureElement(value, directionId, elementId);
	Parent = &parent;
}

TreeStructureElement::TreeStructureElement(FTransform value, int directionId, int elementId)
{
	Parent = NULL;
	Value = value;
	DirectionId = directionId;
	ElementId = elementId;
}

TreeStructureElement::TreeStructureElement(FTransform value, TreeStructureElement *parent)
{
	Value = value;
	Parent = parent;
}

TreeStructureElement::~TreeStructureElement()
{
}