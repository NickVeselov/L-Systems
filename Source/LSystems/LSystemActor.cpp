// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "LSystemActor.h"
#include "LSystem.h"

void ALSystemActor::OnConstruction(const FTransform & Transform)
{
	Init();
}

// Sets default values
ALSystemActor::ALSystemActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALSystemActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALSystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Create tree 
void ALSystemActor::CreateTreeStructure()
{
	TArray<TCHAR> LS = EvolvedLSystem.GetCharArray();

	Tree.init(TurtlePosition, TurtleDirection,InitialScale,ScaleStep);
	for (int i = 0; i < LS.Num(); i++)
	{
		PerformTransformation(LS[i]);
	}
	Tree.CloseBranch();
}

void ALSystemActor::PerformTransformation(TCHAR symbol)
{
	if (symbol == FirstVariable[0] && FirstVariableRespondsForDrawing)
	{
		TurtlePosition += TurtleDirection*Length;
		Tree.AddElement(TurtlePosition);
	}
	if (SecondVariable != "")
	{
		if (symbol == SecondVariable[0] && SecondVariableRespondsForDrawing)
		{
			TurtlePosition += TurtleDirection*Length;
			Tree.AddElement(TurtlePosition);
		}
	}

	if (symbol == NewBranchSymbol[0])
	{
		Tree.NewBranch(TurtleDirection,TurtlePosition);
	}
	if (symbol == EndBranchSymbol[0])
	{
		TurtleDirection = Tree.GetLastDirection();
		TurtlePosition = Tree.GetLastPosition();
	}
	if (symbol == CWRotationSymbol[0])
	{
		TurtleDirection = TurtleDirection.RotateAngleAxis(Angle, FVector(0, 1, 0));
	}
	if (symbol == CCWRotationSymbol[0])
	{
		TurtleDirection = TurtleDirection.RotateAngleAxis(-Angle, FVector(0, 1, 0));
	}
}


void ALSystemActor::Clear()
{
	TurtlePosition = FVector(1, 1, 1);
	TurtleDirection = FVector(0, 0, 1);
	Tree.Clear();
}

int ALSystemActor::GetNumberOfBranches()
{
	return Tree.GetNumberOfBranches();
}

TArray<FVector> ALSystemActor::GetBranchCoordinates(int i)
{
	return Tree.GetBranch(i).BranchParts;
}

float ALSystemActor::GetStartScale(int i)
{
	return Tree.GetBranchStartScale(i);
}

float ALSystemActor::GetEndScale(int i)
{
	return Tree.GetBranchEndScale(i);
}

FVector ALSystemActor::GetBranchDirection(int i)
{
	return Tree.GetBranch(i).Direction;
}

void ALSystemActor::Init()
{
	LSystem LS;
	LS.init(FirstVariable, SecondVariable, Start, First_Rule, Second_Rule);
	if (Generations > 0)
	{
		Clear();
		EvolvedLSystem = LS.evolve(Generations);

		CreateTreeStructure();
	}
}

