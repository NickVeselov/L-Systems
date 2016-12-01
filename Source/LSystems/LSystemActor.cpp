// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "LSystemActor.h"
#include "LSystem.h"

void ALSystemActor::OnConstruction(const FTransform & Transform)
{
	LSystem LS;
	LS.init(FirstVariable, SecondVariable, Start, First_Rule, Second_Rule, Angle, Length);
	if (Generations > 0)
	{
		Clear();
		EvolvedLSystem = LS.evolve(Generations);

		CreateTreeStructure();
	}
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
	TCHAR FV = FirstVariable[0],
		SV = SecondVariable[0];
	if ((symbol == FV && FirstVariableRespondsForDrawing) || (symbol == SV && SecondVariableRespondsForDrawing))
	{
		TurtlePosition += TurtleDirection*Length;
		Tree.AddElement(TurtlePosition);
	}
	else if (symbol == '[')
	{
		Tree.NewBranch(TurtleDirection,TurtlePosition);
	}
	else if (symbol == ']')
	{
		TurtleDirection = Tree.GetLastDirection();
		TurtlePosition = Tree.GetLastPosition();
	}
	else if (symbol == '+')
	{
		TurtleDirection = TurtleDirection.RotateAngleAxis(Angle, FVector(0, 1, 0));
	}
	else if (symbol == '-')
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

