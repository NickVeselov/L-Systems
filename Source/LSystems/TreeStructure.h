// Fill out your copyright notice in the Description page of Project Settings.

#include "TreeStructureElement.h"
#pragma once

/**
 * 
 */
class LSYSTEMS_API TreeStructure
{
	TreeStructureElement *root;
	TreeStructureElement *current;

public:
	TreeStructure();
	~TreeStructure();

	void init(FTransform seed);

	void AddElement(FTransform transform);
};
