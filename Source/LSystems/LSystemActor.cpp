// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "LSystemActor.h"
#include "LSystem.h"

void ALSystemActor::OnConstruction(const FTransform & Transform)
{
	LSystem LS;
	LS.init(FirstVariable, SecondVariable, Start, First_Rule, Second_Rule, Angle, Length);
	EvolvedLSystem = LS.evolve(Generations);

	LS.draw();

	//Tree->init(FTransform(this->GetTransform()));
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

UStaticMeshComponent *ALSystemActor::PerformTransformation(FString symbol, UStaticMeshComponent *Turtle)
{
	if ((symbol == FirstVariable && FirstVariableRespondsForDrawing) || (symbol == SecondVariable && SecondVariableRespondsForDrawing))
	{
		//K2_AddActorLocalRotation()
		//K2_AddActorWorldRotation(Turtle->RelativeRotation, false, FHitResult(), false);
		//FRotator R = ;
		//R.get
		this->SetActorRelativeRotation(FQuat(Turtle->RelativeRotation));
		FVector OldLocation = Turtle->GetForwardVector();// .ro
														 //OldLocation.RotateAngleAxis();
		FVector NewLocation = OldLocation*Length;
		Turtle->AddRelativeLocation(NewLocation);
		//this->GetWorld()->Setwo

		//Tree->AddElement(Turtle->GetRelativeTransform());
	}
	else if (symbol == "[")
	{
		Turtle->AddRelativeRotation(FQuat(0, 0, Angle, 0));
	}
	else if (symbol == "]")
	{
		Turtle->AddRelativeRotation(FQuat(0, 0, -Angle, 0));
	}
	else if (symbol == "+")
	{
		Turtle->AddRelativeRotation(FQuat(0, 0, Angle, 0));
	}
	else if (symbol == "-")
	{
		Turtle->AddRelativeRotation(FQuat(0, 0, -Angle, 0));
	}

	return Turtle;
}

