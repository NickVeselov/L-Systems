// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class LSYSTEMS_API TreeStructureElement
{

public:
	//Transform property
	FTransform Value;
	//Branch direction ID
	int DirectionId;
	//The distance between this element and parent branch
	int ElementId;
	//Parent
	TreeStructureElement *Parent;
	TArray<TreeStructureElement> Children;

	TreeStructureElement();

	TreeStructureElement(TreeStructureElement parent, FTransform value, int directionId, int elementId);

	TreeStructureElement(FTransform value, int directionId, int elementId);

	TreeStructureElement(FTransform value, TreeStructureElement parent);

	~TreeStructureElement();
};
